import time
import paho.mqtt.client as mqtt
from zeroconf import ServiceBrowser, Zeroconf, ServiceStateChange
import subprocess
import netifaces

class MqttClientManager:
    def __init__(self, topic="phone-rasp", port=1883, service_type="_mqtt._tcp.local.", client_id="User", protocol="MQTTv5"):
            self.client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, client_id="Raspberry")
            self.zeroconf = Zeroconf()
            self.broker_process = None
            self.topic = topic
            self.port = port
            self.service_type = service_type
            self.message_callback = None
            self.setup_callbacks()

    def setup_callbacks(self):
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.on_disconnect = self.on_disconnect

    def on_connect(self, client, userdata, flags, rc, properties):
        if rc == mqtt.MQTT_ERR_SUCCESS:
            print("Connected with Success")
        else:
            print(f"Connected with result code {rc}")
        client.subscribe(self.topic)
        print(self.topic, f": {client._client_id.decode()} has joined the network.")
        
    def on_message(self, client, userdata, message):
        data = message.payload.decode().split(",")
        x = int(data[0].strip()) 
        y = int(data[1].strip()) 
        if self.message_callback:
            self.message_callback(x, y)
        
    def set_message_callback(self, callback):
        if callable(callback):
            self.message_callback = callback
        else:
            print("Error: Provided callback is not callable")

    def on_disconnect(self, client, userdata, flags, rc, properties):
        print(f"Client {client._client_id.decode()} disconnected from the broker!")
        if rc != 0:
            print("Unexpected disconnection. Sending disconnection message...")

    def on_service_state_change(self, zeroconf, service_type, name, state_change):
        print(f"State Change: {state_change}, Service: {name}")
        if state_change is ServiceStateChange.Added:
            info = zeroconf.get_service_info(service_type, name)
            if info:
                broker_ip = ".".join(map(str, info.addresses[0]))
                print(f"Found broker: {broker_ip}")
                self.connect_to_broker(broker_ip)

    def connect_to_broker(self, broker_ip):
        print(f"Attempting to connect to MQTT broker at {broker_ip}:{self.port}")
        try:
            time.sleep(0.1)
            self.client.connect(broker_ip, self.port, 1)
            print(f"Connect_to_broker: {broker_ip}")
            self.client.loop_start()
        except Exception as e:
            print(f"Reconnection.. Failed to connect to MQTT broker at {broker_ip}:{self.port}. Error: {e}")
            time.sleep(1) 
            self.connect_to_broker(broker_ip) 

    def start_local_broker(self):
        print("Starting local MQTT broker...")
        self.broker_process = subprocess.Popen(
            ["sudo", "mosquitto", "-c", "/etc/mosquitto/mosquitto.conf", "-v"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
    )

    def start_discovery(self):
        print("Searching for MQTT broker...")
        ServiceBrowser(self.zeroconf, self.service_type, handlers=[self.on_service_state_change])

    def cleanup(self):
        self.zeroconf.close()
        if self.client.is_connected():
            self.client.loop_stop()
        if self.broker_process:
            self.broker_process.terminate()
        print("Disconnect successful.")
        
    def get_ip(self, interface="wlan0"): 
        try:
            ip = netifaces.ifaddresses(interface)[netifaces.AF_INET][0]['addr']
            print(f"IP Address of wlan0: {ip}")
            return ip
        except (ValueError, KeyError, IndexError) as e:
            print(f"Error getting IP for interface {interface}: {e}")
            return None
    


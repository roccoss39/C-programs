import paho.mqtt.client as mqtt
import time

class MqttClient:
    def __init__(self, client_id, protocol, broker_address, port, timeout):
        self.client = mqtt.Client(client_id=client_id, protocol=protocol)
        self.broker_address = broker_address
        self.port = port
        self.timeout = timeout
        self.message_callback = None 
        self.setup_callbacks()
    
    def setup_callbacks(self):
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.on_disconnect = self.on_disconnect  
    def set_message_callback(self, callback):
        self.message_callback = callback  

    def on_connect(self, client, userdata, flags, reason_code, properties=None):
        if reason_code == mqtt.MQTT_ERR_SUCCESS:
            print("Connected with result code Success")
            client.subscribe("phone")
        else:
            print(f"Connected with result code {reason_code}")

    def on_message(self, client, userdata, message):
        data = message.payload.decode().split(",")
        x = int(data[0].strip()) 
        y = int(data[1].strip()) 
        if self.message_callback:
            self.message_callback(x, y) 

    def on_disconnect(self, client, userdata, rc, properties=None):
        if rc != mqtt.MQTT_ERR_SUCCESS:
         print("Unexpected disconnection.")
        else:
         print("Disconnected successfully.")


    def connect_to_broker(self):
        while True:
            try:
                self.client.connect(self.broker_address, self.port, self.timeout)
                self.client.loop_start()
                break
            except Exception as e:
                print(f"Connection failed: {e}. Retrying in 10 seconds...")
                time.sleep(10)

    def run(self):
        try:
            while True:
                time.sleep(10)
        except KeyboardInterrupt:
            print("Exiting...")
            self.client.disconnect()
            self.client.loop_stop()

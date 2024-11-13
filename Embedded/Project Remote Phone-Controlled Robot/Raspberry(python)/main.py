import time
import threading
import mqtt_client_with_server as mqtt
import robot_handle as rbt
import streaming

ZEROCONF = 0       # Set to 1 if you want use antoher server 
PROTOCOL = "RTSP"  # Set to "RTMP" if you want to use RTMP streaming

def main():
    streaming_thread = threading.Thread(target=streaming.check_server_and_stream, args=(PROTOCOL,))
    streaming_thread.daemon = True
    streaming_thread.start()

    robot = rbt.Robot(
        l_dir_pin=rbt.L_DIR,
        r_dir_pin=rbt.R_DIR,
        l_pwm_pin=rbt.L_PWM,
        r_pwm_pin=rbt.R_PWM
    )

    mqtt_client = mqtt.MqttClientManager(
        topic="phone-rasp",
        port=1883,
        service_type="_mqtt._tcp.local.",
        client_id="my_unique_client_id"
    )

    mqtt_client.set_message_callback(robot.set_duty)
    mqtt_client.start_local_broker()

    if ZEROCONF == 1:
        mqtt_client.start_discovery()
    else:
        broker_ip = mqtt_client.get_ip("wlan0")
        if broker_ip:
            mqtt_client.connect_to_broker(broker_ip)
        else:
            print("Cannot obtain local IP address")

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("Stopping...")
    finally:
        mqtt_client.cleanup()
        robot.stop()

if __name__ == "__main__":
    main()

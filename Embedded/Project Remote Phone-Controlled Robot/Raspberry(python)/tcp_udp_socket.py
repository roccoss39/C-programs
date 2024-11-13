#ADD IF NEED UDP/TCP CONNECTION INSTED OF ZEROCONFIG

import netifaces
import socket
import time
import threading

UDP_PORT = 12345
TCP_PORT = 1234
received_flag = threading.Event() 

def get_network_info():
    interfaces = netifaces.interfaces()
    for interface in interfaces:
        if "wlan" in interface or "wlp" in interface:
            addresses = netifaces.ifaddresses(interface)
            if netifaces.AF_INET in addresses:
                ip_info = addresses[netifaces.AF_INET][0]
                ip_address = ip_info['addr']
                broadcast = addresses[netifaces.AF_INET][0].get('broadcast')
                print(f"Using IP: {ip_address}, Broadcast: {broadcast}")
                return ip_address, broadcast
    return None, None

def listen_for_response(TCP_PORT):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind(("", TCP_PORT))
        sock.listen(1)
        print(f"Listening for TCP response on port {TCP_PORT}...")

        while not received_flag.is_set():
            try:
                sock.settimeout(1)
                conn, addr = sock.accept()
                with conn:
                    data = conn.recv(1024)
                    message = data.decode('utf-8').strip()
                    print(f"Received TCP message from {addr}: {message}")
                    if message == "received_ip":
                        received_flag.set()
                        print("Stopping broadcast due to received message.")
            except socket.timeout:
                continue

def send_broadcast_udp(port, host, broadcast):
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        while not received_flag.is_set():
            sock.sendto(host.encode('utf-8'), (broadcast, port))
            print(f"Sent broadcast message to {broadcast}:{port}")
            time.sleep(1)

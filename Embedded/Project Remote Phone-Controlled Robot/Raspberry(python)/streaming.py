import subprocess
import time

def start_streaming_rtsp():
    command = "libcamera-vid -t 0 -n -b 3000000 --width 1280 --height 960 --framerate 80 --libav-format mpegts -o - | ffmpeg -fflags nobuffer -flags low_delay -i - -an -c:v copy -f rtsp rtsp://localhost:8554/mystream"
    subprocess.Popen(command, shell=True)

def start_streaming_rtmp():
    command = "libcamera-vid -t 0 -n -b 3000000 --width 320 --height 240 --framerate 30 --libav-format mpegts -o - | ffmpeg -fflags nobuffer -flags low_delay -i - -c:v copy -f flv rtmp://localhost:1935/live"
    subprocess.Popen(command, shell=True)

def start_streaming(protocol):
    if protocol == "RTSP":
        print("Starting RTSP streaming...")
        start_streaming_rtsp()
    elif protocol == "RTMP":
        print("Starting RTMP streaming...")
        start_streaming_rtmp()
    else:
        print("Unknown protocol. Please use 'RTSP' or 'RTMP'.")

def check_server_and_stream(protocol):
    server_started = False
    while not server_started:
        try:
            subprocess.run(["pgrep", "-x", "mediamtx"], check=True)
            print("mediamtx server is running. Starting streaming...")
            start_streaming(protocol)
            server_started = True
        except subprocess.CalledProcessError:
            print("mediamtx server is not running yet. Retrying in 1 second...")
        time.sleep(1)

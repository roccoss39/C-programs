#Project: Remote Phone-Controlled Robot

#Requirements
- Raspberry Pi Zero 2W (or newer model)
- Android phone with minimum SDK 24
- Shield or motor controller to manage engine operation

#Objective
- Enable the robot to be remotely steered over a local network with minimal delay, using live camera streaming.

#Challenges Encountered
- Voltage mismatch between Arduino-compatible shields and Raspberry Pi
- Finding a streaming solution with low latency
- Implementing an efficient communication protocol
- Ensuring automatic connection and reconnection between the robot and phone

#Solutions
- Voltage Level Conversion: A logic level converter was used to adjust voltage from 3.3V (Raspberry Pi) to 5V (shield). An operational amplifier wasn’t required for PWM, as measured voltage on a single motor was 4.84V, safely below the maximum of 6V.
- Low-Latency Streaming: Many Android video players struggle with RTMP streams, especially when needing adjustable buffering. Therefore, RTSP was chosen as the streaming protocol, with ExoPlayer for video playback, allowing buffer customization for reduced delay.
- Communication Protocol: MQTT was selected for efficient data transmission, with a local broker configured to eliminate the need for internet access. The local broker is detected automatically when the app launches.
- Auto-Discovery: Zeroconf was implemented to automatically locate the Raspberry Pi’s IP address, simplifying the connection process. This ensures the app can run on any Android phone with SDK 24.

#Configurable Parameters
- Video Stream: RTSP or RTMP (RTMP offers slightly better quality but introduces marginally more delay)
- Connection Method: Zeroconf is preconfigured for use when the server isn’t running on the Pi Zero.

#Technologies and Tools
- Languages: Python (Raspberry Pi), Kotlin (Android app)
- Protocols: MQTT, RTSP/RTMP
- Software: MediaMTX (server on Raspberry Pi), Android Studio

#How to build
- Download and start MediaMTX for Raspberry server
- Configure automatical start file main.py on Rasberry
- Install app on Android Phone

#Summary
The robot performs well, maintaining a stable connection with a video streaming delay of about 0.2-0.3 seconds, which is adequate for general use with medium-quality visuals.
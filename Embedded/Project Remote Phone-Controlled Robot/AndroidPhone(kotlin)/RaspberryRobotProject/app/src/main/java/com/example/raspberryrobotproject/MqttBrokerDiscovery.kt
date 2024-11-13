package com.example.raspberryrobotproject

import android.util.Log
import javax.jmdns.JmDNS
import javax.jmdns.ServiceInfo
import java.io.IOException
import java.net.InetAddress
import java.net.NetworkInterface

class MqttBrokerDiscovery {
    private var broker: String = "localhost"

    fun discoverBroker(): String? {
        var jmDNS: JmDNS? = null

        try {
            val serviceType = "_mqtt._tcp.local."
            val serviceName = "MQTT Server on raspberrypi"
            val localHost = getLocalIpAddress() ?: return null
            jmDNS = JmDNS.create(localHost)

            Log.d("MqttBrokerDiscovery", "Starting Zeroconf discovery for MQTT broker...")
            val services: Array<ServiceInfo> = jmDNS.list(serviceType)

            for (service in services) {
                Log.d("MqttBrokerDiscovery", "Discovered service:")
                Log.d("MqttBrokerDiscovery", "Name: ${service.name}")
                Log.d("MqttBrokerDiscovery", "Type: ${service.type}")
                Log.d("MqttBrokerDiscovery", "Port: ${service.port}")
                Log.d("MqttBrokerDiscovery", "Addresses: ${service.inet4Addresses.joinToString { it.hostAddress }}")

                if (service.name == serviceName) {
                    val inetAddress = service.inet4Addresses.firstOrNull()
                    if (inetAddress != null) {
                        broker = inetAddress.hostAddress
                        Log.d("MqttBrokerDiscovery", "Found matching MQTT service '$serviceName' with IP: $broker")
                        return broker
                    } else {
                        Log.d("MqttBrokerDiscovery", "No valid IP address found for service: ${service.name}")
                    }
                    break
                }
            }

            if (broker == "localhost") {
                Log.d("MqttBrokerDiscovery", "No matching MQTT service found. Using default broker.")
            }

        } catch (e: IOException) {
            Log.e("MqttBrokerDiscovery", "Zeroconf discovery failed: ${e.message}")
            e.printStackTrace()
        } finally {
            jmDNS?.close()
        }

        Log.d("MqttBrokerDiscovery", "Discovery complete. Broker IP: $broker")
        return if (broker != "localhost") broker else null
    }


    private fun getLocalIpAddress(): InetAddress? {
        try {
            val interfaces = NetworkInterface.getNetworkInterfaces()
            while (interfaces.hasMoreElements()) {
                val networkInterface = interfaces.nextElement()
                val addresses = networkInterface.inetAddresses
                while (addresses.hasMoreElements()) {
                    val address = addresses.nextElement()
                    if (!address.isLoopbackAddress && address.isSiteLocalAddress) {
                        Log.d("MqttBrokerDiscovery", "Actual local IP address found: ${address.hostAddress}")
                        return address
                    }
                }
            }
        } catch (e: Exception) {
            Log.e("MqttBrokerDiscovery", "Error getting local IP address: ${e.message}")
            e.printStackTrace()
        }
        return null
    }
}

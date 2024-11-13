package com.example.raspberryrobotproject

import android.util.Log
import org.eclipse.paho.client.mqttv3.*
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence

class MqttClientManager(private val serverUri: String) {
    private val clientId = "AndroidClient"
    private val persistence = MemoryPersistence()
    private var mqttClient: MqttAsyncClient? = null

    fun connect() {
        mqttClient = MqttAsyncClient(serverUri, clientId, persistence)
        mqttClient?.setCallback(object : MqttCallbackExtended {
            override fun connectComplete(reconnect: Boolean, serverURI: String) {
                Log.d("MqttClient", "Connected to MQTT broker")
                subscribe("phone")
            }

            override fun connectionLost(cause: Throwable) {
                Log.d("MqttClient", "Connection lost: ${cause.message}")
            }

            override fun messageArrived(topic: String, message: MqttMessage) {
                Log.d("MqttClient", "Message arrived: ${message.payload.decodeToString()}")
            }

            override fun deliveryComplete(token: IMqttDeliveryToken) {
                Log.d("MqttClient", "Message delivery complete")
            }
        })

        val options = MqttConnectOptions().apply {
            isAutomaticReconnect = true
            maxReconnectDelay = 1000
            keepAliveInterval = 30
        }

        mqttClient?.connect(options, null, object : IMqttActionListener {
            override fun onSuccess(asyncActionToken: IMqttToken) {
                Log.d("MqttClient", "Connection successful")
            }

            override fun onFailure(asyncActionToken: IMqttToken, exception: Throwable) {
                Log.d("MqttClient", "Connection failed: ${exception.message}")
            }
        })
    }

    fun disconnect() {
        mqttClient?.disconnect()
    }

    fun publish(topic: String, payload: String) {
        mqttClient?.publish(topic, payload.toByteArray(), 0, false)
    }

    fun subscribe(topic: String) {
        mqttClient?.subscribe(topic, 0)
    }

    fun isConnected(): Boolean {
        return mqttClient?.isConnected ?: false
    }
}

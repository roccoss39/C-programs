package com.example.raspberryrobotproject

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.enableEdgeToEdge
import kotlinx.coroutines.*
import android.util.Log
import androidx.media3.ui.PlayerView
import com.example.raspberryrobotproject.databinding.ActivityMainBinding

class MainActivity : ComponentActivity() {

    private lateinit var views: ActivityMainBinding
    private var mqttClientManager: MqttClientManager? = null
    private lateinit var exoPlayerManager: ExoPlayerManager
    private lateinit var playerView: PlayerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        views = ActivityMainBinding.inflate(layoutInflater)
        setContentView(views.root)

        playerView = findViewById(R.id.playerView)
        val joystickView: JoystickView = findViewById(R.id.joystickView)

        CoroutineScope(Dispatchers.IO).launch {
            while (true) {
                val mqttBrokerDiscovery = MqttBrokerDiscovery()
                val brokerIp = mqttBrokerDiscovery.discoverBroker()

                if (brokerIp != null) {
                    val serverUri = "tcp://$brokerIp:1883"
                    mqttClientManager = MqttClientManager(serverUri)

                    mqttClientManager?.let { client ->
                        if (!client.isConnected()) {
                            client.connect()
                        }
                    }
                    val streamUrl = "rtsp://$brokerIp:8554/mystream"
                    withContext(Dispatchers.Main) {
                        exoPlayerManager = ExoPlayerManager(this@MainActivity, playerView)
                        exoPlayerManager.initializePlayer(streamUrl)
                    }

                    joystickView.setOnMoveListener(object : JoystickView.OnMoveListener {
                        override fun onMove(x: Int, y: Int) {
                            mqttClientManager?.let { client ->
                                if (client.isConnected()) {
                                    client.publish("phone-rasp", "$x, $y")
                                }
                            }
                        }
                    })
                    break
                } else {
                    Log.e("Main", "No MQTT broker found. Retrying in 1 seconds...")
                    delay(1000)
                }
            }
        }
    }
}

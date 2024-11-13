package com.example.raspberryrobotproject

import android.content.Context
import androidx.annotation.OptIn
import androidx.media3.common.MediaItem
import androidx.media3.common.util.UnstableApi
import androidx.media3.exoplayer.DefaultLoadControl
import androidx.media3.exoplayer.ExoPlayer
import androidx.media3.exoplayer.SeekParameters
import androidx.media3.exoplayer.trackselection.DefaultTrackSelector
import androidx.media3.ui.PlayerView

class ExoPlayerManager(private val context: Context, private val playerView: PlayerView) {

    private lateinit var player: ExoPlayer

    @OptIn(UnstableApi::class)
    fun initializePlayer(streamUrl: String) {
        val loadControl = DefaultLoadControl.Builder()
            .setBufferDurationsMs(
                10,
                200,
                10,
                10
            )
            .setPrioritizeTimeOverSizeThresholds(true)
            .build()

        val trackSelector = DefaultTrackSelector(context).apply {
            setParameters(
                buildUponParameters()
                    .setForceLowestBitrate(true)
                    .setMaxVideoSizeSd()
            )
        }

        player = ExoPlayer.Builder(context)
            .setTrackSelector(trackSelector)
            .setLoadControl(loadControl)
            .build()

        player.setSeekParameters(SeekParameters.CLOSEST_SYNC)
        player.playWhenReady = true
        playerView.player = player

        val mediaItem = MediaItem.fromUri(streamUrl)
        player.setMediaItem(mediaItem)
        player.prepare()
    }
}

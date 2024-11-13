package com.example.raspberryrobotproject

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.util.AttributeSet
import android.view.MotionEvent
import android.view.View

class JoystickView @JvmOverloads constructor(
    context: Context,
    attrs: AttributeSet? = null,
    defStyleAttr: Int = 0
) : View(context, attrs, defStyleAttr) {

    private var centerX = 0f
    private var centerY = 0f
    private var radius = 175f
    private var thumbRadius = 50f
    private var joystickPaint: Paint = Paint()
    private var thumbPaint: Paint = Paint()
    private var listener: OnMoveListener? = null
    private var thumbX = 0f
    private var thumbY = 0f

    init {
        joystickPaint.color = Color.argb(125, 0, 0, 0)
        joystickPaint.style = Paint.Style.STROKE
        joystickPaint.strokeWidth = 10f

        thumbPaint.color = Color.argb(75, 255, 255, 255)
        thumbPaint.style = Paint.Style.FILL

        thumbX = centerX
        thumbY = centerY
    }

    interface OnMoveListener {
        fun onMove(x: Int, y: Int)
    }

    fun setOnMoveListener(listener: OnMoveListener) {
        this.listener = listener
    }

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)
        canvas.drawCircle(centerX, centerY, radius, joystickPaint)
        drawThumb(canvas)
    }

    override fun onSizeChanged(w: Int, h: Int, oldw: Int, oldh: Int) {
        super.onSizeChanged(w, h, oldw, oldh)
        centerX = (w / 2).toFloat()
        centerY = (h / 2).toFloat()
        thumbX = centerX
        thumbY = centerY
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        val x = event.x - centerX
        val y = event.y - centerY

        when (event.action) {
            MotionEvent.ACTION_MOVE -> {
                val distance = Math.sqrt((x * x + y * y).toDouble()).toFloat()
                if (distance <= radius) {
                    thumbX = event.x
                    thumbY = event.y
                    val scaledY = (-y / radius * 100).toInt().coerceIn(-100, 100)
                    val scaledX = (x / radius * 100).toInt().coerceIn(-100, 100)
                    listener?.onMove(scaledX, scaledY)
                } else {
                    val scale = radius / distance
                    val scaledY = (-scale * y / radius * 100).toInt().coerceIn(-100, 100)
                    val scaledX = (scale * x / radius * 100).toInt().coerceIn(-100, 100)
                    listener?.onMove(scaledX, scaledY)
                    thumbX = centerX + x * scale
                    thumbY = centerY + y * scale
                }
                invalidate()
                return true
            }
            MotionEvent.ACTION_UP -> {
                listener?.onMove(0, 0)
                thumbX = centerX
                thumbY = centerY
                invalidate()
            }
            MotionEvent.ACTION_DOWN -> {
                thumbX = event.x
                thumbY = event.y
                invalidate()
                return true
            }
        }
        return true
    }

    private fun drawThumb(canvas: Canvas) {
        canvas.drawCircle(thumbX, thumbY, thumbRadius, thumbPaint)
    }
}

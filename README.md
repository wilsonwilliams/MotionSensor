# MotionSensor

This project makes use of an Arduino, ultrasonic sensor, push button, and a green and red LED.
The device makes use of three states: arming, waiting, and alarmed. In the picture, the current
state is the arming state, both LEDs being lit. Once armed, the red LED will be turned off until
the ultrasonic sensor has detected movement, turning off the green LED and on the red LED. To reset
the system, only one click of the push button is required.

# Parking-Sensor

This is a very simple arduino based project. It is a project which is used in automobiles, especially when parking in reverse gear, it beeps more rapidly as it nears an obstacle, which will warn the driver of some incoming obstacle.

Materials Required:
                    1.Hardware
                      a.Arduino Uno Board
                      b.Ultrasonic sensor HC-SR04
                      c.Buzzer
                      d.LED
                      e.Connecting Wires
                      f.BreadBoard Mini
                    2.Software
                      a.arduino IDE
                      
Theory: When an ultrasonic sensor Generates a ping from the trig pin, It bounces off an obstacle and Hits the echo Pin, the ping time is           determined by the pulseIn(echo,HIGH) method. Knowing the speed of sound in the medium, We can find out the distance. Then using the         conditional if statements, we can make the buzzer beep accordingly

Language: C++

#include <Servo.h> // Incluimos la biblioteca Servo

Servo miServo; // Creamos un objeto Servo
int pin=9;
void setup() {
  miServo.attach(pin); // Conectamos el servo al pin 9 (puede ser otro PWM)
}
void loop() {
  // Movemos el servo de 0 a 170 grados
  for (int angulo = 0; angulo <= 170; angulo++) {
    miServo.write(angulo); // Establecemos el ángulo del servo
    delay(15); // Pequeña pausa para que el movimiento sea suave
  }

  // Movemos el servo de 170 a 0 grados
  for (int angulo = 170; angulo >= 0; angulo--) {
    miServo.write(angulo); // Establecemos el ángulo del servo
    delay(15); // Pequeña pausa para que el movimiento sea suave
  }
}
int gasVal;
volatile int velocidad = 500;
const int maxima = 5000;
const int minima = 100;
const int aumenta = 50;
int serial=0;

void setup() {
  Serial.begin(1200);//terminal
  Serial2.begin(9600);//bluetooh

  attachInterrupt(digitalPinToInterrupt(3), delayMas, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), delayMenos, RISING);
  attachInterrupt(digitalPinToInterrupt(18), saludoFunc, FALLING);
}

void loop() {
  gasVal=analogRead(A0);
  Serial.print("gas> ");
  Serial.println(gasVal);
  
  Serial.print("vel> ");
  Serial.print(velocidad);
  Serial.print("\t");

  Serial2.print(gasVal);
  Serial2.print(",");
  Serial2.println(velocidad);
  
  delay(velocidad);
}


// ISR pin 2, disminuye la velocidad
void delayMenos()
{
  velocidad = velocidad - aumenta;
  if (velocidad < minima) velocidad = minima;
  Serial.println("ISR2 MENOS FLANCO UP");
}
 
// ISR pin 3, aumenta la velocidad
void delayMas()
{
  velocidad = velocidad + aumenta;
  if (velocidad > maxima) velocidad = maxima;
  Serial.println("ISR3 MAS BAJADA");
}

void saludoFunc(){
  Serial.println("ISR18 :3 :3 :3 CAMBIO");
}
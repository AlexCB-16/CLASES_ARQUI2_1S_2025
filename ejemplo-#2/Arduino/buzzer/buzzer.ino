// Definir las frecuencias de las notas
#define SS  -1//silencio
#define DO  523.25//C
#define RE  590.37//D
#define MI  659.26//e
#define FA  698.46//f
#define SOL 790//G
#define LA  835//A
#define SI  990//B
#define DO2 1052//D2

// Definir la duración de las notas
int semi=125;//s
int corche=250;//c
int negra = 500; //n
int blanca = 1000; //b
int redonda = 2000; //r

// Pin del buzzer
int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
   tocarNota(MI, blanca);
  tocarNota(SOL, negra);
  tocarNota(RE, blanca);
  tocarNota(DO, negra);
  tocarNota(RE, negra);
  tocarNota(MI, blanca);
  tocarNota(SOL, negra);
  tocarNota(RE, blanca);

  delay(4000);


}

// Función para tocar una nota
void tocarNota(int frecuencia, int duracion) {
  if(frecuencia!=-1)
    tone(buzzerPin, frecuencia); // Activa el tono
  delay(duracion);             // Espera la duración de la nota
  if(frecuencia!=-1)
    noTone(buzzerPin);           // Detiene el tono
  
  delay(50);                   // Pequeña pausa entre notas
}
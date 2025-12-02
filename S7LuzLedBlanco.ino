// programa para controlar un ldr + led blanco
// Desarrollado por Leandro Teran Xolocotzi 
// Definición de pines
const int ldrPin = A0;       // Pin analógico para el LDR
const int ledPin = 8;        // Pin para el LED blanco

// Umbral de detección de luz (ajusta según sea necesario)
const int LuzUmbral = 500;

void setup() {
  // Inicializa el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  
  // Inicializa la comunicación serial para depuración
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del LDR
  int ValorLdr= analogRead(ldrPin);
  
  // Muestra el valor leído en el monitor serial
  Serial.println(ValorLdr);
  
  // Si el valor del LDR es menor que el umbral, no hay luz ambiental
  if (ValorLdr < LuzUmbral) {
    Serial.println("Luz ambiental detectada. Apagando LED...");
    digitalWrite(ledPin, LOW);  // Enciende el LED
  } else {
    Serial.println("Oscuridad detectada. Encendiendo LED...");
    digitalWrite(ledPin, HIGH);   // Apaga el LED
  }
  
  // Pequeña pausa antes de la siguiente lectura
  delay(100);
}
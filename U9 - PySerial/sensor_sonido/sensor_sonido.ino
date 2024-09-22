int sensor = A0;
unsigned long tiempoAnterior = 0;
const int intervaloMuestreo = 125; // Tiempo entre muestreos en milisegundos (8 kHz = 0.125 ms)

void setup() {
  Serial.begin(115200); // Inicializa la comunicación serie
}

void loop() {
  unsigned long tiempoActual = millis();

  // Comprobar si pasó el intervalo de muestreo
  if (tiempoActual - tiempoAnterior >= intervaloMuestreo) {
    tiempoAnterior = tiempoActual; // Actualiza el tiempo anterior
    int muestra = analogRead(sensor); // Leer el valor analógico
    Serial.println(muestra); // Enviar la muestra por Serial
  }
}

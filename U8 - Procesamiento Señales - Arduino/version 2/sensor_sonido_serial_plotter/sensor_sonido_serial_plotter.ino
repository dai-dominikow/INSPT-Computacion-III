
#include <arduinoFFT.h>


int led = 11;
int sensor = A0;
const int muestras = 64; //debe ser potencia de 2
const int frecMuestreo = 1000; // por lo menos el doble de la voz humana, segun wikipedia max 255 Hz.
double periodo = 1000.0 /frecMuestreo; //tiempo en milisegundos entre muestras
double vData[muestras];
double vDataIm[muestras];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vData, vDataIm, muestras, frecMuestreo);

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin (115200);
  delay(1000); // para que cargue el puerto serial le doy un cachito, en microsegundos!
}

void loop (){
  digitalWrite(led, LOW);
  unsigned long inicio = millis();
  int i = 0;
  while (i < muestras){
    unsigned long ahora = millis();
    if (ahora - inicio >= (i * periodo)){
      int muestra = analogRead(sensor);
      // el analogRead levanta valores entre 0 y 1024, tengo que llevarlos de -128 a 128 para hacerles una transformada
      vData[i] = muestra/4.0 - 128.0; //levanta la infodel sensor
      vDataIm[i] = 0.0; //tengo que pasarle si o si un imaginario
      //Serial.println(vData[i]);
      if (abs( vData[i]) >= 10){
        digitalWrite(led, HIGH);
      }
      i++;
    }
  }
  FFT.windowing(vData,muestras,FFT_WIN_TYP_HAMMING,FFT_FORWARD); //Hamming
  FFT.compute(vData,vDataIm,muestras,FFT_FORWARD);
  FFT.complexToMagnitude(vData,vDataIm,muestras);
  for (int n  = 0; n < (muestras); n++){
    double frecuencia = n * (frecMuestreo / muestras);
    double magnitud = vData[n];
    Serial.print(frecuencia);
    Serial.print("\t"); //para que deje un 
    Serial.println(magnitud);
  }
  delay(500); //espera 1000 milisegundos para la siguiente muestra
}

int led = 11;
int sensor = A0;
int frecMuestreo = 1000; // por lo menos el doble de la voz humana, segun wikipedia max 255 Hz.

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin (9600);
  delay(1000); // para que cargue el puerto serial le doy un cachito
}

void loop (){
  digitalWrite(led, LOW);
  int muestra = analogRead(sensor);
  // el analogRead levanta valores entre 0 y 1024, tengo que llevarlos de -128 a 128 para hacerles una transformada
  int data = muestra/4 - 128;
  Serial.println(data);
  if (abs(data) >= 5){
    digitalWrite(led, HIGH);
   }
  delay(1000/frecMuestreo); //recordemos que delay() toma milisegundos por parametro.  
}

int led = 6;
int fotores = A0;
int dato; 
int datomap;


void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
delay(1000); // segundo
}

void loop() {
  delay(1000); // un dato por segundo
  //leer la info del fotoresistor:
  dato = analogRead(fotores);
  //la función MAP, hace el trabajo de pasar una escala de 10 bits (0 a 1023) a la de 8 bits del pin PWM (0 a 255)
  datomap = map(dato, 0, 1023, 0, 255);
  analogWrite(led,datomap);
  //para leer el valor del fotoresistor:
  Serial.println(dato);
}
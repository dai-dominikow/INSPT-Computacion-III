int led = 6;
int fotores = A0;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
delay(1000); // segundo
}

void loop() {
  delay(1000); // un dato por segundo
  //leer la info del fotoresistor:
  foto = analogRead(fotores);
  //la función MAP, hace el trabajo de pasar una escala de 10 bits (0 a 1023) a la de 8 bits del pin PWM (0 a 255)
  analogWrite(led,map(foto, 0, 1023, 0, 255));
  //para leer el valor del fotoresistor:
  Serial.println(foto);
}
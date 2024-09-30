int led = 6;
int foto = A0;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
delay(1000); // segundo
}

void loop() {
  delay(1000); // un dato por segundo
  //leer la info del fotoresistor:
  foto = analogRead(foto);
  //la función MAP, hace el trabajo de pasar una escala (0 a 1023) a otra ( 0 a 255 )
  analogWrite(led,map(foto, 0, 1023, 0, 255));
  //para leer el valor del fotoresistor:
  Serial.println(foto);
}
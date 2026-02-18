//la forma de conectarlo es una division de tensión.
//la resistencia utilizada es de 100 ohm
//la luz incide en la fotoresistencia, la caida de tension en el cable es 5* resistencia del circuito.
//los pines analogicos se toman por default como input.


int motor = 5;
int foto = 0;

void setup(){
  pinMode(motor, OUTPUT);
}

void loop(){
  foto = analogRead(A0);
  analogWrite(motor,map(foto, 0, 1023, 0, 255) );
}

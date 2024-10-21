/* carga y descarga de un capacitor, 
 * Para el ejercicio C=220 microf, Rcarga=1 kOhm, Rdescarga=470 Ohm
*/

// Pines usados
#define cargar 13   
#define descargar 11    // descarga auxiliar
#define medir 0 
unsigned long t0;   // tiempo inicio lecturas
unsigned int valorsensor;

void setup () {
  pinMode(cargar, OUTPUT );    // pin de carga  
  pinMode(descargar, OUTPUT ); // pin de descarga auxiliar
  Serial.begin(9600);          // envio dato serial
}

void loop(){
  /* Descarga capacitor */ 
  digitalWrite(cargar, LOW );
  digitalWrite(descargar, LOW );          
  valorsensor = analogRead(medir);
  while (valorsensor> 0) {
    Serial.println(valorsensor) ;
    valorsensor = analogRead(medir);
  }
  /* carga capacitor */ 
  digitalWrite (cargar, HIGH ); 
  pinMode(descargar, INPUT );    // pin auxiliar con alta impedancia
  valorsensor = analogRead (medir); 
  while (valorsensor <1016) {         // valor maximo de carga de 1024 
    Serial.println(valorsensor);
    valorsensor = analogRead(medir);
  }
}
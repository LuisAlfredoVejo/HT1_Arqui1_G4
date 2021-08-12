//Variable para el pin analogo
int pinAnalogo = A0;

//Lista con los pines digitales del display
int listaPines[7] = {23, 25, 27, 29, 31, 33, 35};

//Variables para los numeros mostrados en el display
boolean cero[7] = {true, true, true, true, true, true, false};
boolean uno[7] = {false, true, true, false, false, false, false};
boolean dos[7] = {true, true, false, true, true, false, true};
boolean tres[7] = {true, true, true, true, false, false, true};
boolean cuatro[7] = {false, true, true, false, false, true, true};
boolean cinco[7] = {true, false, true, true, false, true, true};
boolean seis[7] = {true, false, true, true, true, true, true};
boolean siete[7] = {true, true, true, false, false, false, false};
boolean ocho[7] = {true, true, true, true, true, true, true};
boolean nueve[7] = {true, true, true, true, false, true, true};




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Inicializar Pines Digitales
  for(int i=0; i<8; i++){

    pinMode(listaPines[i], OUTPUT);
    digitalWrite(listaPines[i], LOW);
    }
}

void encenderDisplay(int posicion, boolean valor){
  if(valor){
    digitalWrite(listaPines[posicion], HIGH);
    }
  else{
    digitalWrite(listaPines[posicion], LOW);
    }
  
  }

void procesarPines(boolean arreglo[]){
  for(int i=0; i<8; i++){
    encenderDisplay(i, arreglo[i]);
    }
  }

void metodoPot(){
int lectura_pot = analogRead(pinAnalogo);
if(lectura_pot == 0){
  procesarPines(cero);
}
else if(lectura_pot>=100 && lectura_pot<=200){
  procesarPines(uno);
  }
else if(lectura_pot>200 && lectura_pot<300){
  procesarPines(dos);
  }
else if(lectura_pot>300 && lectura_pot<400){
  procesarPines(tres);
  }
else if(lectura_pot>400 && lectura_pot<512){
  procesarPines(cuatro);
  }
else if(lectura_pot>500 && lectura_pot<614){
  procesarPines(cinco);
  }
else if(lectura_pot>600 && lectura_pot<717){
  procesarPines(seis);
  }
else if(lectura_pot>700 && lectura_pot<819){
  procesarPines(siete);
  }
else if(lectura_pot>800 && lectura_pot<922){
  procesarPines(ocho);
  }
else if(lectura_pot>900 && lectura_pot<1023){
  procesarPines(nueve);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  int lectura_pot = analogRead(pinAnalogo);
  delay(500);
  //Impresion de la lectura del potenciometro en virtual terminal
  Serial.println(lectura_pot);
  metodoPot(); 

  
  

}

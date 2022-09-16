String incomingByte ;   
String n1; 
String n2; 
String n3;  
int tiempo1;
int tiempo2;
int tiempo3;

void setup() {

  Serial.begin(9600);

  pinMode(Q0_0, OUTPUT);

}
void loop() {

  if (Serial.available() > 0) {

  // Leemos lo que este en el serial
  incomingByte = Serial.readStringUntil('\n');
  delay(1000);
  n1 = Serial.readStringUntil('\n');
  delay(1000);
  n2 = Serial.readStringUntil('\n');
  delay(1000);
  n3 = Serial.readStringUntil('\n');

  // Empezamos con las condiciones de operación de los tiempos
    if (n1 == "1000" || n1 == "3000" || n1 == "5000") {
     //digitalWrite(Q0_1,HIGH); // encendemos foco
      tiempo1= n1.toInt(); //convertimos string a int
    }

    if (n2 == "1000" || n2 == "3000" || n2 == "5000") {
      //digitalWrite(Q0_1,HIGH); // encendemos foco
      tiempo2= n2.toInt(); //convertimos string a int
    }

    if (n3 == "1000" || n3 == "3000" || n3 == "5000") {
      //digitalWrite(Q0_1,HIGH); // encendemos foco
      tiempo3= n3.toInt(); //convertimos string a int
    }
    
    if (incomingByte == "on") { // Botón de arranque
      
      Serial.write("Led on");
      digitalWrite(Q0_0,HIGH); // encendemos foco
      delay(tiempo1); // tiempo variable en base a n
      digitalWrite(Q0_0,LOW); // apagamos foco
  //////////////////// FOCO 2
      digitalWrite(Q0_6,HIGH); // encendemos foco
      delay(tiempo2); // tiempo variable en base a n
      digitalWrite(Q0_6,LOW); // apagamos foco
    //////////////////// FOCO 3
      digitalWrite(Q0_1,HIGH); // encendemos foco
      delay(tiempo3); // tiempo variable en base a n
      digitalWrite(Q0_1,LOW); // apagamos foco
    

    }

    else if (incomingByte == "off") {

      digitalWrite(Q0_0, LOW);
      digitalWrite(Q0_1, LOW);
      digitalWrite(Q0_6, LOW);

      Serial.write("Led off");

    }

    else{

     Serial.write("invald input");

    }

  }

}

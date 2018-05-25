int recepByte = 0 ;
int tabCourant[]= {127, 127, 127, 127};
int i = 0 ;

void setup() {
 
  Serial.begin(9600);
  // Bus PIC 1
  pinMode(22, OUTPUT); //LSB
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT); 
  pinMode(36, OUTPUT) ;//MSB

}

void loop() {

// Bloc réception données Xbee :
  i=0;

  Serial.println("Startrecep");

  
  while (recepByte!=255 && i<4) { // réception d'une trame

    if (Serial.available()>0) {
      
       recepByte= Serial.read(); //lecture port série
       tabCourant[i] = recepByte; //On remplit le tableau de consignes       
       Serial.print(recepByte); //test avec PC
       Serial.print(" ; ");
       i++;
      } 
      
  }
  Serial.println("");
  Serial.println("endrecep");
  Serial.println("startemit");
  
    // Bloc consignes
   for (int j = 0 ; j<4 ; j++) {
      for (int k=0 ; k<8 ; k++) {
          digitalWrite((22 + 2*k), bitRead(tabCourant[j],k));
          Serial.print(digitalRead(22 + 2*k));
      } 
      Serial.print(",");
   }

   Serial.println("endemit");
   
    


  recepByte = 0 ;            

}

const int ldr_pin = 7;

void setup() {
  // put your setup code here, to run once:
    pinMode(ldr_pin,INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
   if( digitalRead( ldr_pin ) == 1){
      Serial.println("Night");
   }
   else{
       Serial.println("Day");
   }
   
   delay(200);
}

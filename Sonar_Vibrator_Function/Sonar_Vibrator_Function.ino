#define RvibPin 2
#define MvibPin 3
#define LvibPin 4
const int trigPinR = 48;
const int echoPinR = 49;
const int trigPinM = 50;
const int echoPinM = 51;
const int trigPinL = 52;
const int echoPinL = 53;
int durationL;
long distanceL;
int durationM;
long distanceM;
int durationR;
long distanceR;


void setup() {
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  pinMode(RvibPin, OUTPUT);  
  pinMode(trigPinM, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinM, INPUT); // Sets the echoPin as an Input
  pinMode(MvibPin, OUTPUT);
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  pinMode(LvibPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
 MainUltraSonic();
 
}

void RightUltrasonic(){
// Clears the trigPin
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
   durationR = pulseIn(echoPinR, HIGH);
  // Calculating the distance
   distanceR = durationR * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("R-Distance: ");
  Serial.println(distanceR);  
    
}

void MidUltrasonic(){
  // Clears the trigPin
  digitalWrite(trigPinM, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinM, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinM, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationM = pulseIn(echoPinM, HIGH);
  // Calculating the distance
  distanceM = durationM * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("M-Distance: ");
  Serial.println(distanceM);  
     
}

void LeftUltrasonic(){
  // Clears the trigPin
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationL = pulseIn(echoPinL, HIGH);
  // Calculating the distance
  distanceL = durationL * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("L-Distance: ");
  Serial.println(distanceL);  
  
}

void MainUltraSonic(){
  RightUltrasonic();
  MidUltrasonic();
  LeftUltrasonic();

 if(distanceR <= 100 || distanceM <= 100 || distanceL <= 100){
    digitalWrite(LvibPin, HIGH);
    digitalWrite(MvibPin, HIGH);
    digitalWrite(RvibPin, HIGH);    
    }
  else{
    digitalWrite(LvibPin, LOW);
    digitalWrite(MvibPin, LOW);
    digitalWrite(RvibPin, LOW);
  }
}
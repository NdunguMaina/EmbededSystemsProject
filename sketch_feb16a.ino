#define echo 2
  #define trig 3
  #define outA 8// Red LED
  #define outB 9// Green LED
  #define outC 10// Buzzer
  
  float  duration; // time taken by the pulse to return back
  float  distance; // oneway distance travelled by the pulse

  const int intruderDistance = 10;  // the minimum distance upto which the sensor is able to sense any object

  void setup() {
  
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    
    pinMode(outA, OUTPUT);
    digitalWrite(outA, LOW);
    
    pinMode(outB, OUTPUT);
    digitalWrite(outB, LOW);

    pinMode(outC, OUTPUT);
    digitalWrite(outC, LOW);
    Serial.begin(9600);
  
  }
  
  void loop() {
  
    time_Measurement();
    distance = (float)duration * (0.0200) / 2;   // calculate the oneway distance travelled by the pulse
    Serial.println(distance);
    alarm_condition(); 
    
  }
  
  void time_Measurement()
  { // function to measure the time taken by the pulse to return back
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  
    duration = pulseIn(echo, HIGH);
  }

  void alarm_condition()
  { //function to execute the output commands based on the sensor input
    if(distance<=intruderDistance)
    { digitalWrite(outA,HIGH);
      digitalWrite(outB,LOW);
      analogWrite(outC,200);}
    else
    {  digitalWrite(outA,LOW);
       digitalWrite(outB,HIGH);
       analogWrite(outC,0);
       }
  }
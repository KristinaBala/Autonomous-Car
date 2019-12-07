

#define LT_R !digitalRead(3)

#define LT_L !digitalRead(2)


#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7



void left(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Car left");
}

void right(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); 
  Serial.println("go right!");
} 

 

void setup(){
  Serial.begin(9600);
}

void loop() {
 
  else if(!LT_R && !LT_L)
  {
    left();
    {
         if(LT_R) {
           right();
           while(LT_R);
           }
         else if(LT_L) {
            left();
            while(LT_L);
            }
   }
  
  } 
}

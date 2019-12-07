    #define EN_Mot_Left 10 
    #define EN_Mot_Right 11         
    #define IN1 8  
    #define IN2 9 
    #define IN3 12
    #define IN4 7
 
    int Trigger_Front = A4;
    int Echo_Front = A5;
    
    int Trigger_Left = A2;
    int Echo_Left = A3;
    
    int Trigger_Right = A0;
    int Echo_Right = A1;
    
     
    void setup()
    {
        pinMode(Trigger_Front, OUTPUT); 
        pinMode(Echo_Front, INPUT);
        
        pinMode(Trigger_Left, OUTPUT);
        pinMode(Echo_Left, INPUT);       
        
        pinMode(Trigger_Right, OUTPUT);
        pinMode(Echo_Right, INPUT);
       
        pinMode(EN_Mot_Left, OUTPUT);
        pinMode(EN_Mot_Right, OUTPUT);
     
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(IN4, OUTPUT);       
        delay(5000);
    }
    
   
    void loop()
    {
     
     long Front_Time, Left_Time, Right_Time, Right, Left, Front; 

     digitalWrite (Trigger_Front, LOW);
     delayMicroseconds(2);
     digitalWrite(Trigger_Front, HIGH);
     delayMicroseconds(5);
     digitalWrite(Trigger_Front, LOW);
     Front_Time = pulseIn(Echo_Front, HIGH);
     Front = Front_Time/29/2;
    
     digitalWrite(Trigger_Left, LOW);
     delayMicroseconds(2);
     digitalWrite(Trigger_Left, HIGH);
     delayMicroseconds(5);
     digitalWrite(Trigger_Left, LOW); 
     Left_Time = pulseIn(Echo_Left, HIGH);
     Left = Left_Time/29/2;
    
     digitalWrite(Trigger_Right, LOW);
     delayMicroseconds(2);
     digitalWrite(Trigger_Right, HIGH);
     delayMicroseconds(5);
     digitalWrite(Trigger_Right, LOW); 
     Right_Time = pulseIn(Echo_Right, HIGH);
     Right = Right_Time/29/2; 
     
     analogWrite(EN_Mot_Left, 0);
     analogWrite(EN_Mot_Right, 0); 
     analogWrite(IN1, 0);            
     analogWrite(IN2, 0);              
     analogWrite(IN3, 0);            
     analogWrite(IN4, 0);            
     
       if(Front >8)
         {  
         
           if(Right >7 && Right< 13) 
             {               
               analogWrite(EN_Mot_Left, 120);
               analogWrite(EN_Mot_Right, 150);
           
               analogWrite(IN1, 255);
               analogWrite(IN2, 0);
               analogWrite(IN3, 0);
               analogWrite(IN4, 255);                                                        
             }
         
           if(Right >=13)
             {
               analogWrite(EN_Mot_Left, 255);
               analogWrite(EN_Mot_Right, 60);
           
               analogWrite(IN1, 255);
               analogWrite(IN2, 0);
               analogWrite(IN3, 0);
               analogWrite(IN4, 255);                               
             }
             
                 
           if(Right <=7)
             {
               analogWrite(EN_Mot_Left, 60);
               analogWrite(EN_Mot_Right, 255);
           
               analogWrite(IN1, 255);
               analogWrite(IN2, 0);
               analogWrite(IN3, 0);
               analogWrite(IN4, 255);                   
             }
         }
         
              
       if(Left <=20 && Right>20 && Front <=8) Turn_Right();
       if(Left >20 && Right>20 && Front <=8) Turn_Right();
       if(Right <=20 && Left>20 && Front <=8) Turn_Left();
       if(Right<=20 && Left<=20 && Front<=8) Back(); 
    }
       
    void Turn_Left() 
      {
       
        analogWrite(EN_Mot_Left, 120);
        analogWrite(EN_Mot_Right, 120);
           
        analogWrite(IN1, 0);
        analogWrite(IN2, 255);
        analogWrite(IN3, 0);
        analogWrite(IN4, 255);
        delay(700);      
        
      }
    
    void Turn_Right()
      {
        
      
        analogWrite(EN_Mot_Left, 120);
        analogWrite(EN_Mot_Right, 120);
        
        analogWrite(IN1, 255);
        analogWrite(IN2, 0);
        analogWrite(IN3, 255);
        analogWrite(IN4, 0);             
        delay(800);
               
      }
    
    void Back()
      {
       
        analogWrite(EN_Mot_Left, 120);
        analogWrite(EN_Mot_Right, 120);
           
        analogWrite(IN1, 255);
        analogWrite(IN2, 0);
        analogWrite(IN3, 255);
        analogWrite(IN4, 0);
        delay(1200); 
         
      } 

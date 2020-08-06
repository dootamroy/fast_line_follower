void call()
    {
      digitalWrite(23,HIGH);
      digitalWrite(25,HIGH);
      digitalWrite(27,HIGH);
      digitalWrite(29,HIGH);
      
      while(time<4000)
     {
      time=millis();
      CalRead();
      //auto_cal_motor();
     }
     
     digitalWrite(23,LOW);
     digitalWrite(25,LOW);
     digitalWrite(27,LOW);
     digitalWrite(29,LOW);


     for(int x=0;x<9;x++)
     {
       mid[x]=(amin[x]+(amax[x]-amin[x])*0.5);
     }
     
     delay(300);
    }


/*
void auto_cal_motor()                        ///.....................auto calibrATION motor control....................///
{
   int spd=90;
  
   if(time<1000)   ///right.
   {
     digitalWrite(3,LOW);
     analogWrite(2,spd);
     digitalWrite(5,LOW);
     analogWrite(4,spd);
     digitalWrite(6,LOW);
     analogWrite(7,spd);
     digitalWrite(9,LOW);
     analogWrite(8,spd);
     delay(10);
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);   
     //delay(100);
   }
  if(time>=1000 && time<3000)   ///left.
   {
     digitalWrite(2,LOW);
     analogWrite(3,spd);
     digitalWrite(4,LOW);
     analogWrite(5,spd);
     digitalWrite(7,LOW);
     analogWrite(6,spd);
     digitalWrite(8,LOW);
     analogWrite(9,spd);
     delay(10);
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);   
     //delay(100);
   }
  if(time>=3000 && time<=4000)    ///right align center.
   {
     digitalWrite(3,LOW);
     analogWrite(2,spd);
     digitalWrite(5,LOW);
     analogWrite(4,spd);
     digitalWrite(6,LOW);
     analogWrite(7,spd);
     digitalWrite(9,LOW);
     analogWrite(8,spd);
     delay(40);
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);   
     //delay(100);
   }
  
}


 */ 

    void initLED()
    {
    int x;
    for (x = 0;x < 9;x++)
    {
        amax[x] = 0; ///Amax is the value called B in the tutorial
        amin[x] = 1023; ///Amin is the value called A in the tutorial
    }

    }


 void CalRead()
 { 
    int x;
    for (x = 0 ; x<9 ; x++)  //For the first 7 line follower detectors.
    {  
        read_ir=analogRead(ir[x]);
        amax[x] = max(amax[x],read_ir); ///if we store a value higher than the last stored we replace it.
        amin[x] = min(amin[x],read_ir); ///if we store a value lower than the last stored we replace it.
    }
    
} 

 void ir_read()                      ///READING SENSOR VALUES AND ASSIGNING.///
 {
  for(int x=0;x<9;x++)
  {
    read_ir=analogRead(ir[x]);
    
    if(read_ir<(mid[x]))
    {
      val[x]=0;
    }
    else
      val[x]=1;
  }
 }



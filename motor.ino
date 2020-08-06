void motor()
{
  int rightMotorSpeed = 100 - PIDvalue;
  int leftMotorSpeed = 100 + PIDvalue;
  
//    if (rightMotorSpeed > 255 ) rightMotorSpeed = 255; // prevent the motor from going beyond max speed
//    if (leftMotorSpeed > 255 ) leftMotorSpeed = 255; // prevent the motor from going beyond max speed


    if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
    if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
    
    
    digitalWrite(3,LOW);
    analogWrite(2,leftMotorSpeed);
    digitalWrite(5,LOW);
    analogWrite(4,leftMotorSpeed);
    digitalWrite(7,LOW);
    analogWrite(6,rightMotorSpeed);
    digitalWrite(8,LOW);
    analogWrite(9,rightMotorSpeed);
    
   

}

void right(int Speed,int delay_time)
{
  digitalWrite(3,LOW);
     analogWrite(2,Speed);
     digitalWrite(5,LOW);
     analogWrite(4,Speed);
     digitalWrite(6,LOW);
     analogWrite(7,Speed);
     digitalWrite(9,LOW);
     analogWrite(8,Speed);
     delay(delay_time);
     
     motor_stop();
}

void left(int Speed,int delay_time)
{
     digitalWrite(2,LOW);
     analogWrite(3,Speed);
     digitalWrite(4,LOW);
     analogWrite(5,Speed);
     digitalWrite(7,LOW);
     analogWrite(6,Speed);
     digitalWrite(8,LOW);
     analogWrite(9,Speed);
     delay(delay_time);
     
     motor_stop();
}

void motor_stop()
{
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
}



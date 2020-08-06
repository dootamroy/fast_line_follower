void run_extra(int Speed,int delay_time)
{
    
    digitalWrite(3,LOW);
    analogWrite(2,Speed);
    digitalWrite(5,LOW);
    analogWrite(4,Speed);
    digitalWrite(7,LOW);
    analogWrite(6,Speed);
    digitalWrite(8,LOW);
    analogWrite(9,Speed);
    
    delay(delay_time);

     motor_stop();
}


void back(int Speed,int delay_time)
{
    digitalWrite(2,LOW);
    analogWrite(3,Speed);
    digitalWrite(4,LOW);
    analogWrite(5,Speed);
    digitalWrite(6,LOW);
    analogWrite(7,Speed);
    digitalWrite(9,LOW);
    analogWrite(8,Speed);
    
    delay(delay_time);
    
    //motor_stop();
}


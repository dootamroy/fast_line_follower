void u_turn(int Speed,int delay_time)
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
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW); 
}


void switch_option()
{
  int key[3];          ///..........key[3]->reset (temporary)...........///
  int key_pin=22;


  for(int q=0;q<4;q++)
  {
    key[q]=digitalRead(key_pin);
    if(key[q]==HIGH && q==0 && (sw_count==1 || sw_count==2))      //pid set.
    {
      if(sw_count==2)
      {
      sw_count=1;
      led();
      }
      else
      {
      sw_count=2;
      led();
      }

      delay(40);
    }

                       if(key[q]==HIGH && q==1 && sw_count==2)  //key 2.   kp.
                       {
                        kp++;
                        delay(10);
                       }
                       if(key[q]==HIGH && q==2 && sw_count==2)  //key 3.   ki.
                       {
                        ki+=0.02;
                        delay(10);
                       } 
                       if(key[q]==HIGH && q==3 && sw_count==2)  //key 4.   kd.
                       {
                        kd++;
                        delay(10);
                       }

  if(key[q]==HIGH && q==1 && (sw_count==1 || sw_count==3))   //SENSOR MASTER CALIB.//
  {
    if(sw_count==3)
      {
      sw_count=1;
      led();
      }
      else
      {
      sw_count=3;
      led();
      }
      delay(40);
  }

                      if(key[q]==HIGH && q==0 && sw_count==3)  //key 1.   ///select   SENSOR!!!.
                       {
                          sw_count_sensor++;
                          if(sw_count_sensor>8)
                             sw_count_sensor=0;
                             
                          delay(40);   
                          
                       }
                       if(key[q]==HIGH && q==2 && sw_count==3)  //key 3.   ///increase.
                       {
                         mid[sw_count_sensor]+=3;
                       } 
                       if(key[q]==HIGH && q==3 && sw_count==3)  //key 4.   ///decrease.
                       {
                         mid[sw_count_sensor]-=3;
                       }

  if(key[q]==HIGH && q==3 && (sw_count==1 || sw_count==4))   //KEY 4.  MOTOR START/STOP........START MAZE............//
  {
    if(sw_count==4)
      {
      sw_count=1;
      }
      else
      {
      sw_count=4;
      delay(300);
      led();
      delay(150);
      led();
      delay(150);
      led();
      }
      
  }

 if(key[q]==HIGH && q==2 && (sw_count==1))   //KEY 3. reset pid...........//
  {
    
    kp=kd=ki=0;
    
      led();
      delay(100);
      led();
  }
  
     
    key_pin+=2;
  }

  
}


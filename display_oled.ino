void display_oled()
{
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);

///...................................................PID..............................................///

  display.setCursor(2,2);
  display.println("Kp: ");
  display.setCursor(20,2);
  display.println(kp);
  
  display.setCursor(36,2);
  display.println("Ki: ");
  display.setCursor(54,2);
  display.println(ki);
  
  display.setCursor(88,2);
  display.println("Kd: ");
  display.setCursor(110,2);
  display.println(kd);
  
 ///.................................................................................................../// 


  display.setCursor(0,10);   //..................................line......................................//
  display.println("---------------------");


  display.setTextColor(BLACK,WHITE);
  display.setCursor(25,16);
  display.println(val[8]);
  display.setTextColor(WHITE);
  
  display.setCursor(35,16);
  display.println(val[7]);
  display.setCursor(45,16);
  display.println(val[6]);
  display.setCursor(55,16);
  display.println(val[5]);
  display.setCursor(65,16);
  display.println(val[4]);
  display.setCursor(75,16);
  display.println(val[3]);
  display.setCursor(85,16);
  display.println(val[2]);
  display.setCursor(95,16);
  display.println(val[1]);

  display.setTextColor(BLACK,WHITE);
  display.setCursor(105,16);
  display.println(val[0]);
  display.setTextColor(WHITE);



  display.setCursor(0,24);   //..................................line......................................//
  display.println("---------------------");


  display.setCursor(10,30);
  display.println("MODE: ");                 ///MODE.///
  display.setCursor(50,30);
           if(mode=='F')
           display.println("FOLLOW_LINE");
           else if(mode=='O')
           display.println("LINE");
           else if(mode=='L')
           display.println("LEFT");
           else if(mode=='R')
           display.println("RIGHT");
           else if(mode=='N')
           display.println("NO LINE");
           else if(mode=='Q')
           display.println("ERROR!!");


  //..........................................................................................................................................................
  
   ///SWITCH OPTION DISPLAY.///
   
  display.setTextColor(BLACK,WHITE);
  if(sw_count==1)
  {
    display.setCursor(90,42);
    display.println("STOP");
  }
  
  if(sw_count==4)
  {
    display.setCursor(90,42);
    display.println("START");

    display.setTextColor(WHITE);
    
    display.setCursor(5,42);
    display.println(T2-T1);
    
    display.setCursor(24,42);
    display.println("ms");
  }

  
  if(sw_count==2)
  {
  display.setCursor(5,42);
  display.println(" PID ");
  }

  if(sw_count==3)
  {
  display.setCursor(30,42);
  display.println(" S:");
  display.setCursor(47,42);
  display.println(sw_count_sensor);

  display.setTextColor(WHITE);

  display.setCursor(60,42);
  display.println("---> ");
  
  display.setCursor(90,42);
  display.println(mid[sw_count_sensor]);
  }

  
  display.setTextColor(WHITE);
 //..........................................................................................................................................................



           
//.....................................................................................................................................................//  

  display.setCursor(10,55);
  display.println("ERROR: ");   ///DISPLAY ERROR VAL.///
  display.setCursor(50,55);
  display.println(error);

  display.setCursor(85,55);   
  display.println("PID:"); 
  display.setCursor(110,55);   
  display.println(PIDvalue);   ///DISPLAY PID VAL.///
//.....................................................................................................................................................//
  
  display.display();
}


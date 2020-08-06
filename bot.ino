#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C
// reset pin not used on 4-pin OLED module
Adafruit_SSD1306 display(-1);  // -1 = no reset pi
// 128 x 64 pixel display
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



int address=0; ///EEPROM ADDRESS.///
int ir[9]={A8,A0,A1,A2,A3,A4,A5,A6,A10};    //Sensor array.

int amax[9],amin[9],mid[9];
//int insert[9],extract[9];   ///EEPROM amax,amin.....///

int val[9];

int T1=0,T2=0,time=0;  int read_ir; 

char mode; int error,lasterror=0;

int kp=7,kd=16; float ki=0.0;   ///PID CONSTANTS.

int P,I,D;
int PIDvalue;   ///PID store location.
int sw_count=1; int sw_count_sensor=0;     //switch count//


    
void setup() 
{

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  
  pinMode(23,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(29,OUTPUT);

  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A8,INPUT);
  pinMode(A10,INPUT);

  /// MOTOR PINS..............................................................................................///
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //.........................................................................................................///


  /// switch pins...........................................................................................///
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  ///.......................................................................................................///

  Serial.begin(9600);

  
  initLED();
  call();

  
}


void loop() 
{
   T1=millis();
   following();
   switch_option();

   pos_pid();

   
   if(sw_count==4)
   {
       switch (mode)
       {
        case 'F': motor();             //follow line.
                  break;
                  
        case 'L': motor_stop();        //left.
                  back(60,100);
                  delay(100);
                  left(60,630);
                  break;
           /*       
        case 'R': //motor_stop();       //right.
                  back(60,150); 
                  following();
                  delay(100);
                  if(mode=='N')
                  {
                    right(60,200);
                  }
                  break;
                  
        case 'N':                       //no_line.
                  //motor_stop();
                  back(60,150);
                  u_turn(60,1600);
                  break;
                  
        case 'O':  motor_stop();       //line.
                   back(60,150);
                   following();
                   delay(100);
                   
                  if(mode=='O')
                  {
                  motor_stop();
                  delay(5000);
                  }
                  else
                  left(60,200);
                  break; 
                              */                                            
       }
   }

   
   else
   {
   motor_stop();
   }

   T2=millis();
   display_oled();
   
}


    


 

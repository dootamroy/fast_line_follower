void pos_pid()
{

   P = error;
   I = error+lasterror ;    ///I+error.
   D = error-lasterror;
   PIDvalue = (kp*P) + (ki*I) + (kd*D);
   lasterror = error;

   if(PIDvalue <= -255)
     { PIDvalue=-255;}
      
   else if(PIDvalue>=255)
     { PIDvalue=255;}
  
}


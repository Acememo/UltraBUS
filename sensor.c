#include <sensor.h>
#use capture(CCP1, input=PIN_C2, capture_rising, stream=RISE)
#use capture(CCP2, input=PIN_C1, capture_falling, stream=FALL)
void main()
{
   set_tris_b(0x00);
   output_B(0x00);
   unsigned int16 Ts=0;
   unsigned int16 Tf=0;
   unsigned int16 Ttotal=0;
   int16 Time;
   float d;
   while(TRUE)
   {  
      output_B(0x00);
      delay_ms(2);
      output_B(0x01);
      delay_ms(10);
      output_B(0x00);
      
      if(get_capture_event(RISE))
         Ts=get_capture_time(RISE);
      if(get_capture_event(FALL)){
         Tf=get_capture_time(FALL);
         Ttotal=Tf-Ts;
      }
      Time=4*Ttotal/4000;
      d=(Time*0.034)/2;
   }

}

#include <expo.h>

void main()
{
   #use capture(CCP1, input=PIN_C1, capture_rising, stream=CAPTURE1)
   #use capture(CCP2, input=PIN_C2, capture_falling, stream=CAPTURE2)

   INT16 x=0;
   INT16 distancia=0;
   unsigned INT16 x1=0;
   CHAR j=0;
   set_tris_b (0b00000000) ;
   set_tris_a (0b000000) ;
   set_tris_e (0b000) ;
   
   WHILE (TRUE)
   {
      output_a(j);
      output_low(pin_e1);
      delay_ms(10);
      output_high(pin_e1);
      delay_ms(10);
      
      IF (get_capture_event (CAPTURE1) == 1)
      x = get_capture_time (CAPTURE1) ;

      IF (get_capture_event (CAPTURE2) == 1)
      {
         x1 = (get_capture_time (CAPTURE2)  - x);
         distancia= x1*0.017;
      }
      
     

      SWITCH (j)
      {
         CASE 0: 
         
            IF (distancia<50)  {output_high(pin_b0);
            delay_ms(10);
            }
            IF (distancia<100)  {output_high(pin_b0);
            delay_ms(10);
            }
            else output_low(pin_b0);
         
         BREAK;
         CASE 1: 
         
            IF (distancia>100)  {output_high(pin_b1);
            delay_ms(10);
            }
            IF (distancia>50)  {output_high(pin_b1);
            delay_ms(10);
            }
            else output_low(pin_b1);
         
         BREAK;
      }
      
      
      output_low(pin_e1);
      j=j+1;
      if(j==2)
         {
            j=0;
         }
         
      
      
   }
}

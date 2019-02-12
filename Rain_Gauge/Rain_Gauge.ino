

#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire.h>

#define F_CPU 12000000UL


int pin = A2;
unsigned int  drops = 0;
 byte buf[4];
//
ISR(ANA_COMP_vect){
	 ACSR &= (0<<ACIE);
  delay(2);
 int pin_h_l = digitalRead(pin);
  if (!pin_h_l)   drops++;
  
  ACSR |= (1<<ACIE);
}


  
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  
  Wire.onReceive(receiveEvent); // register event
  
  	cli();             // disable global interrupts
  	SFIOR |= _BV(ACME);
  	ADCSRA &= ~_BV(ADEN);
  ADMUX = 0b00000010;
  
  ACSR =
  (0<<ACD) |   // Analog Comparator: Enabled
  (1<<ACBG) |   // Analog Comparator Bandgap Select: AIN0 is applied to the positive input
  (0<<ACO) |   // Analog Comparator Output: Off
  (1<<ACI) |   // Analog Comparator Interrupt Flag: Clear Pending Interrupt
  (1<<ACIE) |   // Analog Comparator Interrupt: Enabled
  (0<<ACIC) |   // Analog Comparator Input Capture: Disabled
  (1<<ACIS1) | (1<ACIS0);   // Analog Comparator Interrupt Mode: Comparator Interrupt on Rising Output Edge

  	sei();   // enable global interrupts:
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
	memcpy(buf,&drops, 2);
	buf[2] = Sum(buf,2);
  Wire.write(buf,3); // respond with message of 6 bytes
  // as expected by master
}


void receiveEvent(int howMany) // register event() to reset drops
{
	char c = 0;
	while (Wire.available()) {
		c = Wire.read();
	}
	if( c == 'r') drops = 0;
	
}


byte Sum(byte  *message, int nBytes)
{
	uint8_t  sum = 0;
	

	while (nBytes-- > 0)
	{
		sum += *(message++);
	}
	
	return (sum);

	}   /* Sum() */

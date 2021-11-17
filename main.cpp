/*----------------------------------------------------------------------------
Activity - TIMER AND PWM
 ----------------------------------------
Make an audio player to play a music

Output: PWM Speaker (play the music)

 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "Notes.h"
#include "mbed_wait_api.h"

#define SPEAKER D3

//Define the frequency of basic music notes
#define ut  523.25
#define re  587.33
#define mi  659.26
#define fa  698.46
#define so  783.99
#define la  880.00
#define si  987.77


//Define the beat length (e.g. whole note, half note) 
// playing 4/4 so n = 4, b = 2, c = 8
# define r    1000/1
# define b    1000/2
# define n    1000/4
# define c    1000/8
# define p    375



//Define the musical piece
float note[] = {mi, mi, mi, mi, mi, mi, mi, so, ut, re, mi, fa, fa, fa, fa, fa, mi, mi, mi, mi, re, re, mi, re, so,
                mi, mi, mi, mi, mi, mi, mi, so, ut, re, mi, fa, fa, fa, fa, fa, mi, mi, mi, so, so, fa, re, ut};
int beat[] = {n, n, b, n, n, b, n, n, p, c, r, n, n, p, c, n, n, p, c, n, n, n, n, b, b,
                n, n, b, n, n, b, n, n, p, c, r, n, n, p, c, n, n, p, c, n, n, n, n, r};



//Define the PWM output for the speaker
PwmOut speaker(PB_10);
	

//Define the time ticker
Ticker tick;
	

//variable
static int k;


/*----------------------------------------------------------------------------
 Interrupt Service Routine
 *----------------------------------------------------------------------------*/

//Define the ticker ISR
void timer_ISR(){
    speaker = 0.1; //50% duty cycle - max volume
    for (k = 0; k<49; k++) {
        speaker.period(1/note[k]);
        wait_us(beat[k]*1000);
    }
	/*
	The time ticker ISR will be periodically triggered after every single note
		+ Update the PWM frequency to the next music note
		+ Update beat length for the next music note (reconfigure the tick interrupt time)

	*/
	
		//Write your code here
} 

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	/*
	Initialize the time ticker
  	Sleep and wait for interrupts
	*/
	//Write your code here
	tick.attach(&timer_ISR, 2s);
    ThisThread::sleep_for(5s);
    // speaker.period(1.0/500.0); // 500hz period
    
    // speaker.period(1.0/261.63); // 500hz period
    // speaker = 0.5; //50% duty cycle - max volume
    // ThisThread::sleep_for(1s);
// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
}
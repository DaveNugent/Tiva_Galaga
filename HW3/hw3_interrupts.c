#include "hw3_interrupts.h"

volatile PS2_DIR_t direction;
//*****************************************************************************
// TIMER2 ISR is used to determine when to move the Invader
//*****************************************************************************
void TIMER2A_Handler(void)
{	
    TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER2_BASE;
		if (!contact_edge( direction, SHIP_X_COORD, SHIP_Y_COORD, shipHeightPixels, shipWidthPixels))
		{
			move_image( direction, &SHIP_X_COORD, &SHIP_Y_COORD, shipHeightPixels, shipWidthPixels);//MOVE
			MOVE_SHIP = true;
		}
		
		timer->ICR |= TIMER_ICR_TATOCINT; // clear interupt
}

//*****************************************************************************
// TIMER3 ISR is used to determine when to move the spaceship
//*****************************************************************************
void TIMER3A_Handler(void)
{
		static PS2_DIR_t current_dir = PS2_DIR_CENTER;
    static uint16_t move_count = 0; 
		static PS2_DIR_t next_dir;
    static uint16_t next_count; 
	
	  TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER3_BASE;
	
		move_count = next_count;
		current_dir = next_dir;
	
		if ((move_count > 0) && (!contact_edge( current_dir, INVADER_X_COORD, INVADER_Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels))) {
			next_count--;
			move_image( current_dir, &INVADER_X_COORD, &INVADER_Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels);//MOVE
			MOVE_INVADER = true;
		}
		else { // get new count and dir if count hits 0 or ship hits edge
			next_count = get_new_move_count();
			next_dir = get_new_direction(current_dir);
		}
	
		timer->ICR |= TIMER_ICR_TATOCINT; // clear interupt
    
}

//*****************************************************************************
// TIMER4 ISR is used to trigger the ADC
//*****************************************************************************
void TIMER4A_Handler(void)
{	
		TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER4_BASE;
	
		ADC0 ->ACTSS |= ADC_ACTSS_ASEN2;	// enable Sample sequencer
		ADC0 ->PSSI |= ADC_PSSI_SS2;			// start sample sequencer
		
	
		timer->ICR |= TIMER_ICR_TATOCINT; // clear interupt
}

//*****************************************************************************
// ADC0 SS2 ISR
//*****************************************************************************
void ADC0SS2_Handler(void)
{
	uint16_t x;
	uint16_t y;
	
	ADC0_Type *adc;
	adc = (ADC0_Type *) ADC0;
	
	x = adc->SSFIFO2;
	y = adc->SSFIFO2;
	
	
	
	if(x > 2979){
		direction = PS2_DIR_LEFT;
	}
	else if (x < 1055){
		direction = PS2_DIR_RIGHT;
	}
	else {
		direction = PS2_DIR_CENTER;
	}
	
	adc->ISC |= 0x4; // clear interupt
}

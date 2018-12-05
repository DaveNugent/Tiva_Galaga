#include "hw3_interrupts.h"

volatile DIR_t direction;
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
		static DIR_t current_dir, next_dir;
    static uint16_t move_count = 0; 
	
	  TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER3_BASE;
	
		current_dir = next_dir;
	
		if ((!contact_edge( current_dir, galaga_enemy_X_COORD[0], galaga_enemy_Y_COORD[0], galaga_enemyHeightPixels, galaga_enemyWidthPixels))) {
			move_image( current_dir, &galaga_enemy_X_COORD[0], &galaga_enemy_Y_COORD[0], galaga_enemyHeightPixels, galaga_enemyWidthPixels);//MOVE
			MOVE_INVADER = true;
		}
		else if (current_dir == DIR_RIGHT){ // get new count and dir ship hits edge
			next_dir = DIR_LEFT;
		}
		else{ // get new count and dir ship hits edge
			next_dir = DIR_RIGHT;
		}
	
		timer->ICR |= TIMER_ICR_TATOCINT; // clear interupt
    
}

//*****************************************************************************
// TIMER4 ISR is used to trigger the ADC
//*****************************************************************************
void TIMER4A_Handler(void)
{	
		int16_t x;
		TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER4_BASE;
	
		// ADC0 ->ACTSS |= ADC_ACTSS_ASEN2;	// enable Sample sequencer
		// ADC0 ->PSSI |= ADC_PSSI_SS2;			// start sample sequencer
		x = accel_read_x();	
	if(x > 6000){
		direction = DIR_FAR_LEFT;
	}
	else if (x > 4000){
		direction = DIR_LEFT;
	}
	else if (x < -6000){
		direction = DIR_FAR_RIGHT;
	}
	else if (x < -4000){
		direction = DIR_RIGHT;
	}
	else {
		direction = DIR_CENTER;
	}		
	
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
		direction = DIR_LEFT;
	}
	else if (x < 1055){
		direction = DIR_RIGHT;
	}
	else {
		direction = DIR_CENTER;
	}
	
	adc->ISC |= 0x4; // clear interupt
}

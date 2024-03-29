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
		uint8_t i;
		bool move_line;
	
	  TIMER0_Type *timer;
		timer = (TIMER0_Type *) TIMER3_BASE;
		current_dir = next_dir;
		move_line = false;


		for (i = 0; i < 8; i++){
			if (galaga_enemy_array[i].alive){
				if (contact_edge(current_dir, galaga_enemy_array[i].X_COORD, galaga_enemy_array[i].Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels)) 
					{
						move_line = true;
					}
			}
		}	
	for (i = 0; i < 8; i++){
			if (galaga_enemy_array[i].alive){
				if (move_line) 
					{
					if (current_dir == DIR_RIGHT){ // move down if ship hits wall and change direction
						move_image( DIR_DOWN, &galaga_enemy_array[i].X_COORD, &galaga_enemy_array[i].Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels);//MOVE
						next_dir = DIR_LEFT;
						move_line = true;
					}
					else{ // move down if ship hits wall and change direction
						move_image( DIR_DOWN, &galaga_enemy_array[i].X_COORD, &galaga_enemy_array[i].Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels);//MOVE
						next_dir = DIR_RIGHT;
						move_line = true;
					}
				}
				else{ //keep going if ship doesnt hit wall
					move_image( current_dir, &galaga_enemy_array[i].X_COORD, &galaga_enemy_array[i].Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels);//MOVE
				}
			}
		}
		MOVE_ENEMY = true;
		MOVE_LASER = true;
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

// portF bit 0
void GPIOF_Handler(void)
{	
		GPIOA_Type  *gpioPort;
		uint8_t button_press;
	
		gpioPort = (GPIOA_Type *)GPIOF_BASE;
		read_button(&button_press);

		if (button_press & DOWN_BUTTON_M){
				LASER_COLOR = LCD_COLOR_BLUE;
				FIRE_LASER = true;
		}
		else if (button_press & UP_BUTTON_M){
			LASER_COLOR = LCD_COLOR_CYAN;
			FIRE_LASER = true;
		}
		else if (button_press & LEFT_BUTTON_M){
			LASER_COLOR = LCD_COLOR_WHITE;
			FIRE_LASER = true;
		}
		else if (button_press & RIGHT_BUTTON_M){
			LASER_COLOR = LCD_COLOR_GREEN2;
			FIRE_LASER = true;
		}
		else if(!lp_io_read_pin(SW2_BIT)) {
			//polling technique change to vector
			eeprom_write();
		}
		read_button(&button_press);	
		gpioPort->ICR |= PF0; // clear interupt
		
		//timer->ICR |= TIMER_ICR_TATOCINT; // clear interupt
}

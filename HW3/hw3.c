#include "hw3.h"

volatile uint16_t SHIP_X_COORD = 190;
const uint16_t SHIP_Y_COORD = 20;
volatile uint16_t INVADER_X_COORD = 50;
volatile uint16_t INVADER_Y_COORD = 40;
volatile bool MOVE_INVADER = true;
volatile bool MOVE_SHIP = true;

char STUDENT_NAME[] = "Dave Nugent";

//*****************************************************************************
// If any part of the image would be off the screen if the image
// is moved in the specified direction, return true.  If the image would not
// be in contact with the edge of the screen, return false.
//*****************************************************************************
bool contact_edge(
    volatile PS2_DIR_t direction,
    volatile uint16_t x_coord,
    volatile uint16_t y_coord,
    uint8_t image_height,
    uint8_t image_width
)
{

  //checking to see if image would leave screen
  if ((direction == PS2_DIR_RIGHT) && (x_coord > (COLS - ((image_width + 4)/2)))){
    return true;
  }
  else if ((direction == PS2_DIR_LEFT) && (x_coord <= ((image_width + 2)/2))){
    return true;
  }
	else if ((direction == PS2_DIR_DOWN) && (y_coord >= (ROWS - ((image_height + 2)/2)))){
    return true;
  }
  else if ((direction == PS2_DIR_UP) && (y_coord <= ((image_height + 2)/2))){
    return true;
  }
  else{
    return false; // image can move in dir w/o leaving screen
  }
}

//*****************************************************************************
// Moves the image by one pixel in the provided direction.  The second and
// third parameter should modify the current location of the image (pass by
// reference)
//*****************************************************************************
void move_image(
        volatile PS2_DIR_t direction,
        volatile uint16_t *x_coord,
        volatile uint16_t *y_coord,
        uint8_t image_height,
        uint8_t image_width
)
{
	uint16_t temp;
	switch (direction)
	{
		case PS2_DIR_RIGHT:
			*x_coord = (*x_coord) + 1;
		break;
		
		case PS2_DIR_LEFT:
			*x_coord = (*x_coord) - 1;
		break;
		
		default:
			return;
	}
	return;
}
static bool verify_base_addr(uint32_t base_addr)
{
   switch( base_addr )
   {
     case TIMER0_BASE:
     case TIMER1_BASE:
     case TIMER2_BASE:
     case TIMER3_BASE:
     case TIMER4_BASE:
     case TIMER5_BASE:
     {
       return true;
     }
     default:
     {
       return false;
     }
   }
}

bool countdown_timer(uint32_t base_addr, uint32_t ticks)
{
  TIMER0_Type *timer;

  // Verify the base address.
  if ( ! verify_base_addr(base_addr) )
  {
    return false;
  }

  // Type cast the base address to a TIMER0_Type struct
  timer = (TIMER0_Type *)base_addr;

  // turn off timer
  timer->CTL &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);
//setting period
  timer->TAILR = ticks;
// clearing interupt
  timer->ICR |= TIMER_ICR_TATOCINT;
//setting interupt
  timer->IMR |= TIMER_IMR_TATOIM;

	timer->CTL |= TIMER_CTL_TAEN;
	
  return true;
}

//*****************************************************************************
// Determines is any portion of the two images are overlapping.  An image is
// considered to be overlapping if the two rectangles determined by the image
// height and widths are overlapping.  An overlap occurs even if the area that
// overlaps are portions of the images where the pixels do not display on the
// screen.
//
// If the two images are overlapping, return true.
// If the two images are NOT overlapping, return false.
//*****************************************************************************
bool check_game_over(
        volatile uint16_t ship_x_coord,
        const uint16_t ship_y_coord,
        uint8_t ship_height,
        uint8_t ship_width,
        volatile uint16_t invader_x_coord,
        volatile uint16_t invader_y_coord,
        uint8_t invader_height,
        uint8_t invader_width
)
{
	if (((ship_x_coord + (ship_width/2)) > (invader_x_coord - (invader_width/2))) && ((ship_x_coord + (ship_width/2)) <  (invader_x_coord + (invader_width/2)))){
		if (((ship_y_coord + (ship_height/2)) > (invader_y_coord - (invader_height/2))) && ((ship_y_coord + (ship_height/2)) <  (invader_y_coord + (invader_height/2)))){
			return true;
		}
		else if(((ship_y_coord - (ship_height/2)) > (invader_y_coord - (invader_height/2))) && ((ship_y_coord - (ship_height/2)) <  ((invader_y_coord + (invader_height/2))))){
			return true;
		}
	}
	else if (((ship_x_coord - (ship_width/2)) > (invader_x_coord - (invader_width/2))) && ((ship_x_coord - (ship_width/2)) <  (invader_x_coord + (invader_width/2)))){
		if (((ship_y_coord + (ship_height/2)) > (invader_y_coord - (invader_height/2))) && ((ship_y_coord + (ship_height/2)) <  (invader_y_coord + (invader_height/2)))){
			return true;
		}
		else if(((ship_y_coord - (ship_height/2)) > (invader_y_coord - (invader_height/2))) && ((ship_y_coord - (ship_height/2)) <  (invader_y_coord + (invader_height/2)))){
			return true;
		}
	}
	return false;
}

bool init_adc(  uint32_t adc_base )
{
  ADC0_Type  *myADC;
  uint32_t rcgc_adc_mask;
  uint32_t pr_mask;


  // examine the adc_base.  Verify that it is either ADC0 or ADC1
  // Set the rcgc_adc_mask and pr_mask
  switch (adc_base)
  {
    case ADC0_BASE :
    {

      // set rcgc_adc_mask
      rcgc_adc_mask = SYSCTL_RCGCADC_R0;

      // Set pr_mask
      pr_mask = SYSCTL_PRADC_R0;

      break;
    }
    case ADC1_BASE :
    {
      // set rcgc_adc_mask
      rcgc_adc_mask = SYSCTL_RCGCADC_R1;

      // Set pr_mask
      pr_mask = SYSCTL_PRADC_R1;

      break;
    }

    default:
      return false;
  }

  // Turn on the ADC Clock
  SYSCTL->RCGCADC |= rcgc_adc_mask;

  // Wait for ADCx to become ready
  while( (pr_mask & SYSCTL->PRADC) != pr_mask){}

  return true;
}




bool init_interrupt_adc (uint32_t adc_base){
	
	ADC0_Type *myADC;
	

	if (!init_adc (adc_base)){
		return false;
	}
	
	myADC = (ADC0_Type *)adc_base;
	
	myADC->ACTSS &= ~ADC_ACTSS_ASEN2;
	
	myADC->EMUX &= ~ADC_EMUX_EM2_M;
	
	myADC->EMUX |= ADC_EMUX_EM2_PROCESSOR;
	
	myADC ->SSMUX2 = 0x10; 
	
	myADC ->SAC |= ADC_SAC_AVG_8X;
	
	myADC->SSCTL2 |= (ADC_SSCTL0_IE1 | ADC_SSCTL0_END1);
	
  myADC->ISC |= ADC_ISC_IN2;
	
	myADC->IM |= ADC_IM_MASK2;
	
	myADC->ACTSS |= ADC_ACTSS_ASEN2;

	NVIC_SetPriority(ADC0SS2_IRQn, 3);
	
	NVIC_EnableIRQ (ADC0SS2_IRQn);
	
	return true;
	
}

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void)
{
	
	gpio_enable_port(PS2_GPIO_BASE);
	gpio_config_analog_enable(PS2_GPIO_BASE, PS2_X_DIR_MASK |PS2_Y_DIR_MASK);
	gpio_config_alternate_function(PS2_GPIO_BASE, PS2_X_DIR_MASK |PS2_Y_DIR_MASK);
	
  // Initialize LCD Screen
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);

  // Initialize ADC and Timer used to provide analog data from the PS2
  init_interrupt_adc(ADC0_BASE);

  // Initialize Timer 2
  gp_timer_config_32(TIMER2_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	
	countdown_timer(TIMER2_BASE, 1000000); //20 ms
	NVIC_SetPriority(TIMER2A_IRQn, 0);
	NVIC_EnableIRQ(TIMER2A_IRQn);
	

  // Initialize Timer 3
  gp_timer_config_32(TIMER3_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	countdown_timer (TIMER3_BASE, 500000); //10 ms
	NVIC_SetPriority(TIMER3A_IRQn, 1);
	NVIC_EnableIRQ(TIMER3A_IRQn);
	
	// Initialize Timer 4
  gp_timer_config_32(TIMER4_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	countdown_timer (TIMER4_BASE, 50000); //1 ms
	NVIC_SetPriority(TIMER4A_IRQn, 2);
	NVIC_EnableIRQ(TIMER4A_IRQn);
}

//*****************************************************************************
// Main application for HW3
//
// This function should return after the INVADER and SHIP images are determined
// to overalp.
//
// This function is responsible for calling the lcd_draw_image function that
// will move the SHIP and the INVADER
//*****************************************************************************
void hw3_main(void)
{
    init_hardware();
    hw3_hardware_validate();

	// while the game is not over
	while(!check_game_over(SHIP_X_COORD, SHIP_Y_COORD, shipHeightPixels, shipWidthPixels, 
												 INVADER_X_COORD, INVADER_Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels))
	{
		NVIC_DisableIRQ(TIMER2A_IRQn);
		NVIC_DisableIRQ(TIMER3A_IRQn);
		NVIC_DisableIRQ(TIMER4A_IRQn);
		if (MOVE_INVADER)
		{
			lcd_draw_image(INVADER_X_COORD, galaga_enemyWidthPixels, INVADER_Y_COORD, galaga_enemyHeightPixels, galaga_enemyBitmaps, LCD_COLOR_RED, LCD_COLOR_BLACK);
			MOVE_INVADER = false;
		}
		if (MOVE_SHIP)
		{
			lcd_draw_image(SHIP_X_COORD, shipWidthPixels, SHIP_Y_COORD, shipHeightPixels, shipBitmaps, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
			MOVE_SHIP = false;
		}
		NVIC_EnableIRQ(TIMER2A_IRQn);
		NVIC_EnableIRQ(TIMER3A_IRQn);
		NVIC_EnableIRQ(TIMER4A_IRQn);

	}
		

}

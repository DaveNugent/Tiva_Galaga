#include "hw3.h"

volatile uint16_t SHIP_X_COORD = 190;
volatile uint16_t SHIP_Y_COORD = 270;
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
  if ((direction == PS2_DIR_RIGHT) && (x_coord > (COLS -(image_width/2)))){
    return true;
  }
  else if ((direction == PS2_DIR_LEFT) && (x_coord < (image_width/2))){
    return true;
  }
	else if ((direction == PS2_DIR_DOWN) && (y_coord > (ROWS -(image_height/2)))){
    return true;
  }
  else if ((direction == PS2_DIR_UP) && (y_coord < (image_height/2))){
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
	if ( contact_edge(direction, *x_coord, *y_coord, image_height, image_width)){
		return;
	}
	switch (direction)
	{
		case PS2_DIR_RIGHT:
			*x_coord += 1;
		break;
		
		case PS2_DIR_LEFT:
			*x_coord -= 1;
		break;
				
		case PS2_DIR_UP:
			*x_coord -= 1;
		break;
						
		case PS2_DIR_DOWN:
			*x_coord += 1;
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
        volatile uint16_t ship_y_coord,
        uint8_t ship_height,
        uint8_t ship_width,
        volatile uint16_t invader_x_coord,
        volatile uint16_t invader_y_coord,
        uint8_t invader_height,
        uint8_t invader_width
)
{
	// this will hopefully work bc everything is unsigned
	// so if they are in a different order, it'll just
	// overflow to a huge number and not evaluate to true
	if ((ship_x_coord - invader_x_coord) < ((ship_width + invader_width)/2)){
    return true;
  }
  else if (((invader_x_coord - ship_x_coord) < ((ship_width + invader_width)/2))){
    return true;
  }
	else if ((ship_y_coord - invader_y_coord) < ((ship_height + invader_height)/2)){
    return true;
  }
  else if ((invader_y_coord - ship_y_coord) < ((ship_height + invader_height)/2)){
    return true;
  }
  else{
    return false; // images do not overlap
  }

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
	
	
	if( adc_base == 0)
  {
    return false;
  }
	if (!init_adc (adc_base)){
		return false;
	}
	
	myADC = (ADC0_Type *)adc_base;
	
	myADC->ACTSS &= ~ADC_ACTSS_ASEN2;
	
	myADC->EMUX &= ~ADC_EMUX_EM2_M;
	
	myADC->EMUX |= ADC_EMUX_EM2_PROCESSOR;
	
	myADC->SSCTL2 |= (ADC_SSCTL0_IE1 | ADC_SSCTL0_END1);
	
  myADC->ISC |= 0x4;

  myADC->IM &= 0x0FFF0FFF;

	NVIC_SetPriority(ADC0SS2_IRQn, 3);
	
	NVIC_EnableIRQ (ADC0SS2_IRQn);
	
	myADC->SSMUX2 = 0x10;          // Set the Channel

  myADC->ACTSS |= ADC_ACTSS_ASEN2;  // Enable SS2

  myADC->PSSI   = ADC_PSSI_SS2;     // Start SS2
	
	return true;
	
}

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void)
{
  // Initialize LCD Screen
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);

  // Initialize ADC and Timer used to provide analog data from the PS2
  init_interrupt_adc(ADC0_BASE);

  // Initialize Timer 2
  gp_timer_config_32(TIMER2_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	NVIC_EnableIRQ(TIMER2A_IRQn);
	NVIC_SetPriority(TIMER2A_IRQn, 0);
	countdown_timer(TIMER2_BASE, 100000); //20 ms

  // Initialize Timer 3
  gp_timer_config_32(TIMER3_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	NVIC_EnableIRQ(TIMER3A_IRQn);
	NVIC_SetPriority(TIMER3A_IRQn, 1);
	countdown_timer (TIMER3_BASE, 50000); //10 ms
	
	// Initialize Timer 4
  gp_timer_config_32(TIMER4_BASE, TIMER_TAMR_TAMR_PERIOD, false, true);
	NVIC_EnableIRQ(TIMER2A_IRQn);
	NVIC_SetPriority(TIMER4A_IRQn, 2);
	countdown_timer (TIMER3_BASE, 5000); //1 ms
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

   // ADD CODE BELOW
	// while the game is not over
	while(!check_game_over(SHIP_X_COORD, SHIP_Y_COORD, space_shipHeightPixels, space_shipWidthPixels, 
												 INVADER_X_COORD, INVADER_Y_COORD, invaderHeightPixels, invaderWidthPixels))
	{
	
	}
		

}

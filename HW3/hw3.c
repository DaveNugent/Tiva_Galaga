#include "hw3.h"

volatile uint16_t SHIP_X_COORD = 190;
volatile uint16_t SHIP_Y_COORD = 300;
volatile uint16_t galaga_enemy_X_COORD[] = {50};
volatile uint16_t galaga_enemy_Y_COORD[] = {50};
volatile uint16_t laser_X_COORD[];
volatile uint16_t laser_Y_COORD[];
volatile bool MOVE_INVADER = true;
volatile bool MOVE_SHIP = true;

char STUDENT_NAME[] = "Dave Nugent";

//*****************************************************************************
// If any part of the image would be off the screen if the image
// is moved in the specified direction, return true.  If the image would not
// be in contact with the edge of the screen, return false.
//*****************************************************************************
bool contact_edge(
    volatile DIR_t direction,
    volatile uint16_t x_coord,
    volatile uint16_t y_coord,
    uint8_t image_height,
    uint8_t image_width
)
{

  //checking to see if image would leave screen
  if ((direction == DIR_RIGHT) && (x_coord > (COLS - ((image_width + 4)/2)))){
    return true;
  }
  else if ((direction == DIR_LEFT) && (x_coord <= ((image_width + 2)/2))){
    return true;
  }
	else if ((direction == DIR_FAR_RIGHT) && (x_coord > (COLS - ((image_width + 6)/2)))){
    return true;
  }
  else if ((direction == DIR_FAR_LEFT) && (x_coord <= ((image_width + 4)/2))){
    return true;
	}	
	else if ((direction == DIR_DOWN) && (y_coord > (ROWS - ((image_width + 8)/2)))){
    return true;
  }
  else if ((direction == DIR_UP) && (y_coord <= ((image_height + 4)/2))){
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
        volatile DIR_t direction,
        volatile uint16_t *x_coord,
        volatile uint16_t *y_coord,
        uint8_t image_height,
        uint8_t image_width
)
{
	uint16_t temp;
	switch (direction)
	{
		case DIR_RIGHT:
			*x_coord = (*x_coord) + 1;
		break;
		
		case DIR_LEFT:
			*x_coord = (*x_coord) - 1;
		break;
		
		case DIR_FAR_RIGHT:
			*x_coord = (*x_coord) + 2;
		break;
		
		case DIR_FAR_LEFT:
			*x_coord = (*x_coord) - 2;
		break;
		
		case DIR_UP:
			*y_coord = (*y_coord) - 1;
		break;
		
		case DIR_DOWN:
			*y_coord = (*y_coord) + 4;
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
        volatile uint16_t ship_y_coord,
        uint8_t ship_height,
        uint8_t ship_width,
        volatile uint16_t galaga_enemy_X_COORD[],
        volatile uint16_t galaga_enemy_Y_COORD[],
        uint8_t galaga_enemyHeightPixels,
        uint8_t galaga_enemyWidthPixels
)
{
	if (((ship_x_coord + 5) > (galaga_enemy_X_COORD[0] - 5)) && ((ship_x_coord + 5) <  (galaga_enemy_X_COORD[0] + 5))){
		if (((ship_y_coord + 15) > (galaga_enemy_Y_COORD[0] - 15)) && ((ship_y_coord + 15) <  (galaga_enemy_Y_COORD[0] + 15))){
			return true;
		}
		else if(((ship_y_coord - 15) > (galaga_enemy_Y_COORD[0] - 15)) && ((ship_y_coord - 15) <  ((galaga_enemy_Y_COORD[0] + 15)))){
			return true;
		}
	}
	else if (((ship_x_coord - 5) > (galaga_enemy_X_COORD[0] - 5)) && ((ship_x_coord - 5) <  (galaga_enemy_X_COORD[0] + 5))){
		if (((ship_y_coord + 15) > (galaga_enemy_Y_COORD[0] - 15)) && ((ship_y_coord + 15) <  (galaga_enemy_Y_COORD[0] + 15))){
			return true;
		}
		else if(((ship_y_coord - 15) > (galaga_enemy_Y_COORD[0] - 15)) && ((ship_y_coord - 15) <  (galaga_enemy_Y_COORD[0] + 15))){
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

  // initialize accel
  accel_initialize();

  // initialize push buttons (IO Expander)
  mcp23017_init();
  initialize_buttons();

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
	countdown_timer (TIMER4_BASE, 400000); //8 ms
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
												 galaga_enemy_X_COORD, galaga_enemy_Y_COORD, galaga_enemyHeightPixels, galaga_enemyWidthPixels))
	{
    lcd_draw_image(20, zeroWidthPixels, 15, zeroHeightPixels, zeroBitmaps, LCD_COLOR_RED, LCD_COLOR_BLACK);
		
		NVIC_DisableIRQ(TIMER2A_IRQn);
		NVIC_DisableIRQ(TIMER3A_IRQn);
		NVIC_DisableIRQ(TIMER4A_IRQn);
		if (MOVE_INVADER)
		{
			lcd_draw_image(galaga_enemy_X_COORD[0], galaga_enemyWidthPixels, galaga_enemy_Y_COORD[0], galaga_enemyHeightPixels, galaga_enemyBitmaps, LCD_COLOR_RED, LCD_COLOR_BLACK);
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

#include "eeprom.h"
#define ADDR_START1    0
#define ADDR_START2    80
#define ADDR_START3    160
#define ADDR_START_GAME_DATA    240
#define NUM_BYTES      80

char string1[NUM_BYTES] = "Student 1: Dave Nugent";
char string2[NUM_BYTES] = "Student 2: Carter Steffen";
char string3[NUM_BYTES] = "Team Number: 10";


void eeprom_game_data(void)
{
	uint16_t addr;
  uint8_t values[20];
  uint8_t read_val;
  bool status = true;
  
  for(addr = ADDR_START_GAME_DATA; addr <(ADDR_START_GAME_DATA+NUM_BYTES); addr++)
  {
		//write high score data instead of rand
      values[ addr - ADDR_START_GAME_DATA] = rand();
      printf("Writing %i\n\r",values[addr-ADDR_START_GAME_DATA]);
      eeprom_byte_write(I2C1_BASE,addr, values[addr-ADDR_START_GAME_DATA]);
  }
  
  for(addr = ADDR_START_GAME_DATA; addr <(ADDR_START_GAME_DATA+NUM_BYTES); addr++)
  {
      eeprom_byte_read(I2C1_BASE,addr, &read_val);
      if( read_val != values[addr-ADDR_START_GAME_DATA])
      {
        printf("ERROR: addr: %i write: %i read %i\n\r",addr,values[addr-ADDR_START_GAME_DATA], read_val);
        status = false;
      }
  }
  
  if(status)
  {
    printf("EEPROM Test passed\n\r");
  }
  else
  {
    printf("EEPROM Test failed\n\r");
  }
}

void eeprom_read_board_data(void)
{
	uint16_t addr;
	uint16_t temp;
  uint8_t values[20];
  uint8_t read_val;
	char currChar;
	char line[NUM_BYTES];
  bool status = true;
	int index = 0;
	int numChar1;
	int numChar2;
	int numChar3;
	int i;
 
  for(i = 0; i < 3; i++) {
		index = 0;
		if(i == 1) {
			temp = ADDR_START1;
		} else if(i == 2) {
			temp = ADDR_START2;
		} else {
			temp = ADDR_START3;
		}
		for(addr = temp; addr <(temp+NUM_BYTES); addr++)
		{
				eeprom_byte_read(I2C1_BASE,addr, &read_val);
				currChar = (char)read_val;
				if(currChar == '\0') {
					//end of line
					break;
				} else {
					line[index] = currChar;
					index++;
				}
		}
		if(i == 1) {
			char newstring1[NUM_BYTES];
			strcpy(newstring1, line);
			printf("Reading %s\n\r",newstring1);
		} else if(i == 2) {
			char newstring2[NUM_BYTES];
			strcpy(newstring2, line);
			printf("Reading %s\n\r",newstring2);
		} else {
			char newstring3[NUM_BYTES];
			strcpy(newstring3, line);
			printf("Reading %s\n\r",newstring3);
		}
		
	}
	
}

void eeprom_write(void)
{
	uint16_t addr;
	uint16_t temp;
  uint8_t values[80];
  uint8_t read_val;
  bool status = true;
	int i;
	int idx = 0;
  for(i = 0; i < 3; i++) {
		idx = 0;
		if(i == 1) {
			temp = ADDR_START1;
		} else if(i == 2) {
			temp = ADDR_START2;
		} else {
			temp = ADDR_START3;
		}
		for(addr = temp; addr <(temp+NUM_BYTES); addr++)
		{
			if(i == 1) {
				values[ addr - temp] = string1[idx];	
			} else if(i == 2) {
				values[ addr - temp] = string2[idx];
			} else {
				values[ addr - temp] = string3[idx];
			}
			printf("Writing %i\n\r",values[addr-temp]);
			eeprom_byte_write(I2C1_BASE,addr, values[addr-temp]);
			idx++;				
		}
	}
}

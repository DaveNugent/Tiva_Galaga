#ifndef __HW3_H__
#define __HW3_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "TM4C123.h"
#include "gpio_port.h"
#include "ps2.h"
#include "lcd.h"
#include "timers.h"
#include "hw3_images.h"
#include "hw3_staff.h"
#include "accel.h"
#include "spi.h"
#include "mcp23017.h"
#include "eeprom.h"
#include "serial_debug.h"
#include "launchpad_io.h"

#define ADDR_START1    0
#define ADDR_START2    80
#define ADDR_START3    160
#define ADDR_START_GAME_DATA    240
#define NUM_BYTES      80
#define MAX_LASERS     8

extern volatile uint16_t SHIP_X_COORD;
extern volatile uint16_t SHIP_Y_COORD;
extern volatile bool MOVE_ENEMY;
extern volatile bool MOVE_SHIP;
extern volatile bool MOVE_LASER;
extern char STUDENT_NAME[];



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
);

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
);

// struct for each enemy
typedef struct {
   volatile bool alive;
   volatile uint16_t X_COORD;
   volatile uint16_t Y_COORD;
} galaga_enemy;

// struct for each laser
typedef struct {
	 volatile bool alive;
   volatile uint16_t X_COORD;
   volatile uint16_t Y_COORD;
} laser;

extern volatile laser laser_array[MAX_LASERS];

extern volatile galaga_enemy galaga_enemy_array[8];



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
        volatile uint16_t galaga_enemy_X_COORD,
        volatile uint16_t galaga_enemy_Y_COORD,
        uint8_t galaga_enemyHeightPixels,
        uint8_t galaga_enemyWidthPixels
);

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void);
				
//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************				
void eeprom_game_data(void);

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************				
void eeprom_read_board_data(void);

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************				
void eeprom_write(void);

//*****************************************************************************
// Main application for HW3
//*****************************************************************************
void hw3_main(void);

#endif

        

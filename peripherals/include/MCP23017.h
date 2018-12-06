#ifndef __IO_EXPANDER_H__
#define __IO_EXPANDER_H__


#include <stdint.h>
#include "i2c.h"
#include "gpio_port.h"

#define MCP23017_DEV_ID			0x27

//*****************************************************************************
// Fill out the #defines below to configure which pins are connected to
// the I2C Bus
//*****************************************************************************
#define   IO_EXPANDER_GPIO_BASE         	GPIOA_BASE
#define   IO_EXPANDER_I2C_BASE          	I2C1_BASE
#define   IO_EXPANDER_I2C_SCL_PIN       	PA6
#define   IO_EXPANDER_I2C_SDA_PIN       	PA7
#define   IO_EXPANDER_I2C_SCL_PCTL_M     GPIO_PCTL_PA6_M
#define   IO_EXPANDER_I2C_SCL_PIN_PCTL 	GPIO_PCTL_PA6_I2C1SCL
#define   IO_EXPANDER_I2C_SDA_PCTL_M     GPIO_PCTL_PA7_M
#define   IO_EXPANDER_I2C_SDA_PIN_PCTL  	GPIO_PCTL_PA7_I2C1SDA

//*****************************************************************************
// Writes a single byte of data out to the  MCP24LC32AT IO_EXPANDER.  
//
// Paramters
//    i2c_base:   a valid base address of an I2C peripheral
//
//    address:    16-bit address of the byte being written.  Only the lower
//                12 bits is used by the IO_EXPANDER
//
//    data:       Data written to the IO_EXPANDER.
//
// Returns
// I2C_OK if the byte was written to the IO_EXPANDER.
//*****************************************************************************
i2c_status_t IO_EXPANDER_byte_write
( 
  uint32_t  i2c_base,
  uint16_t  IO_EXPANDERDataAddress,
  uint8_t   data
);

//*****************************************************************************
// Reads a single byte of data from the  MCP24LC32AT IO_EXPANDER.  
//
// Paramters
//    i2c_base:   a valid base address of an I2C peripheral
//
//    address:    16-bit address of the byte being read.  Only the lower
//                12 bits is used by the IO_EXPANDER
//
//    data:       data read from the IO_EXPANDER is returned to a uint8_t pointer.
//
// Returns
// I2C_OK if the byte was read from the IO_EXPANDER.
//*****************************************************************************
i2c_status_t IO_EXPANDER_byte_read
( 
  uint32_t  i2c_base,
  uint16_t  address,
  uint8_t   *data
);

//*****************************************************************************
// Initialize the IO_EXPANDER peripheral
//*****************************************************************************
bool IO_EXPANDER_init(void);


#endif

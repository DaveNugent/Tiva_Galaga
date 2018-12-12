#include "mcp23017.h"

static i2c_status_t IO_expander_byte_write
(
  uint32_t  i2c_base,
  uint8_t  address,
  uint8_t   data
)
{
  i2c_status_t status;
  
  // wait if I2C is Busy
  while (I2CMasterBusy(i2c_base)) {};
	
  // Set address 
	status = i2cSetSlaveAddr(i2c_base, MCP23017_DEV_ID, I2C_WRITE);

  // make sure i2c set correctly
  if (status != I2C_OK) {
    return status;
  }
	
  // Send address
	status = i2cSendByte(i2c_base, address, I2C_MCS_START | I2C_MCS_RUN);

  // make sure address sent correctly
	if (status != I2C_OK){
   return status;
  }
	
	 // Send data
	status = i2cSendByte(i2c_base, data, I2C_MCS_RUN | I2C_MCS_STOP);
	
  return status;
}

// initalize 4 directional buttons
i2c_status_t initialize_buttons(void)
{
	i2c_status_t status;
	
  // set lower 4 bit to pull up bc pressing them shorts to ground
	status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_GPPUB, 0x0F);
  
	if (status != I2C_OK){
   return status;
  }

  	// set GpioB to be an input
	status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_IODIRB, 0xFF);

  // make sure setting to input correctly
	if (status != I2C_OK){
   return status;
  }

	status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_INTCONB, 0xF0);

  if (status != I2C_OK){
   return status;
  }

  status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_DEFVALB, 0x0F);

  if (status != I2C_OK){
   return status;
  }

	// status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_IOCON, 0x00);

  // // error checking
	// if (status != I2C_OK){
  //  return status;
  // }
	

	
  // status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_IOPOLB, 0x0F);
  // if (status != I2C_OK){
  //  return status;
  // }

	
	//set to interupt on change
	status = IO_expander_byte_write(MCP23017_I2C_BASE, MCP23017_GPINTENB, 0xFF);
	
	return status;
}


// read push button data
i2c_status_t read_button(uint8_t *data)
{
  i2c_status_t status;
  
  // wait if i2c is busy
  while (I2CMasterBusy(MCP23017_I2C_BASE)) {};

  // set slave address for write mode
	status = i2cSetSlaveAddr(MCP23017_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
  
  // check address was set correctly
  if (status != I2C_OK) {
    return status;
  }
	// send address
	status = i2cSendByte(MCP23017_I2C_BASE, MCP23017_GPIOB, I2C_MCS_START | I2C_MCS_RUN);
  
  if (status != I2C_OK){
    return status;
  }
	
	// set slave address for read mode
	status = i2cSetSlaveAddr(MCP23017_I2C_BASE, MCP23017_DEV_ID, I2C_READ);
  if (status != I2C_OK) {
    return status;
  }

  // get data from buttons
	status = i2cGetByte(MCP23017_I2C_BASE, data, I2C_MCS_RUN | I2C_MCS_STOP | I2C_MCS_START);
	
	//return 1 byte where buttom 4 bits are active low buttons
  return status;
}


// initalize i2c
bool mcp23017_init(void)
{
  // Configure I2C GPIO pins
  if (!gpio_enable_port(MCP23017_GPIO_BASE)){
     return false;
  }
  
  // Configure SCL 
  if (!gpio_config_digital_enable(MCP23017_GPIO_BASE, MCP23017_I2C_SCL_PIN)) {
    return false;
  }
  if (!gpio_config_alternate_function(MCP23017_GPIO_BASE, MCP23017_I2C_SCL_PIN)) {
    return false;
  }
  if (!gpio_config_port_control(MCP23017_GPIO_BASE, MCP23017_I2C_SCL_PCTL_M, MCP23017_I2C_SCL_PIN_PCTL)) {
    return false;
  }
  
  // Configure SDA 
  if (!gpio_config_digital_enable(MCP23017_GPIO_BASE, MCP23017_I2C_SDA_PIN)) {
    return false;
  }
  if (!gpio_config_open_drain(MCP23017_GPIO_BASE, MCP23017_I2C_SDA_PIN)) {
    return false;
  }
  if (!gpio_config_alternate_function(MCP23017_GPIO_BASE, MCP23017_I2C_SDA_PIN)) {
    return false;
  }
  if (!gpio_config_port_control(MCP23017_GPIO_BASE, MCP23017_I2C_SDA_PCTL_M, MCP23017_I2C_SDA_PIN_PCTL)) {
    return false;
  }
    
  // Initialize the I2C peripheral
  if (initializeI2CMaster(MCP23017_I2C_BASE)!= I2C_OK){
    return false;
  }
  return true;
}

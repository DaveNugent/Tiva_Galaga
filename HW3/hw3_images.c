// Copyright (c) 2015-16, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/* 
**  Image data
*/

#include "hw3_images.h"
/* 
**  Image data for space_ship
*/

// 
//  Image data for ship
// 

// 
//  Image data for ship
// 

const uint8_t shipBitmaps[] =
{
	0x00, 0x00, 0x00, 0x00, //   
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x03, 0x00, 0x00, //               ##              
	0x00, 0x0F, 0xC0, 0x00, //             ######            
	0x00, 0x0F, 0xC0, 0x00, //             ######            
	0x00, 0x0F, 0xC0, 0x00, //             ######            
	0x01, 0x8F, 0xC6, 0x00, //        ##   ######   ##       
	0x01, 0x8F, 0xC6, 0x00, //        ##   ######   ##       
	0x01, 0x8F, 0xC6, 0x00, //        ##   ######   ##       
	0x01, 0x8F, 0xC6, 0x00, //        ##   ######   ##       
	0x01, 0xBF, 0xF6, 0x00, //        ## ########## ##       
	0x01, 0xBF, 0xF6, 0x00, //        ## ########## ##       
	0x21, 0xFF, 0xFE, 0x10, //  #    ################    # 
	0x21, 0xFF, 0xFE, 0x10, //  #    ################    # 
	0x21, 0xFF, 0xFE, 0x10, //  #    ################    # 
	0x21, 0xFF, 0xFE, 0x10, //  #    ################    # 
	0x21, 0xFF, 0xFE, 0x10, //  #    ################    # 
	0x27, 0xFF, 0xFF, 0x90, //  #  ####################  # 
	0x27, 0xFF, 0xFF, 0x90, //  #  ####################  # 
	0x3F, 0xFF, 0xFF, 0xF0, //  ########################## 
	0x3F, 0xFF, 0xFF, 0xF0, //  ########################## 
	0x3E, 0x7F, 0xF9, 0xF0, //  #####  ############  ##### 
	0x3E, 0x7F, 0xF9, 0xF0, //  #####  ############  ##### 
	0x38, 0x73, 0x38, 0x70, //  ###    ###  ##  ###    ### 
	0x38, 0x73, 0x38, 0x70, //  ###    ###  ##  ###    ### 
	0x20, 0x03, 0x00, 0x10, //  #           ##           # 
	0x20, 0x03, 0x00, 0x10, //  #           ##           #
	0x00, 0x00, 0x00, 0x00, //   
};

// Bitmap sizes for ship
const uint8_t shipWidthPixels = 30;
const uint8_t shipHeightPixels = 32;



// 
//  Image data for enemy
// 


const uint8_t galaga_enemyBitmaps[] =
{
	0x00, 0x00, 0x00, 0x00, //                               
	0x00, 0x00, 0x00, 0x00, //                               
	0x0E, 0x00, 0x03, 0xC0, //     ###               ####    
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x80, 0x07, 0xE0, //   #######            ######   
	0x3F, 0x8C, 0xC7, 0xE0, //   #######   ##  ##   ######   
	0x3F, 0x8C, 0xC7, 0xE0, //   #######   ##  ##   ######   
	0x0F, 0xEC, 0xDF, 0xC0, //     ####### ##  ## #######    
	0x0F, 0xE0, 0x1F, 0xC0, //     #######        #######    
	0x0F, 0xE0, 0x1F, 0xC0, //     #######        #######    
	0x3F, 0xE0, 0x1F, 0xE0, //   #########        ########   
	0x3F, 0xE0, 0x1F, 0xE0, //   #########        ########   
	0x03, 0xE0, 0x1F, 0x00, //       #####        #####      
	0x00, 0x63, 0x18, 0x00, //          ##   ##   ##         
	0x00, 0x63, 0x18, 0x00, //          ##   ##   ##         
	0x00, 0x1F, 0xE0, 0x00, //            ########           
	0x00, 0x1F, 0xE0, 0x00, //            ########           
	0x00, 0x7F, 0xF8, 0x00, //          ############         
	0x01, 0xFF, 0xFC, 0x00, //        ###############        
	0x01, 0xFF, 0xFC, 0x00, //        ###############        
	0x00, 0x0C, 0x80, 0x00, //             ##  #             
	0x00, 0x0C, 0x80, 0x00, //             ##  #             
	0x00, 0x0C, 0x80, 0x00, //             ##  #             
	0x00, 0x00, 0x00, 0x00, //                               
	0x00, 0x00, 0x00, 0x00, //                               
};

// Bitmap sizes for galaga_enemy
const uint8_t galaga_enemyWidthPixels = 30;
const uint8_t galaga_enemyHeightPixels = 30;

const uint8_t laser[] =
{
	0x00, // 
	0x60, // ##
	0x60, // ##
	0x60, // ##
	0x60, // ##
	0x00  //
};
 //Bitmap sizes for laser
const uint8_t laserHeight = 6;
const uint8_t laserWidth = 4;

const uint8_t zeroBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x70, 0x00, //          ###           
	0x01, 0xFE, 0x00, //        ########        
	0x03, 0xFF, 0x00, //       ##########       
	0x03, 0xFF, 0x00, //       ##########       
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x0F, 0x87, 0xC0, //     #####    #####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x87, 0xC0, //     #####    #####     
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0xFF, 0x00, //      ###########       
	0x03, 0xFF, 0x00, //       ##########       
	0x01, 0xFE, 0x00, //        ########        
	0x00, 0x78, 0x00, //          ####          
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _0
const uint8_t zeroWidthPixels = 23;
const uint8_t zeroHeightPixels = 30;

const uint8_t oneBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x1C, 0x00, //            ###         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x7C, 0x00, //          #####         
	0x01, 0xFC, 0x00, //        #######         
	0x07, 0xFC, 0x00, //      #########         
	0x07, 0xFC, 0x00, //      #########         
	0x07, 0xBC, 0x00, //      #### ####         
	0x06, 0x3C, 0x00, //      ##   ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _1
const uint8_t oneWidthPixels = 23;
const uint8_t oneHeightPixels = 30;

const uint8_t twoBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x78, 0x00, //          ####          
	0x01, 0xFE, 0x00, //        ########        
	0x07, 0xFF, 0x00, //      ###########       
	0x07, 0xFF, 0x80, //      ############      
	0x0F, 0x87, 0x80, //     #####    ####      
	0x0F, 0x07, 0x80, //     ####     ####      
	0x0F, 0x07, 0x80, //     ####     ####      
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x0F, 0x80, //             #####      
	0x00, 0x1F, 0x00, //            #####       
	0x00, 0x3E, 0x00, //           #####        
	0x00, 0x7E, 0x00, //          ######        
	0x00, 0xFC, 0x00, //         ######         
	0x01, 0xF0, 0x00, //        #####           
	0x03, 0xE0, 0x00, //       #####            
	0x07, 0xC0, 0x00, //      #####             
	0x07, 0xC0, 0x00, //      #####             
	0x0F, 0xFF, 0x80, //     #############      
	0x0F, 0xFF, 0x80, //     #############      
	0x0F, 0xFF, 0x80, //     #############      
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _2
const uint8_t twoWidthPixels = 23;
const uint8_t twoHeightPixels = 30;

const uint8_t threeBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x70, 0x00, //          ###           
	0x01, 0xFE, 0x00, //        ########        
	0x03, 0xFF, 0x00, //       ##########       
	0x07, 0xFF, 0x00, //      ###########       
	0x07, 0x87, 0x80, //      ####    ####      
	0x0F, 0x07, 0x80, //     ####     ####      
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x1F, 0x00, //            #####       
	0x00, 0x3E, 0x00, //           #####        
	0x00, 0x7E, 0x00, //          ######        
	0x00, 0x7F, 0x80, //          ########      
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x03, 0xC0, //               ####     
	0x00, 0x03, 0xC0, //               ####     
	0x01, 0x03, 0xC0, //        #      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x87, 0xC0, //     #####    #####     
	0x07, 0xFF, 0x80, //      ############      
	0x03, 0xFF, 0x00, //       ##########       
	0x01, 0xFE, 0x00, //        ########        
	0x00, 0x78, 0x00, //          ####          
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _3
const uint8_t threeWidthPixels = 23;
const uint8_t threeHeightPixels = 30;

const uint8_t fourBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x1F, 0x00, //            #####       
	0x00, 0x3F, 0x00, //           ######       
	0x00, 0x3F, 0x00, //           ######       
	0x00, 0x7F, 0x00, //          #######       
	0x00, 0xFF, 0x00, //         ########       
	0x00, 0xEF, 0x00, //         ### ####       
	0x01, 0xEF, 0x00, //        #### ####       
	0x03, 0xCF, 0x00, //       ####  ####       
	0x03, 0x8F, 0x00, //       ###   ####       
	0x07, 0x8F, 0x00, //      ####   ####       
	0x0F, 0x0F, 0x00, //     ####    ####       
	0x0E, 0x0F, 0x00, //     ###     ####       
	0x0F, 0xFF, 0xC0, //     ##############     
	0x0F, 0xFF, 0xC0, //     ##############     
	0x0F, 0xFF, 0xC0, //     ##############     
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _4
const uint8_t fourWidthPixels = 23;
const uint8_t fourHeightPixels = 30;

const uint8_t fiveBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x01, 0xFF, 0x80, //        ##########      
	0x03, 0xFF, 0x80, //       ###########      
	0x03, 0xFF, 0x80, //       ###########      
	0x03, 0xC0, 0x00, //       ####             
	0x03, 0xC0, 0x00, //       ####             
	0x03, 0x80, 0x00, //       ###              
	0x03, 0x98, 0x00, //       ###  ##          
	0x07, 0xFF, 0x00, //      ###########       
	0x07, 0xFF, 0x80, //      ############      
	0x07, 0xFF, 0x80, //      ############      
	0x07, 0x87, 0xC0, //      ####    #####     
	0x00, 0x03, 0xC0, //               ####     
	0x00, 0x03, 0xC0, //               ####     
	0x00, 0x03, 0xC0, //               ####     
	0x00, 0x03, 0xC0, //               ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x07, 0x87, 0xC0, //      ####    #####     
	0x07, 0xEF, 0x80, //      ###### #####      
	0x03, 0xFF, 0x00, //       ##########       
	0x01, 0xFE, 0x00, //        ########        
	0x00, 0x78, 0x00, //          ####          
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _5
const uint8_t fiveWidthPixels = 23;
const uint8_t fiveHeightPixels = 30;

const uint8_t sixBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x38, 0x00, //           ###          
	0x00, 0xFF, 0x00, //         ########       
	0x01, 0xFF, 0x80, //        ##########      
	0x03, 0xFF, 0x80, //       ###########      
	0x07, 0xC7, 0xC0, //      #####   #####     
	0x07, 0x83, 0xC0, //      ####     ####     
	0x07, 0x80, 0x00, //      ####              
	0x07, 0x80, 0x00, //      ####              
	0x0F, 0x3E, 0x00, //     ####  #####        
	0x0F, 0xFF, 0x00, //     ############       
	0x0F, 0xFF, 0x80, //     #############      
	0x0F, 0xC7, 0xC0, //     ######   #####     
	0x0F, 0x83, 0xC0, //     #####     ####     
	0x0F, 0x83, 0xC0, //     #####     ####     
	0x0F, 0x83, 0xC0, //     #####     ####     
	0x07, 0x83, 0xC0, //      ####     ####     
	0x07, 0x83, 0xC0, //      ####     ####     
	0x07, 0xC3, 0xC0, //      #####    ####     
	0x03, 0xFF, 0x80, //       ###########      
	0x03, 0xFF, 0x80, //       ###########      
	0x01, 0xFF, 0x00, //        #########       
	0x00, 0x7C, 0x00, //          #####         
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _6
const uint8_t sixWidthPixels = 23;
const uint8_t sixHeightPixels = 30;

const uint8_t sevenBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x0F, 0xFF, 0xC0, //     ##############     
	0x0F, 0xFF, 0xC0, //     ##############     
	0x0F, 0xFF, 0xC0, //     ##############     
	0x00, 0x07, 0x80, //              ####      
	0x00, 0x07, 0x00, //              ###       
	0x00, 0x0F, 0x00, //             ####       
	0x00, 0x1E, 0x00, //            ####        
	0x00, 0x1C, 0x00, //            ###         
	0x00, 0x3C, 0x00, //           ####         
	0x00, 0x38, 0x00, //           ###          
	0x00, 0x78, 0x00, //          ####          
	0x00, 0x78, 0x00, //          ####          
	0x00, 0xF0, 0x00, //         ####           
	0x00, 0xF0, 0x00, //         ####           
	0x00, 0xF0, 0x00, //         ####           
	0x00, 0xE0, 0x00, //         ###            
	0x01, 0xE0, 0x00, //        ####            
	0x01, 0xE0, 0x00, //        ####            
	0x01, 0xE0, 0x00, //        ####            
	0x01, 0xE0, 0x00, //        ####            
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _7
const uint8_t sevenWidthPixels = 23;
const uint8_t sevenHeightPixels = 30;

const uint8_t eightBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x78, 0x00, //          ####          
	0x01, 0xFE, 0x00, //        ########        
	0x03, 0xFF, 0x00, //       ##########       
	0x07, 0xFF, 0x80, //      ############      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x07, 0x87, 0x80, //      ####    ####      
	0x03, 0xCF, 0x00, //       ####  ####       
	0x01, 0xFE, 0x00, //        ########        
	0x01, 0xFE, 0x00, //        ########        
	0x03, 0xFF, 0x00, //       ##########       
	0x07, 0x87, 0x80, //      ####    ####      
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x03, 0xC0, //     ####      ####     
	0x0F, 0x87, 0xC0, //     #####    #####     
	0x07, 0xCF, 0x80, //      #####  #####      
	0x03, 0xFF, 0x00, //       ##########       
	0x01, 0xFE, 0x00, //        ########        
	0x00, 0x78, 0x00, //          ####          
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _8
const uint8_t eightWidthPixels = 23;
const uint8_t eightHeightPixels = 30;

const uint8_t nineBitmaps[] =
{
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x70, 0x00, //          ###           
	0x01, 0xFC, 0x00, //        #######         
	0x03, 0xFF, 0x00, //       ##########       
	0x07, 0xFF, 0x00, //      ###########       
	0x0F, 0x8F, 0x80, //     #####   #####      
	0x0F, 0x07, 0x80, //     ####     ####      
	0x0F, 0x07, 0x80, //     ####     ####      
	0x0F, 0x07, 0xC0, //     ####     #####     
	0x0F, 0x07, 0xC0, //     ####     #####     
	0x0F, 0x07, 0xC0, //     ####     #####     
	0x0F, 0x87, 0xC0, //     #####    #####     
	0x07, 0xFF, 0xC0, //      #############     
	0x03, 0xFF, 0xC0, //       ############     
	0x01, 0xFB, 0xC0, //        ###### ####     
	0x00, 0x07, 0xC0, //              #####     
	0x00, 0x07, 0x80, //              ####      
	0x07, 0x07, 0x80, //      ###     ####      
	0x07, 0x8F, 0x80, //      ####   #####      
	0x07, 0xFF, 0x00, //      ###########       
	0x07, 0xFE, 0x00, //      ##########        
	0x03, 0xFC, 0x00, //       ########         
	0x00, 0xF0, 0x00, //         ####           
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
	0x00, 0x00, 0x00, //                        
};

// Bitmap sizes for _9
const uint8_t nineWidthPixels = 23;
const uint8_t nineHeightPixels = 30;

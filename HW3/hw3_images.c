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

const uint_8 shipBitmaps[] =
{
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
	0x61, 0xFF, 0xFE, 0x18, //  ##    ################    ## 
	0x61, 0xFF, 0xFE, 0x18, //  ##    ################    ## 
	0x61, 0xFF, 0xFE, 0x18, //  ##    ################    ## 
	0x61, 0xFF, 0xFE, 0x18, //  ##    ################    ## 
	0x61, 0xFF, 0xFE, 0x18, //  ##    ################    ## 
	0x67, 0xFF, 0xFF, 0x98, //  ##  ####################  ## 
	0x67, 0xFF, 0xFF, 0x98, //  ##  ####################  ## 
	0x7F, 0xFF, 0xFF, 0xF8, //  ############################ 
	0x7F, 0xFF, 0xFF, 0xF8, //  ############################ 
	0x7E, 0x7F, 0xF9, 0xF8, //  ######  ############  ###### 
	0x7E, 0x7F, 0xF9, 0xF8, //  ######  ############  ###### 
	0x78, 0x73, 0x38, 0x78, //  ####    ###  ##  ###    #### 
	0x78, 0x73, 0x38, 0x78, //  ####    ###  ##  ###    #### 
	0x60, 0x03, 0x00, 0x18, //  ##           ##           ## 
	0x60, 0x03, 0x00, 0x18, //  ##           ##           ## 
};

// Bitmap sizes for ship
const uint_8 shipWidthPixels = 30;
const uint_8 shipHeightPixels = 30;



// 
//  Image data for enemy
// 

const uint8_t galaga_enemyBitmaps[] =
{
	0x00, 0x32, 0x00, 0x00, //           ##  #          
	0x00, 0x32, 0x00, 0x00, //           ##  #          
	0x00, 0x32, 0x00, 0x00, //           ##  #          
	0x07, 0xFF, 0xF0, 0x00, //      ###############     
	0x07, 0xFF, 0xF0, 0x00, //      ###############     
	0x01, 0xFF, 0xE0, 0x00, //        ############      
	0x00, 0x7F, 0x80, 0x00, //          ########        
	0x00, 0x7F, 0x80, 0x00, //          ########        
	0x01, 0x8C, 0x60, 0x00, //        ##   ##   ##      
	0x01, 0x8C, 0x60, 0x00, //        ##   ##   ##      
	0x0F, 0x80, 0x7C, 0x00, //     #####        #####   
	0xFF, 0x80, 0x7F, 0x80, // #########        ########
	0xFF, 0x80, 0x7F, 0x80, // #########        ########
	0x3F, 0x80, 0x7F, 0x00, //   #######        ####### 
	0x3F, 0x80, 0x7F, 0x00, //   #######        ####### 
	0x3F, 0xB2, 0x7F, 0x00, //   ####### ##  #  ####### 
	0xFE, 0x32, 0x1F, 0x80, // #######   ##  #    ######
	0xFE, 0x32, 0x1F, 0x80, // #######   ##  #    ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0xFE, 0x00, 0x1F, 0x80, // #######            ######
	0x38, 0x00, 0x0F, 0x00, //   ###               #### 
};

// Bitmap sizes for enemy
const uint8_t galaga_enemyWidthPixels = 32;
const uint8_t galaga_enemyHeightPixels = 26;







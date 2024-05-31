//
// Created by Vadim on 29.05.2024.
//

#ifndef DFPLAYER_DFPLAYER_H
#define DFPLAYER_DFPLAYER_H

#include "main.h"
#include "usart.h"

#define UART_DFP         &huart1
#define delay(ms)       HAL_Delay(ms)

#define DFPLAYER_SEND_LENGTH 10

#define Busy 1

#define Header 0
#define Version 1
#define Length 2
#define Command 3
#define ACK 4
#define Parameter_MSB 5
#define Parameter_LSB 6
#define CheckSum_MSB 7
#define CheckSum_LSB 8
#define End 9

#define COMMAND_PLAY        0x0F
#define COMMAND_SET_VOLUME  0x06
#define COMMAND_SET_GAIN    0x10
#define COMMAND_SET_EQ      0x07

#define PLAY_TRACK(dir,file)    COMMAND_PLAY,dir*256 + file
#define SET_VOLUME(volume)      COMMAND_SET_VOLUME,volume
#define SET_GAIN(gain)          COMMAND_SET_GAIN,256 + gain
#define SET_EQ(eq)              COMMAND_SET_EQ,eq

void send_command_DFP(uint8_t command, uint16_t parameter);

#endif //DFPLAYER_DFPLAYER_H
/* примеры
 * send_command_DFP(PLAY_TRACK(1,5));
 * send_command_DFP(SET_GAIN(30));
 * send_command_DFP(SET_EQ(5);
*/



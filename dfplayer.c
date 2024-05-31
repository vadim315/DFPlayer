//
// Created by Vadim on 29.05.2024.
//

#include "dfplayer.h"

uint8_t dfp_buffer[DFPLAYER_SEND_LENGTH] = {0x7E, 0xFF, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF};

uint16_t calculateCheckSum(uint8_t *buffer){
    uint16_t sum = 0;
    for (int i=Version; i < CheckSum_MSB; i++) {
        sum -= buffer[i];
    }
    return sum;
}

void send_command_DFP(uint8_t command, uint16_t parameter){
    uint8_t *buff[2];
    uint16_t crc = 0;
    dfp_buffer[Command] = command;
    buff[0] = (uint8_t *)&parameter;
    dfp_buffer[Parameter_LSB] = *buff[0];
    buff[0] += 1;
    dfp_buffer[Parameter_MSB] = *buff[0];
    crc = calculateCheckSum(&dfp_buffer[0]);
    dfp_buffer[CheckSum_MSB] = (uint8_t)(crc >> 8);
    dfp_buffer[CheckSum_LSB] = (uint8_t)(crc & 0x00FF);
    HAL_UART_Transmit(UART_DFP, &dfp_buffer[0], 10, 10000);
}





































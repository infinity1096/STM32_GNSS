/*
 * GNSS.h
 *
 *  Created on: Jun 14, 2020
 *      Author: yuchen
 */
#include <stdint.h>
#include "stm32f1xx_hal.h"

#ifndef INC_GNSS_H_
#define INC_GNSS_H_

#define MAX_FIELD_SIZE 12
#define NUM_FIELDS 15
#define BUFFER_LENGTH 100

typedef struct{
	int 		UTC_Hour;
	int 		UTC_Min;
	int 		UTC_Second;
	int 		UTC_Millis;

	float 		lat_raw;//ddmm.mmmm
	double 		lat;//decimal in degrees
	char 		North_South;

	double 		lon_raw;//dddmm.mmmm
	double 		lon;//decimal, in degrees
	char 		East_West;

	int 		status;	//0 = invalid

	int 		num_sat; //number of satellites

	float 		HDOP;

	float 		MSL_alt;
	char		MSL_Unit;
	float 		Geoid_Separation;
	char		Geoid_Unit;

	char		checksum[2];
} GNGGA_t;

typedef struct{
	uint8_t current_char;

	uint8_t gnss_buffer[BUFFER_LENGTH];
	uint8_t char_buffer;

	GNGGA_t GNGGA;

} GNSS_t;

void GNSS_callback(UART_HandleTypeDef*);

void GNSS_Init(UART_HandleTypeDef*);

#endif /* INC_GNSS_H_ */

/*
 * ring_buffer.h
 *
 *  Created on: Aug 15, 2024
 *      Author: isabe
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#include <stdint.h>

void ring_buffer_reset();
uint8_t ring_buffer_size(void);
uint8_t ring_buffer_is_full(void);
uint8_t ring_buffer_is_empy(void);
uint8_t right_buffer_ID(uint8_t *data);

void ring_buffer_write(uint8_t data);
uint8_t ring_buffer_read(uint8_t *byte);

#endif /* INC_RING_BUFFER_H_ */

/*
 * ring_buffer.c
 *
 *  Created on: Aug 15, 2024
 *      Author: isabe
 */

#include "ring_buffer.h"



#define capacity (10)
uint8_t ring_buffer[capacity];
uint8_t head_ptr;
uint8_t tail_ptr;
uint8_t is_full;
//uint8_t numberID = '1006964098';
uint8_t numberID[] = {'1','0','0','6','9','6','4','0','9','8'};

/**
 * @ brief Esta función escribe un dato en el buffer circular
 *
 * @ param data: Dato que se va a escribir
 *
 * @ retval Ninguno
 * */
void ring_buffer_write(uint8_t data){
		ring_buffer[head_ptr] = data;
		head_ptr++;

		if (head_ptr >= capacity){ // Si la cabeza llega al final de la memoria
			head_ptr = 0;
		}

		if (is_full != 0 ){ // Si se pierden datos viejos
			tail_ptr += 1;
		}

		if (tail_ptr >= capacity){ // Si la cola llega al final de la memoria
			tail_ptr = 0;
				}

		if (head_ptr == tail_ptr){ // Si la cabeza alcanza la cola
			is_full = 1;
		}
}


/**
 * @ brief Esta función lee un dato en el buffer circular
 *
 * @ param data: Dirección de donde se va a escribir el dato
 *
 * @ retval 1: Hay datos disponibles, 0: No hay datos
 * */
uint8_t ring_buffer_read(uint8_t *byte){

	if( is_full != 0 || head_ptr != tail_ptr ){
		  *byte = ring_buffer[tail_ptr];
		  tail_ptr += 1;

		  if (tail_ptr >= capacity) {
			  tail_ptr = 0;
		  }
		  is_full = 0;

		  return 1; // Buffer con datos
	}
	return 0; //Buffer vacío
}

void ring_buffer_reset(){
	//ring_buffer[capacity] = 0;
	head_ptr = 0;
	tail_ptr = 0;
	is_full = 0;
} ;

uint8_t ring_buffer_size(void){
	uint8_t size = 0;
	if(head_ptr > tail_ptr){
		size = head_ptr - tail_ptr;
	}
	else if(head_ptr < tail_ptr){
			size = capacity - tail_ptr + (head_ptr);
	}else{
		if(is_full == 1){
			size = capacity -1;
		}else{
			size = 0;
		}
	}

	return size;
};

uint8_t ring_buffer_is_full(void){
	if(is_full){
		return 1;
	}else{
		return 0;
	}
};

uint8_t ring_buffer_is_empy(void){
	if(head_ptr == 0 && tail_ptr == 0 && is_full == 0){
		return 1;
	}else{
		return 0;
	}
};

uint8_t right_buffer_ID(uint8_t *data){

	 if ( memcmp(data, numberID, sizeof(numberID)) != 0 ) {
	        return 0;
	 } else {
	       return 1;
	 }
}

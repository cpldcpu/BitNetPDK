/* ---------------------------------------------------
    *  BitNetMCU - Low bit Neural Network Inference on Padauk MCU	
  ---------------------------------------------------- */
  
#include <stdint.h>
#include <pdk/device.h>
#include <pdk/delay.h>
#include "BitNetMCU_model.h"

#include "softuart.h"
#include <easy-pdk/calibrate.h>

#ifdef __SDCC_pdk14
    #define UART_OUTPUT
#endif

void fc_innerloop(uint8_t);
void fc_innerloop_mem(uint8_t);
uint8_t processalllayers( int8_t *activations); 

unsigned char _sdcc_external_startup(void)
{

   	CLKMD = CLKMD_IHRC_DIV2 | CLKMD_ENABLE_IHRC;  // 16/2=8 Mhz main clock
#ifdef __SDCC_pdk14
    PDK_USE_FACTORY_IHRCR_16MHZ();
#endif

	return 0;
}

const int8_t input_data_0[64] = {-6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -5.0, 7.0, -5.0, -6.0, -6.0, -6.0, -6.0, 4.0, 1.0, 17.0, -4.0, -6.0, -6.0, -6.0, -5.0, 18.0, 6.0, 19.0, 3.0, -6.0, -6.0, -6.0, -6.0, 10.0, 19.0, 31.0, 10.0, -6.0, -6.0, -6.0, -6.0, -5.0, 8.0, 23.0, -4.0, -6.0, -6.0, -6.0, -6.0, -6.0, -0.0, 18.0, -5.0, -6.0, -6.0, -6.0, -6.0, -6.0, -6.0, -2.0, -6.0, -6.0, -6.0};
const uint8_t label_0 = 4;
const int8_t input_data_1[64] = {-7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -7.0, -5.0, -3.0, -1.0, -5.0, -7.0, -7.0, -5.0, 12.0, 21.0, 17.0, 31.0, 4.0, -7.0, -7.0, -6.0, 2.0, 1.0, 8.0, 23.0, -4.0, -7.0, -7.0, -7.0, -7.0, -1.0, 23.0, 1.0, -7.0, -7.0, -7.0, -7.0, -6.0, 15.0, 9.0, -7.0, -7.0, -7.0, -7.0, -7.0, 8.0, 24.0, -5.0, -7.0, -7.0, -7.0, -7.0, -6.0, 15.0, 9.0, -7.0, -7.0, -7.0, -7.0};
const uint8_t label_1 = 7;
const int8_t input_data_2[64] = {-5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -3.0, -1.0, -3.0, -5.0, -5.0, -5.0, 3.0, 17.0, 23.0, 22.0, 5.0, -5.0, -5.0, -4.0, 21.0, 31.0, 10.0, -1.0, -5.0, -5.0, -5.0, -5.0, 4.0, 9.0, 15.0, -4.0, -5.0, -5.0, -5.0, -5.0, -5.0, -3.0, 14.0, -4.0, -5.0, -5.0, -5.0, -5.0, -3.0, 11.0, 15.0, -4.0, -5.0, -5.0, -5.0, -5.0, -4.0, 12.0, 8.0, -5.0, -5.0, -5.0};
const uint8_t label_2 = 5;
const int8_t input_data_3[64] = {-7.0, -7.0, -7.0, -7.0, -6.0, -5.0, -7.0, -7.0, -7.0, -7.0, -7.0, 1.0, 24.0, 26.0, -2.0, -7.0, -7.0, -7.0, -0.0, 28.0, 22.0, 30.0, 6.0, -7.0, -7.0, -4.0, 25.0, 20.0, -5.0, 20.0, 13.0, -7.0, -7.0, 8.0, 29.0, -2.0, -6.0, 21.0, 11.0, -7.0, -7.0, 11.0, 31.0, 6.0, 10.0, 28.0, -0.0, -7.0, -7.0, -3.0, 21.0, 30.0, 22.0, 3.0, -7.0, -7.0, -7.0, -7.0, -6.0, -4.0, -6.0, -7.0, -7.0, -7.0};
const uint8_t label_3 = 0;

uint8_t weightChunk;
const uint8_t *weightidx;
uint8_t layer_in1[MAX_N_ACTIVATIONS];
uint8_t layer_in2[MAX_N_ACTIVATIONS];
volatile int16_t sum;
int8_t *activations_idx;
int8_t *output;
int8_t max_val;
int8_t max_pos;

uint8_t processalllayers( int8_t *activations) 
{
    weightidx = (const uint8_t*)L1_weights;
    output = layer_in1;
    for (uint8_t i = 0; i < L1_outgoing_weights; i++) {
        activations_idx = activations;
        fc_innerloop(L1_incoming_weights/4);            
    }

    weightidx = (const uint8_t*)L2_weights;
    output = layer_in2;
    for (uint8_t i = 0; i < L2_outgoing_weights; i++) {
        activations_idx = layer_in1;
        fc_innerloop_mem(L2_incoming_weights/4);            
    }

    weightidx = (const uint8_t*)L3_weights;
    output = layer_in1;
    for (uint8_t i = 0; i < L3_outgoing_weights; i++) {
        activations_idx = layer_in2;
        fc_innerloop_mem(L3_incoming_weights/4);            
    }

    weightidx = (const uint8_t*)L4_weights;
    output = layer_in2;
    max_val = -INT8_MAX;
    max_pos = 127;    

    for (uint8_t i = 0; i < L4_outgoing_weights; i++) {
        activations_idx = layer_in1;
        fc_innerloop_mem(L4_incoming_weights/4);            

		int8_t sum8 = sum;

        if (sum8 > max_val) {
            max_val = sum8;
            max_pos = i;
        }
    }

#ifdef UART_OUTPUT
    output = layer_in2;
    PDK_sendchar('\n');
    PDK_sendchar('>');
    for (uint8_t i = 0; i < 10; i++) {
        PDK_sendhex8(*output++);
        PDK_sendchar(' ');
    }
#endif
    return max_pos;
}

void fc_innerloop(uint8_t loops) {

    sum = 0;
    do  {
       weightChunk = *weightidx++;
__asm   

	mov	a, _activations_idx+0
	mov	p, a
	mov	a, _activations_idx+1
	call	__gptrget   ; in is in a now
	inc	_activations_idx+0
	addc	_activations_idx+1

    t0sn _weightChunk, #6
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #7
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

	mov	a, _activations_idx+0
	mov	p, a
	mov	a, _activations_idx+1
	call	__gptrget   ; in is in a now
	inc	_activations_idx+0
	addc	_activations_idx+1

    t0sn _weightChunk, #4
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #5
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

	mov	a, _activations_idx+0
	mov	p, a
	mov	a, _activations_idx+1
	call	__gptrget   ; in is in a now
	inc	_activations_idx+0
	addc	_activations_idx+1

    t0sn _weightChunk, #2
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #3
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

	mov	a, _activations_idx+0
	mov	p, a
	mov	a, _activations_idx+1
	call	__gptrget   ; in is in a now
	inc	_activations_idx+0
	addc	_activations_idx+1

    t0sn _weightChunk, #0
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #1
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  
__endasm;
    } while (--loops);

    int8_t sum8 = ((uint16_t)sum)>>3;
    sum8 = sum8 < 0 ? 0 : sum8;
    *output++ = sum8;
}

void fc_innerloop_mem(uint8_t loops) {

    sum = 0;
    do  {
       weightChunk = *weightidx++;
__asm   
    idxm  a, _activations_idx
	inc	_activations_idx+0

    t0sn _weightChunk, #6
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #7
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

    idxm  a, _activations_idx
	inc	_activations_idx+0

    t0sn _weightChunk, #4
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #5
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

    idxm  a, _activations_idx
	inc	_activations_idx+0

    t0sn _weightChunk, #2
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #3
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  

    idxm  a, _activations_idx
	inc	_activations_idx+0

    t0sn _weightChunk, #0
    sl     a            ;    if (weightChunk & 0x40) in = in+in;
    t0sn _weightChunk, #1
    neg    a           ;     if (weightChunk & 0x80) in =-in;                    

    add    _sum+0,a
    addc   _sum+1
    sl     a 
    subc   _sum+1  
__endasm;
    } while (--loops);

    int8_t sum8 = ((uint16_t)sum)>>3;
    sum8 = sum8 < 0 ? 0 : sum8;
    *output++ = sum8;
}


void main(void)
{

#ifdef UART_OUTPUT
	PDK_autobaud();			// Adjust baudrate on easypdkprogrammer
#endif

	for (;;) {	
#ifdef UART_OUTPUT
    PDK_sendstring("\nInference...");
    _delay_ms(500);
#endif
    uint8_t prediction;

    prediction=processalllayers(input_data_0);
#ifdef UART_OUTPUT
    PDK_sendstring("\n#1 Predicted: ");
    PDK_sendhex8(prediction);
    PDK_sendstring("\tlabel: ");
    PDK_sendhex8(label_0);
#endif
    prediction=processalllayers(input_data_1);
#ifdef UART_OUTPUT
    PDK_sendstring("\n#2 Predicted: ");
    PDK_sendhex8(prediction);
    PDK_sendstring("\tlabel: ");
    PDK_sendhex8(label_1);
#endif
    prediction=processalllayers(input_data_2);
#ifdef UART_OUTPUT
    PDK_sendstring("\n#3 Predicted: ");
    PDK_sendhex8(prediction);
    PDK_sendstring("\tlabel: ");
    PDK_sendhex8(label_2);
#endif
    prediction=processalllayers(input_data_3);
#ifdef UART_OUTPUT
    PDK_sendstring("\n#4 Predicted: ");
    PDK_sendhex8(prediction);
    PDK_sendstring("\tlabel: ");
    PDK_sendhex8(label_3);
#endif
	}
}

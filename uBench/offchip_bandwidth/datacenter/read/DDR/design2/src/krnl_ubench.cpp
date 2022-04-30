#include "ap_int.h"
#include <inttypes.h>

const int DWIDTH = 512;
#define INTERFACE_WIDTH ap_uint<DWIDTH>
const int BLOCK_SIZE = 2048;

extern "C" {
	void load_in0(INTERFACE_WIDTH* in0_buf, const INTERFACE_WIDTH* in0, const int stride) {

	        for (int i = 0; i < BLOCK_SIZE; i++) {
		#pragma HLS PIPELINE II=1
	            in0_buf[i] = in0[i*stride];
	        }
	}

	void load_in1(INTERFACE_WIDTH* in1_buf, const INTERFACE_WIDTH* in1, const int stride) {

	        for (int i = 0; i < BLOCK_SIZE; i++) {
		#pragma HLS PIPELINE II=1
	            in1_buf[i] = in1[i*stride];
	        }
	}
		
	void load_in2(INTERFACE_WIDTH* in2_buf, const INTERFACE_WIDTH* in2, const int stride) {

	        for (int i = 0; i < BLOCK_SIZE; i++) {
		#pragma HLS PIPELINE II=1
	            in2_buf[i] = in2[i*stride];
	        }
	}

	void load_in3(INTERFACE_WIDTH* in3_buf, const INTERFACE_WIDTH* in3, const int stride) {

	        for (int i = 0; i < BLOCK_SIZE; i++) {
		#pragma HLS PIPELINE II=1
	            in3_buf[i] = in3[i*stride];
	        }
	}

	void krnl_ubench(const INTERFACE_WIDTH* in0, const INTERFACE_WIDTH* in1, 
                         const INTERFACE_WIDTH* in2, const INTERFACE_WIDTH* in3, const int stride) {
	#pragma HLS INTERFACE m_axi port=in0 offset=slave bundle=gmem0   max_read_burst_length=16 
	#pragma HLS INTERFACE m_axi port=in1 offset=slave bundle=gmem1   max_read_burst_length=16 
	#pragma HLS INTERFACE m_axi port=in2 offset=slave bundle=gmem2   max_read_burst_length=16 
	#pragma HLS INTERFACE m_axi port=in3 offset=slave bundle=gmem3   max_read_burst_length=16 
	
	#pragma HLS INTERFACE s_axilite port=in0 bundle=control
	#pragma HLS INTERFACE s_axilite port=in1 bundle=control
	#pragma HLS INTERFACE s_axilite port=in2 bundle=control
	#pragma HLS INTERFACE s_axilite port=in3 bundle=control
	
	#pragma HLS INTERFACE s_axilite port=stride bundle=control
	#pragma HLS INTERFACE s_axilite port=return bundle=control

	INTERFACE_WIDTH in0_buf[BLOCK_SIZE];
	INTERFACE_WIDTH in1_buf[BLOCK_SIZE];
	INTERFACE_WIDTH in2_buf[BLOCK_SIZE];
	INTERFACE_WIDTH in3_buf[BLOCK_SIZE];


	load_in0(in0_buf, in0, stride);
	load_in1(in1_buf, in1, stride);
	load_in2(in2_buf, in2, stride);
	load_in3(in3_buf, in3, stride);
		
	    return;   
	}
}


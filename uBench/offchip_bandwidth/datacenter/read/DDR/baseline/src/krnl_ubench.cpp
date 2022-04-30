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

	void krnl_ubench(const INTERFACE_WIDTH* in0, const int stride) {
	#pragma HLS INTERFACE m_axi port=in0 offset=slave bundle=gmem0   max_read_burst_length=16 
	
	#pragma HLS INTERFACE s_axilite port=in0 bundle=control
	
	#pragma HLS INTERFACE s_axilite port=stride bundle=control
	#pragma HLS INTERFACE s_axilite port=return bundle=control

	INTERFACE_WIDTH in0_buf[BLOCK_SIZE];


	load_in0(in0_buf, in0, stride);
		
	    return;   
	}
}


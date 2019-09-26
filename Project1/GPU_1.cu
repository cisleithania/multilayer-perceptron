#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include "device_launch_parameters.h"
#include "GPU_1.h"
#include "fann.h"
#include "floatfann.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "f2.h"
using namespace std;


__global__ void kernel(fann *ann, fann_type *input, fann_type *b)
{
	int idx = threadIdx.x;
	b = __device__ fann_run(ann, input);
}

void useGPU::adding(fann *ann, fann_type *input, fann_type *b) {
	/*
	int *d_o_1 = 0;
	int *d_two_1 = 0;
	int *d_one_1 = 0;
	int *d_equally_1 = 0;
	int *d_percent_1 = 0;

	cudaMalloc(&d_o_1, sizeof(int));
	cudaMalloc(&d_two_1, sizeof(int));
	cudaMalloc(&d_one_1, sizeof(int));
	cudaMalloc(&d_equally_1, sizeof(int));
	cudaMalloc(&d_percent_1, sizeof(int));
	
	cudaMemcpy(d_o_1, &o_1, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_two_1, &two_1, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_one_1, &one_1, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_equally_1, &equally_1, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_percent_1, &percent_1, sizeof(int), cudaMemcpyHostToDevice);

	testing_1 << <1, 1 >> > (d_o_1, d_one_1, d_two_1, d_equally_1, d_percent_1);

	cudaMemcpy(&o_1, d_o_1, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&two_1, d_two_1, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&one_1, d_one_1, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&equally_1, d_equally_1, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&percent_1, d_percent_1, sizeof(int), cudaMemcpyDeviceToHost);
	*/

	fann *d_ann = 0;
	fann_type *d_input = 0;
	fann_type *d_b = 0;

	cudaMalloc((void**)&d_ann, sizeof(fann));
	cudaMalloc((void**)&d_input, sizeof(fann_type));
	cudaMalloc((void**)&d_b, sizeof(fann_type));

	cudaMemcpy(d_ann, ann, sizeof(fann), cudaMemcpyHostToDevice);
	cudaMemcpy(d_input, input, sizeof(fann_type), cudaMemcpyHostToDevice);
	cudaMemcpy(d_input, b, sizeof(fann_type), cudaMemcpyHostToDevice);

	kernel << <1, 1 >> > (d_ann, d_input, d_b);

	cudaMemcpy(b, d_input, sizeof(fann_type), cudaMemcpyDeviceToHost);
	
	cudaFree(d_ann);
	cudaFree(d_input);
	cudaFree(d_b);
}

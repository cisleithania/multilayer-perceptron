#include "fann.h"
#include "floatfann.h"
#ifndef GPUFUNC_H
#define GPUFUNC_H
class useGPU
{
public:

	void adding (fann *ann, fann_type *input, fann_type *b);

};
#endif
#pragma once

#include "cpu/vision_cpu.h"
#ifdef WITH_CUDA
#include "cuda/vision_cuda.h"
#endif

namespace tv
{

at::Tensor power3(const at::Tensor& input);

int dummy();

// static int dummy_var = dummy();

}


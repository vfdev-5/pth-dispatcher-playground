#pragma once

#include <torch/extension.h>

#include "cpu/vision_cpu.h"
#ifdef WITH_CUDA
#include "cuda/vision_cuda.h"
#endif

namespace tv
{

at::Tensor power3(const at::Tensor& input)
{
  static auto op = c10::Dispatcher::singleton()
                       .findSchemaOrThrow("tv::power3", "")
                       .typed<decltype(power3)>();
  return op.call(input);
}

int dummy();

static int dummy_var = dummy();

}


#include "vision_cuda.h"


at::Tensor power3_cuda(const at::Tensor & input) {
  TORCH_CHECK(input.is_cuda(), "input must be a CUDA tensor");
  return input * input * input;
}

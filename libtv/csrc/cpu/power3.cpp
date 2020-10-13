#include "vision_cpu.h"

at::Tensor power3_cpu(const at::Tensor & input) {
  TORCH_CHECK(input.device().is_cpu(), "input must be a CPU tensor");
  return input * input * input;
}

namespace tv
{

int dummy()
{
  return 12;
}

}
#include <torch/script.h>

#include "power3.h"

using namespace tv;

TORCH_LIBRARY(tv, m) {
  m.def("power3(Tensor other) -> Tensor");
}

TORCH_LIBRARY_IMPL(tv, CPU, m) {
  m.impl("power3", power3_cpu);
}

#ifdef WITH_CUDA
TORCH_LIBRARY_IMPL(tv, CUDA, m) {
  m.impl("power3", power3_cuda);
}
#endif

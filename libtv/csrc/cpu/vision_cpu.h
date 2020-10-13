#pragma once
#include <torch/extension.h>

#define VISION_API

VISION_API at::Tensor power3_cpu(const at::Tensor & input);

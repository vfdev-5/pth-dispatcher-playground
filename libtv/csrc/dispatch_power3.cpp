#include <torch/extension.h>


namespace tv
{

at::Tensor power3(const at::Tensor& input)
{
  static auto op = c10::Dispatcher::singleton()
                       .findSchemaOrThrow("tv::power3", "")
                       .typed<decltype(power3)>();
  return op.call(input);
}

}

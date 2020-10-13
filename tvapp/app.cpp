#include <torch/torch.h>
#include <tv/power3.h>


int main() {

    // std::cout << "dummy var: " << tv::dummy_var << std::endl;
    torch::Tensor input = torch::arange(3);
    auto out = tv::power3(input);
    std::cout << "power3: " << out << std::endl;

    torch::Tensor input_cuda = torch::arange(3).cuda();
    auto out_cuda = tv::power3(input_cuda);
    std::cout << "power3: " << out_cuda << std::endl;

}
# PyTorch Dispatcher playground

- `libtv` mimics version of torchvision's C++ frontend
- `tvapp`, application using `libtv`

## Build in docker

- Run container:
```
docker run -it --network=host -v $PWD:/cpp -w /cpp --shm-size 16G --security-opt seccomp:unconfined pytorch/pytorch:1.6.0-cuda10.1-cudnn7-devel /bin/bash
```

- Install nightly PyTorch
```

```

- Install CMake
```
sh install_cmake.sh
```


- Build `libtv`
```
export TORCH_PATH=$(dirname $(python -c "import torch; print(torch.__file__)"))
mkdir -p /cpp/libtv/bld && cd /cpp/libtv/bld 
cmake .. -DTorch_DIR=$TORCH_PATH/share/cmake/Torch -DWITH_CUDA=on
make install
```

- Build `tvapp`
```
export TORCH_PATH=$(dirname $(python -c "import torch; print(torch.__file__)"))
mkdir -p /cpp/tvapp/bld && cd /cpp/tvapp/bld 
cmake .. -DTorch_DIR=$TORCH_PATH/share/cmake/Torch -DWITH_CUDA=on
make
```
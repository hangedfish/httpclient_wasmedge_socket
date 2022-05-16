# C/C++ HttpClient example using WasmEdge Socket API

Download and extract [wasi-sdk](https://github.com/WebAssembly/wasi-sdk/releases), setup environment variable WASI_SDK_HOME=path/to/wasi-sdk.

note: Because WasmEdge is not compatible with the latest wasi-libc, we need to download and use wasi-sdk-14.

```
$ export WASI_SDK_HOME=path/to/wasi-sdk
$ cmake -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASI_SDK_PREFIX=${WASI_SDK_HOME} -DCMAKE_TOOLCHAIN_FILE=${WASI_SDK_HOME}/share/cmake/wasi-sdk.cmake
$ cmake --build build
```
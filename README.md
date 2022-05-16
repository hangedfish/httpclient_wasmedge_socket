# C/C++ HttpClient example using WasmEdge Socket API

Download and extract [wasi-sdk](https://github.com/WebAssembly/wasi-sdk/releases), setup environment variable WASI_SDK_HOME=path/to/wasi-sdk.

note: Because WasmEdge is not compatible with the latest wasi-libc, we need to download and use wasi-sdk-14.

note: Only supports WasmEdge 0.10.0 and later.

```
$ export WASI_SDK_HOME=path/to/wasi-sdk
$ cmake -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASI_SDK_PREFIX=${WASI_SDK_HOME} -DCMAKE_TOOLCHAIN_FILE=${WASI_SDK_HOME}/share/cmake/wasi-sdk.cmake
$ cmake --build build
$
$ wasmedge --version
wasmedge version 0.10.0-alpha.1
$ wasmedge build/http_get.wasm
[2022-05-16 15:12:01.090] [error] wasmedge_process module not founded.
<!doctype html>
<html>
<head>
    <title>Example Domain</title>
```
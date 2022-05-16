#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if __wasi__
__attribute__((export_name("http_get")))
#else
__attribute__((visibility("default")))
#endif
auto http_get() -> void;

#ifdef __cplusplus
}
#endif
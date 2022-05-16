#include "http_get.h"
#include <array>
#include <iostream>
#include <fetch/fetch.h>

auto http_get() -> void {
  std::array<char, 4096> buf{};
  fetchIO *io = fetchGetURL("http://www.example.com", "4");
  if (io == nullptr) {
    std::cout << "fetchIO null" << std::endl;
    std::cout << "error: " << fetchLastErrString << std::endl;
    return;
  }
  int nbytes = fetchIO_read(io, buf.data(), buf.size());
  fetchIO_close(io);
  std::cout << buf.data() << std::endl;
  std::cout << "done" << std::endl;

}

auto main(int argc, char* argv[]) -> int {
  http_get();
  return 0;
}
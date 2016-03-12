#include <string.h>
#include <unistd.h>
#include "utils.h"

size_t write_to_buf(char *const buf_out, size_t buf_out_sz,
  const char *const buf_in, size_t n, size_t BUFSIZ_OUT) {
  if (n <= buf_out_sz) {
    strncpy(buf_out, buf_in, n);
  } else {
    strncpy(buf_out, buf_in, buf_out_sz);
    write(1, buf_out, BUFSIZ_OUT);
    strncpy(buf_out, buf_in + buf_out_sz, n - buf_out_sz);
  }
}

size_t find_word(const char *const buf, size_t bufsz, char delim,
  size_t *const left, size_t *const right) {
  *left = 0;
  while (*left + 1 < bufsz && buf[*left] == delim) {
    ++(*left);
  }
  *right = *left + 1;
  while (*right < bufsz && buf[*right] != delim) {
    ++(*right);
  }
  if (*right < bufsz && buf[*right] == delim) {
    --(*right);
  }
  return *right - *left - 1;
}

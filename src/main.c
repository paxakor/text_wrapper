#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "config.h"
#include "help.h"
#include "utils.h"

int main(int argc, char const* argv[]) {
  struct Config conf;
  config_init(&conf, argc, argv);
  if (conf.help) {
    printf("%s", help_msg_ru);
    return 0;
  }

  size_t BUFSIZ_IN  = BUFSIZ;
  size_t BUFSIZ_OUT = BUFSIZ;
  if (conf.input != NULL) {
    freopen(conf.input, "r", stdin);
    struct stat file_stat;
    stat(conf.input, &file_stat);
    BUFSIZ_IN = file_stat.st_blksize;
  }
  if (conf.output != NULL) {
    freopen(conf.output, "w", stdout);
    struct stat file_stat;
    stat(conf.output, &file_stat);
    BUFSIZ_OUT = file_stat.st_blksize;
  }

  char *buf_in  = malloc(BUFSIZ_IN);
  char *buf_out = malloc(BUFSIZ_OUT);
  ssize_t read_bytes = 0;
  size_t  iter_in    = 0;
  size_t  iter_out   = 0;
  size_t  line_len   = 0;

  for (size_t i = 0; i < conf.tab; ++i) {
    buf_out[iter_out++] = conf.delim;
  }
  line_len = conf.tab;

  while ((read_bytes = read(0, buf_in, BUFSIZ_IN)) > 0) {
    iter_in = 0;
    while (iter_in < (size_t) read_bytes) {
      while (buf_in[iter_in] == conf.delim || buf_in[iter_in] == conf.nl) {
        ++iter_in;
      }
      char *ptr = memchr(buf_in + iter_in, conf.delim, read_bytes - iter_in);
      char *ptr_nl = memchr(buf_in + iter_in, conf.nl, read_bytes - iter_in);
      if (ptr == NULL && ptr_nl == NULL) {
        ptr = buf_in + read_bytes;
      } else if (ptr == NULL && ptr_nl != NULL) {
        ptr = ptr_nl;
      } else if (ptr_nl != NULL && ptr_nl < ptr) {
        ptr = ptr_nl;
      }
      size_t len = ptr - (buf_in + iter_in);
      if (line_len + len + 1 > conf.len) {
        buf_out[iter_out++] = conf.nl;
        for (size_t i = 0; i < conf.tab; ++i) {
          buf_out[iter_out++] = conf.delim;
        }
        line_len = conf.tab;
      } else if (line_len > conf.tab) {
        buf_out[iter_out++] = conf.delim;
        ++line_len;
      }
      line_len += len;
      if (len < BUFSIZ_OUT - iter_out) {
        memcpy(buf_out + iter_out, buf_in + iter_in, len);
        iter_out += len;
      } else if (len == BUFSIZ_OUT - iter_out) {
        memcpy(buf_out + iter_out, buf_in + iter_in, len);
        write(1, buf_out, BUFSIZ_OUT);
        iter_out = 0;
      } else {
        // I hope, 'BUFSIZ_OUT' would be greater than 'conf.len'. -_-
        size_t rest = BUFSIZ_OUT - iter_out;
        memcpy(buf_out + iter_out, buf_in + iter_in, rest);
        write(1, buf_out, BUFSIZ_OUT);
        memcpy(buf_out, buf_in + iter_in + rest, len - rest);
        iter_out = len - rest;
      }
      iter_in += len + 1;
    }
  }
  write(1, buf_out, iter_out);
  config_deinit(&conf);
  free(buf_in);
  free(buf_out);
  return 0;
}

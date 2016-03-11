#pragma once

#include <stddef.h>
#include <stdbool.h>

struct Config {
  bool help;
  char *input;
  char *output;
  char delim;
  size_t len;
  size_t tab;
};

void config_init(struct Config *conf, size_t argc, char const* argv[]);
void config_deinit(struct Config *conf);

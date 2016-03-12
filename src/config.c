#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

void config_init(struct Config *conf, size_t argc, char const* argv[]) {
  conf->help   = false;
  conf->input  = NULL;
  conf->output = NULL;
  conf->delim  = ' ';
  conf->nl     = '\n';
  conf->len    = 80;
  conf->tab    = 2;

  const char const *params[] = {"-h", "--help", "-i", "-o", "-d", "-l", "-t"};
  const size_t pms_cnt = 7;
  for (size_t i = 0; i < pms_cnt; ++i) {
    for (size_t j = 0; j < argc; ++j) {
      if (!strcmp(params[i], argv[j])) {
        conf->help = (i < 2 || j + 1 >= argc);
        if (conf->help) {
          return;
        }
        switch (i) {
          case 2:
            conf->input = malloc(strlen(argv[j + 1]));
            strcpy(conf->input, argv[j + 1]);
            break;
          case 3:
            conf->output = malloc(strlen(argv[j + 1]));
            strcpy(conf->output, argv[j + 1]);
            break;
          case 4:
            sscanf(argv[j + 1], "%c", &conf->delim);
            break;
          case 5:
            sscanf(argv[j + 1], "%lu", &conf->len);
            break;
          case 6:
            sscanf(argv[j + 1], "%lu", &conf->tab);
            break;
        }
      }
    }
  }
}

void config_deinit(struct Config *conf) {
  free(conf->input);
  free(conf->output);
}

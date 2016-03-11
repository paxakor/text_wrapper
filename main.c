#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "help.h"

int main(int argc, char const* argv[]) {
  struct Config conf;
  config_init(&conf, argc, argv);
  if (conf.help) {
    printf("%s", help_msg_ru);
    return 0;
  }
  if (conf.input != NULL) {
    freopen(conf.input, "r", stdin);
  }
  if (conf.output != NULL) {
    freopen(conf.output, "w", stdout);
  }

  char *buf = malloc(BUFSIZ);
  ssize_t n;
  while ((n = read(0, buf, BUFSIZ)) > 0) {
    write(1, buf, n);
  }
  config_deinit(&conf);
  return 0;
}

/*
  |  _ \ / _ \ / ___|   __ _    ___ __ _| |_    ___| | ___  _ __   ___
  | | | | | | | |  _   / _` |  / __/ _` | __|  / __| |/ _ \| '_ \ / _ \
  | |_| | |_| | |_| | | (_| | | (_| (_| | |_  | (__| | (_) | | | |  __/_
  |____/ \___/ \____|  \__,_|  \___\__,_|\__|  \___|_|\___/|_| |_|\___(_)

  V-0.0.1 - 23/1/2026
  V-0.0.2 - 23/1/2026
  V-0.0.3 - 25/1/2026

  Made by Totoño, written in C, with NeoVim.
 */

#include "dog.c"
#include "dog.h"

// NOTE: Função main() ------------------------
int main(int argc, char *argv[]) {
  if (args_test(argc, argv))
    return EXIT_SUCCESS;
  if (print_file(argc, argv)) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

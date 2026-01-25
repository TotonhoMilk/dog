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

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: implementar o -H, --no-header --> para tirar o cabeçalho.

// NOTE: Protótipo das funções
bool print_version();
bool print_help();
bool set_parameters(char *parameter);
bool args_test(int n, char **arg);
bool print_file(int n, char **arg);
bool print_header(int n, char *name);

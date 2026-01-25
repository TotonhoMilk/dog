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

#include "dog.h"

// NOTE: Flags
bool is_filename = false;
bool is_color = false;
bool is_header = false;

// NOTE: Função para escrever a versão do dog.
bool print_version() {
  FILE *file = fopen("docs/version", "r");
  if (file == NULL) {
    fprintf(stderr, "Falha ao executar o comando 'version'.\n");
    return true;
  }
  char ch;
  while ((ch = fgetc(file)) != EOF)
    putchar(ch);
  fclose(file);
  return false;
}

// NOTE: Função para escrever o ajuda do dog.
bool print_help() {
  FILE *file = fopen("docs/help", "r");
  if (file == NULL) {
    fprintf(stderr, "Falha ao executar o comando.\n");
    return true;
  }
  char ch;
  while ((ch = fgetc(file)) != EOF)
    putchar(ch);
  fclose(file);
  return false;
}

// NOTE: Função para escolher e setar os parâmetreos.
bool set_parameters(char *parameter) {
  if (strcmp(parameter, "-c") == 0 || strcmp(parameter, "--no-color") == 0) {
    is_color = true;
    // printf("\n\n\t\tis_color = true;\n\n\n");
    return false;
  }
  if (strcmp(parameter, "-H") == 0 || strcmp(parameter, "--no-header") == 0) {
    is_header = true;
    return false;
  }
  if (strcmp(parameter, "-h") == 0 || strcmp(parameter, "--help") == 0) {
    print_help();
    return true;
  }
  if (strcmp(parameter, "-v") == 0 || strcmp(parameter, "--version") == 0) {
    print_version();
    return true;
  }
  printf("Parameter '%s' incorrect.\n", parameter);
  return true;
}

// NOTE: Função para testar os parâmetros
bool args_test(int n, char **arg) {
  for (int i = 1; i < n; i++) {
    if (arg[i][0] == '-' && is_filename == false) {
      // printf("Argumento: %-15s --> seta parâmetros\n", arg[i]);
      if (set_parameters(arg[i]))
        return true;
    } else {
      is_filename = true;
    }
    // if (arg[i][0] != '-' && is_filename == true) {
    //   printf("Argumento: %-15s --> nome\n", arg[i]);
    // }
  }
  return false;
}

// NOTE: Função para imprimir o cabeçalho.
bool print_header(int n, char *name) {
  if (is_header == false) {
    if (is_color == false) {
      printf("COLOR\n");
      printf("+-----------------------------------------------------+\n");
      printf("| Filename %2d: %-38s | WOOF! 🐕✨ WOOF!\n", n, name);
      printf("+-----------------------------------------------------+\n");
    } else {
      printf("NO COLOR\n");
      printf("+-----------------------------------------------------+\n");
      printf("| Filename %2d: %-38s | WOOF! 🐕✨ WOOF!\n", n, name);
      printf("+-----------------------------------------------------+\n");
    }
  }
  return false;
}

// NOTE: Função para imprimir os arquivos.
bool print_file(int n, char **arg) {
  // TODO: imprimir o cabeçalho.
  int count_filename = 1;
  for (int i = 1; i < n; i++) {
    if (arg[i][0] == '-') {
      continue;
    }
    FILE *file = fopen(arg[i], "r");
    if (file == NULL) {
      fprintf(stderr, "Falha ao abrir o arquivo '%s'\n", arg[i]);
      return true;
    }
    print_header(count_filename, arg[i]);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
      putchar(ch);
    }
    fclose(file);
    count_filename++;
  }
  return false;
}

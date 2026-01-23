/*
  |  _ \ / _ \ / ___|   __ _    ___ __ _| |_    ___| | ___  _ __   ___
  | | | | | | | |  _   / _` |  / __/ _` | __|  / __| |/ _ \| '_ \ / _ \
  | |_| | |_| | |_| | | (_| | | (_| (_| | |_  | (__| | (_) | | | |  __/_
  |____/ \___/ \____|  \__,_|  \___\__,_|\__|  \___|_|\___/|_| |_|\___(_)

  V-0.0.1 - 23/1/2026
  V-0.0.2 - 23/1/2026

  Made by Totoño in C, with NeoVim.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: Protótipo das funções
void print_version();
void print_help();
int print_file(char *name, int n);

// NOTE: Implementação da função main().
int main(int argc, char *argv[]) {
  if ((strcmp(argv[1], "-V") == 0) || (strcmp(argv[1], "--version") == 0)) {
    print_version();
    return EXIT_SUCCESS;
  }

  if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    print_help();
    return EXIT_SUCCESS;
  }

  for (int i = 1; i < argc; i++) {
    int arquivo = print_file(argv[i], i);
    if (arquivo == 1) {
      return EXIT_FAILURE;
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}

// NOTE: Implementação das função print_file().
int print_file(char *name, int n) {
  printf("+-----------------------------------------------------+\n");
  printf("| Filename %2d: %-38s |\n", n, name);
  printf("+-----------------------------------------------------+\n");

  FILE *file = fopen(name, "r");

  if (file == NULL) {
    fprintf(stderr, "Falha ao abrir o arquivo '%s'\n", name);
    return 1;
  }

  char ch;
  while ((ch = fgetc(file)) != EOF)
    putchar(ch);

  fclose(file);

  return 0;
}

// NOTE: Implementação da função print_version().
void print_version() { printf("dog 0.0.2\n"); }

// NOTE: Implementação da função print_help().
void print_help() {
  printf("A cat(1) clone made by Totoño para toda humanidade.\n\n");
  printf("Usage: dog [FILE]...\n\n");
  printf("Arguments:\n\t[FILE]...\n\t\tFile(s) to print.\n\n");
  printf("Options:\n\t-h, --help\n\t\tPrint help\n\n");
  printf("\t-v, --version\n\t\tPrint version\n\n");
}

// TODO: Implementar cores no terminal.
// TODO: Ajustar o ajuda para cores.
// TODO: Ajustar o README.md no github.

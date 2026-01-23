#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_version();
void print_help();
int print_file(char *name, int n);

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

void print_version() { printf("dog 0.0.2\n"); }

void print_help() {
  printf("A cat(1) clone made by Totoño para toda humanidade.\n\n");
  printf("Usage: dog [FILE]...\n\n");
  printf("Arguments:\n\t[FILE]...\n\t\tFile(s) to print.\n\n");
  printf("Options:\n\t-h, --help\n\t\tPrint help\n\n");
  printf("\t-v, --version\n\t\tPrint version\n\n");
}

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/ascii_dump.h"

int print_ascii(const char *filename){
  unsigned char byte;
  int i;
  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "sorry the file not open cuz: %s\n", strerror(errno));
    return 1;
  }
  while (fread(&byte, sizeof(unsigned char), 1, fp) == 1) {
    if (byte >= 32 && byte <= 126) {
      printf("%c", byte);
    } else {
      printf(".");
    }
  }
  printf("\n");
  fclose(fp);
  return 0;
}

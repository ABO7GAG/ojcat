#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/bindump.h"

int print_binary(const char *filename)
{
  unsigned char byte;
  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "sorry the file not open cuz: %s\n", strerror(errno));
    return 1;
  }
  while (fread(&byte, sizeof(unsigned char), 1, fp) == 1) {
    for (int i = 7; i >= 0; i--) {
      if ((byte >> i) & 1) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf(" ");
  }
  printf("\n");
  fclose(fp);
  return 0;
}

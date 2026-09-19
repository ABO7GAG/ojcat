#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/hexdump.h"

int print_hex(const char *filename)
{
  unsigned char byte;
  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "sorry the file not open cuz: %s\n", strerror(errno));
    return 1;
  }
  while (fread(&byte, sizeof(unsigned char), 1, fp) == 1) {
    printf("0x%02X ", byte);
  }
  printf("\n");
  fclose(fp);
  return 0;
}

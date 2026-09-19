/*
 * ojcat - A lightweight ELF binary inspection tool
 * Copyright (C) 2026 ABO7GAG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
// #include "include/file.h"

uint16_t read_u16(const unsigned char *p){
  return p[0] | ((uint16_t)p[1] << 8); 
}

const char *elf_type_name(uint16_t type)
{
    switch (type) {
        case 0x0000:
            return "ET_NONE";
        case 0x0001:
            return "ET_REL";
        case 0x0002:
            return "ET_EXEC";
        case 0x0003:
            return "ET_DYN";
        case 0x0004:
            return "ET_CORE";
        default:
            return "UNKNOWN";
    }
}

int com(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  unsigned char ELF_MAGIC[] = {0x7F, 0x45, 0x4C, 0x46};
  int status = com(argc, argv);
  unsigned char buffer[64];
  FILE *fp;
  // int i;
  // char file[];
  if (status == 0) { 
    // file = argv[1];
    fp = fopen(argv[1], "rb");
      if (fp != NULL) {
        size_t result = fread(buffer, sizeof(unsigned char), 64, fp);
        if (result != 64) {
          fprintf(stderr, "file not readed probably not \"elf\" %s\n", strerror(errno));
          exit(EXIT_FAILURE);
        } else {
          if (memcmp(buffer, ELF_MAGIC, 4) == 0) {
            printf("your ELF file is [%s]\n", argv[1]);
            printf("Class: %02X\n", buffer[4]);
            printf("Data: %02X\n", buffer[5]);
            printf("Version: %02X\n", buffer[6]);
            printf("OS ABI: %02X\n", buffer[7]);
            printf("ABI Version: %02X\n", buffer[8]);
            uint16_t e_type = read_u16(&buffer[16]);
            printf("Type: %04X (%s)\n", e_type, elf_type_name(e_type));
            fclose(fp);
          } else {
            fprintf(stderr, "sorry but probably this is not an ELF file...\n");
            fclose(fp);
          }
        }
    } else {
      fprintf(stderr, "sorry your file not opened cuz :%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    // fgets(); 
  } else if (status == 1){
    fprintf(stderr, "too many arguments bro...\n");
  } else {
    fprintf(stderr, "write file after run the comand..\n");
  }
  
}

int com(int argc, char *argv[]){
  if (argc == 2) {
    printf("your program is [%s] to read\n", argv[1]);
    return 0;
    // exit(EXIT_SUCCESS);
  } else if (argc > 2) {
    printf("sorry... until now there is one argument.. ojcat <file> just it\n");
    return 1;
  } else {
    printf("write \"ojcat <file> please..\"\n");
    return 3;
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// #include "include/file.h"

int com(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  unsigned char ELF_MAGIC[] = {0x7F, 0x45, 0x4C, 0x46};
  int status = com(argc, argv);
  unsigned char buffer[18];
  FILE *fp;
  // int i;
  // char file[];
  if (status == 0) { 
    // file = argv[1];
    fp = fopen(argv[1], "rb");
      if (fp != NULL) {
        int result = fread(buffer, sizeof(unsigned char), 18, fp);
        if (result != 18) {
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

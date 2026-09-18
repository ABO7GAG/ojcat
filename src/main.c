#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elf_header.h"

int com(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  int status = com(argc, argv);

  if (status == 0) {
    print_elf_header(argv[1]);
  } else if (status == 1) {
    fprintf(stderr, "too many arguments bro...\n");
  } else {
    fprintf(stderr, "write file after run the command..\n");
  }

  return 0;
}

int com(int argc, char *argv[]){
  if (argc == 3) {
    printf("you will see your file with this command %s\n", argv[1]);
    printf("your program is [%s] to read\n", argv[2]);
    return 0;
  } else if (argc > 3) {
    printf("sorry... until now there is one argument.. ojcat <file> just it\n");
    return 1;
  } else if (argc < 2) {
    printf("you shuold run this \"-h\"command to run your code successfully...");
  }

  else {
    printf("write \"ojcat <file> please..\"\n");
    return 3;
  }
  return 0;
}

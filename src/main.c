#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elf_header.h"
#include "../include/args.h"
#include "../include/elf_sections.h"
#include "../include/hexdump.h"
#include <errno.h>

int com(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  int status = com(argc, argv);

  

  if (status == 0) {
    CmdTyps command = parse_command(argc, argv);
    if (command == CMD_HDR) {
      uint64_t phoff;
      uint16_t phnum;
      // get_phdr_info(argv[2], &phoff, &phnum);
      print_elf_header(argv[2], &phoff, &phnum);
    } else if (command == CMD_STS) {
      uint64_t phoff;
      uint16_t phnum;
      get_phdr_info(argv[2], &phoff, &phnum);
      print_section(argv[2], phoff, phnum);
    } else if (command == CMD_HEX) {
      print_hex(argv[2]);
    } else if (command == CMD_BIN) {
      // func to binary command
    } else if (command == CMD_ASC) {
      // func to ascii command
    } else {
      exit(EXIT_FAILURE);
    }
  } else if (status < 0) {
    fprintf(stderr, "too many arguments bro...\n", strerror(errno));
  } else {
    exit(EXIT_FAILURE);
  }

  return 0;
}

int com(int argc, char *argv[]){
  if (argc == 3) {
    printf("you will see your file with this command %s\n", argv[1]);
    printf("your program is [%s] to read\n", argv[2]);
    return 0;
  } else if (argc == 2) {
    printf("sorry... you need to run another argument like this \"ojcat -h <file>\"\n");
    return 1;
  } else if (argc == 1) {
    printf("you shuold run this \"-h\"command to run your code successfully...\n");
    return 2;
  } else if (argc > 3) {
    printf("bro just 3 words to type...\n");
    return 4;
  } 
  else {
    printf("write \"ojcat <file> please..\"\n");
    return 3;
  }
  return 0;
}

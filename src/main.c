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
#include <stdlib.h>
#include <string.h>
#include "../include/elf_header.h"
#include "../include/args.h"
#include "../include/elf_sections.h"
#include "../include/hexdump.h"
#include "../include/bindump.h"
#include "../include/elf_types.h"
#include "../include/ascii_dump.h"
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
      print_elf_header(argv[2], &phoff, &phnum);
    } else if (command == CMD_STS) {
      uint64_t phoff;
      uint16_t phnum;
      get_phdr_info(argv[2], &phoff, &phnum);
      print_section(argv[2], phoff, phnum);
    } else if (command == CMD_HEX) {
      print_hex(argv[2]);
    } else if (command == CMD_BIN) {
      print_binary(argv[2]);
    } else if (command == CMD_ASC) {
      print_ascii(argv[2]);
    } else if (command == CMD_HLP) {
      printf("Usage: ojcat <command> <file>\n\nCommands:\n-h              Print the ELF header information\n-s              Print program headers (sections)\n-x              Print the file as hex\n-b              Print the file as binary\n-a              Print the file as ASCII (with hex-like layout)\n\nExample:\nojcat -h myfile.elf\n");
    } else if (command == CMD_VRN) {
      printf("ojcat - a lightweight ELF binary inspection tool\nVersion 0.8\n\nPart of the Oj project — building low-level systems, security tools,\nand developer utilities from scratch, one piece at a time.\n\nProject: Oj — https:\/\/github.com/AboHgegA\n        AND - https:\/\/codeberg.org/ABO-7GAG/\n\n");
    }
    else {
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
  } else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
    return 0;
  } else if (argc == 2 && strcmp(argv[1], "--version") == 0) {
    return 0;
  } else if (argc == 1) {
    printf("hi... i see you use my tool... type this helpful commands --help --version\n");
    return 2;
  } else if (argc > 3) {
    printf("bro just 3 words to type...\n");
    return 4;
  } 
  return 0;
}

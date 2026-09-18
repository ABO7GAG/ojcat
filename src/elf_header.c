#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include "../include/elf_header.h"

uint16_t read_u16(const unsigned char *p){
  return p[0] | ((uint16_t)p[1] << 8);
}

uint32_t read_u32(const unsigned char *p){
  return p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

uint64_t read_u64(const unsigned char *p){
   return p[0]
     | ((uint64_t)p[1] << 8)
     | ((uint64_t)p[2] << 16)
     | ((uint64_t)p[3] << 24)
     | ((uint64_t)p[4] << 32)
     | ((uint64_t)p[5] << 40)
     | ((uint64_t)p[6] << 48)
     | ((uint64_t)p[7] << 56);
}

const char *elf_type_name(uint16_t type)
{
    switch (type) {
        case 0x0000: return "ET_NONE";
        case 0x0001: return "ET_REL";
        case 0x0002: return "ET_EXEC";
        case 0x0003: return "ET_DYN";
        case 0x0004: return "ET_CORE";
        default: return "UNKNOWN";
    }
}

int print_elf_header(const char *filename)
{
  // unsigned char phdr[56];
  unsigned char ELF_MAGIC[] = {0x7F, 0x45, 0x4C, 0x46};
  unsigned char buffer[64];
  FILE *fp;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "sorry your file not opened cuz :%s\n", strerror(errno));
    return 1;
  }

  size_t result = fread(buffer, sizeof(unsigned char), 64, fp);
  if (result != 64) {
    fprintf(stderr, "file not readed probably not \"elf\" %s\n", strerror(errno));
    fclose(fp);
    return 1;
  }

  if (memcmp(buffer, ELF_MAGIC, 4) != 0) {
    fprintf(stderr, "sorry but probably this is not an ELF file...\n");
    fclose(fp);
    return 1;
  }

  printf("your ELF file is [%s]\n", filename);
  printf("Class: %02X\n", buffer[4]);
  printf("Data: %02X\n", buffer[5]);
  printf("Version: %02X\n", buffer[6]);
  printf("OS ABI: %02X\n", buffer[7]);
  printf("ABI Version: %02X\n", buffer[8]);

  uint16_t e_type = read_u16(&buffer[16]);
  printf("Type: %04X (%s)\n", e_type, elf_type_name(e_type));

  uint16_t e_machine = read_u16(&buffer[18]);
  printf("Machine: %04X \n", e_machine);

  uint32_t e_version = read_u32(&buffer[20]);
  printf("Version: %08X\n", e_version);

  uint64_t e_entry = read_u64(&buffer[24]);
  printf("Entry: %016" PRIX64 "\n", e_entry);

  uint64_t e_phoff = read_u64(&buffer[32]);
  printf("Program Header Offset: %016" PRIX64 "\n", e_phoff);

  uint64_t e_shoff = read_u64(&buffer[40]);
  printf("Section Header Offset: %016" PRIX64 "\n", e_shoff);

  uint32_t e_flags = read_u32(&buffer[48]);
  printf("Flags: %08" PRIX32 "\n", e_flags);

  uint16_t e_ehsize = read_u16(&buffer[52]);
  printf("ELF Header Size: %04" PRIX16 "\n", e_ehsize);

  uint16_t e_phentsize = read_u16(&buffer[54]);
  printf("Program Header Entry Size: %04" PRIX16 "\n", e_phentsize);

  uint16_t e_phnum = read_u16(&buffer[56]);
  printf("Program Header Number: %04" PRIX16 "\n", e_phnum);

  uint16_t e_shentsize = read_u16(&buffer[58]);
  printf("Section Header Entry Size: %04" PRIX16 "\n", e_shentsize);

  uint16_t e_shnum = read_u16(&buffer[60]);
  printf("Section Header Number: %04" PRIX16 "\n", e_shnum);

  uint16_t e_shstrndx = read_u16(&buffer[62]);
  printf("Section Header String Table Index: %04" PRIX16 "\n", e_shstrndx);

  if (fseek(fp, e_phoff, SEEK_SET) != 0) {
    perror("fseek");
    fclose(fp);
    return 1;
  }

  // fread(phdr, sizeof(unsigned char), 56, fp);
  fclose(fp);

  return 0;
}

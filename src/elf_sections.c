#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "../include/elf_header.h"

const char *program_type_name(uint32_t type){
  switch (type){
    case 0x00000000:
      return "PT_NULL";
    case 0x00000001:
      return "PT_LOAD";
    case 0x00000002:
      return "PT_DYNAMIC";
    case 0x00000003:
      return "PT_INTERP";
    case 0x00000004:
      return "PT_NOTE";
    case 0x00000006:
      return "PT_PHDR";
    case 0x00000007:
      return "PT_TLS";
    default:
      return "UNKNOWN";
  }
}

int print_section(const char *filename, uint64_t e_phoff, uint16_t e_phnum)
{
  unsigned char phdr_buffer[56];
  int i;
  
  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "sorry the file not open cuz: %s\n", strerror(errno));
    return 1;
    // exit(EXIT_FAILURE);
  } if (fseek(fp, e_phoff, SEEK_SET) != 0){
    perror("fseek");
    fclose(fp);
    return 1;
  }
  for (i = 0; i < e_phnum; i++) {
   size_t result = fread(phdr_buffer, sizeof(unsigned char), 56, fp);
   if (result != 56) {
     fprintf(stderr, "Err: failed to read program header #%d (file may be corrupted)\n", i);
    fclose(fp);
    return 1;
   }
   printf("Program Header #%d:\n", i);
   uint32_t p_type = read_u32(&phdr_buffer[0]);
   printf("Type: %08X (%s)\n", p_type, program_type_name(p_type));

   uint32_t p_flags = read_u32(&phdr_buffer[4]);
   // printf("Program Header #%d:\n", i);
   printf("Flags: %08X\n", p_flags);

   uint64_t p_offset = read_u64(&phdr_buffer[8]);
   // printf("Program Header #%d:\n", i);
   printf("Offest: %016" PRIX64 "\n", p_offset);

   uint64_t p_vaddr = read_u64(&phdr_buffer[16]);
   // printf("%s\n");
   // printf("Program Header #%d:\n", i);
   printf("Vaddr: %016" PRIX64 "\n", p_vaddr);

   uint64_t p_paddr = read_u64(&phdr_buffer[24]);
   // printf("Program Header #%d:\n", i);
   printf("Paddr: %016" PRIX64 "\n", p_paddr);

   uint64_t p_filesz = read_u64(&phdr_buffer[32]);
   // printf("Program Header #%d:\n", i);
   printf("Filesz: %016" PRIX64 "\n", p_filesz);

   uint64_t p_memsz = read_u64(&phdr_buffer[40]);
   // printf("Program Header #%d:\n", i);
   printf("Memsz: %016" PRIX64 "\n", p_memsz);

   uint64_t p_align = read_u64(&phdr_buffer[48]);
   // printf("Program Header #%d:\n", i);
   printf("Align: %016" PRIX64 "\n", p_align);
  }
  return 0;
}

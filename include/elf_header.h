#ifndef ELF_HEADER_H
#define ELF_HEADER_H
#include <stdint.h>

uint16_t read_u16(const unsigned char *p);
uint32_t read_u32(const unsigned char *p);
uint64_t read_u64(const unsigned char *p);

int get_phdr_info(const char *filename, uint64_t *phoff_out, uint16_t *phnum_out);
int print_elf_header(const char *filename, uint64_t *phoff_out, uint16_t *phnum_out);

#endif

#ifndef ELF_SECTION_H
#define ELF_SECTION_H
#include <stdint.h>

const char *program_type_name(uint32_t type);
int print_section(const char *filename, uint64_t e_phoff, uint16_t e_phnum);

#endif // !ELF_SECTION_H


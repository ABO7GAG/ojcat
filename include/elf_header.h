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

#ifndef ELF_HEADER_H
#define ELF_HEADER_H
#include <stdint.h>

uint16_t read_u16(const unsigned char *p);
uint32_t read_u32(const unsigned char *p);
uint64_t read_u64(const unsigned char *p);

int get_phdr_info(const char *filename, uint64_t *phoff_out, uint16_t *phnum_out);
int print_elf_header(const char *filename, uint64_t *phoff_out, uint16_t *phnum_out);

#endif

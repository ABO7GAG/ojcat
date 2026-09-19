ojcat: src/main.c src/args.c src/elf_header.c src/elf_sections.c src/hexdump.c
	gcc src/main.c src/args.c src/elf_header.c src/elf_sections.c src/hexdump.c -o ojcat -Iinclude

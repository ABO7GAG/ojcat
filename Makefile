ojcat: src/main.c src/args.c src/elf_header.c src/elf_sections.c
	gcc src/main.c src/args.c src/elf_header.c src/elf_sections.c -o ojcat -Iinclude

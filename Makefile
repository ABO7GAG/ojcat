ojcat: src/main.c src/args.c src/elf_header.c src/elf_sections.c src/hexdump.c src/bindump.c src/ascii_dump.c
	gcc src/main.c src/args.c src/elf_header.c src/elf_sections.c src/hexdump.c src/bindump.c src/ascii_dump.c -o ojcat -Iinclude

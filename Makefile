ojcat: src/main.c src/args.c src/elf_header.c
	gcc src/main.c src/args.c src/elf_header.c -o ojcat -Iinclude

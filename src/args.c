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
#include <string.h>
#include "../include/args.h"

CmdTyps parse_command(int argc, char *argv[]){
  if (strcmp(argv[1], "-h") == 0) {
    return CMD_HDR;
  } else if (strcmp(argv[1], "-s") == 0) {
    return CMD_STS;
  } else if (strcmp(argv[1], "-x") == 0) {
    return CMD_HEX;
  } else if (strcmp(argv[1], "-b") == 0) {
    return CMD_BIN;
  } else if (strcmp(argv[1], "-a") == 0) {
    return CMD_ASC;
  } else if (strcmp(argv[1], "--help") == 0) {
    return CMD_HLP;
  } else if (strcmp(argv[1], "--version") == 0) {
    return CMD_VRN;
  }
  else {
    fprintf(stderr, "UNKNOWN ERROR\n available commands is -a -b -x -h -s --help --version\n just it\n");
    return CMD_ERR;
    }
}

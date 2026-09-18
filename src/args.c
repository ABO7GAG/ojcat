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
  } else {
    fprintf(stderr, "UNKNOWN ERROR\n");
    return CMD_ERR;
    }
}

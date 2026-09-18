#include <stdio.h>
#include <string.h>
#include "../include/args.h"

CmdTyps parse_command(int argc, char *argv[]){
  if (strcmp(argv[1], "-h") == 0) {
    return CMD_HDR;
  } else {
    fprintf(stderr, "UNKNOWN ERROR\n");
    return CMD_ERR;
  }
}

//cave18.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave19",
        "south" : ROOMS"cave17"
   	]));
}

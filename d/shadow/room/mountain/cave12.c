//cave12.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave13",
        "south" : ROOMS"cave11"
   	]));
}

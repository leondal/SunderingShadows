//cave13.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave14",
        "south" : ROOMS"cave12"
   	]));
}

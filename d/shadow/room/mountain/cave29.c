//cave29.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "south" : ROOMS"cave30",
        "north" : ROOMS"cave28"
   	]));
}

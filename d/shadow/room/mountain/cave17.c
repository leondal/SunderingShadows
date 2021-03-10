//cave17.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave18",
        "south" : ROOMS"cave16"
   	]));
}

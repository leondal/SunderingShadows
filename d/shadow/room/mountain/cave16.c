//cave16.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave17",
        "south" : ROOMS"cave15"
   	]));
}

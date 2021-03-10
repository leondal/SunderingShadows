//cave37.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave36",
        "east" : ROOMS"cave38"
   	]));
}

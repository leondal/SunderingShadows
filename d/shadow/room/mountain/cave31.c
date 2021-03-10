//cave31.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave30",
        "east" : ROOMS"cave32"
   	]));
}

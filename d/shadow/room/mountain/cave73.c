//cave73.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS"cave72",
        "west" : ROOMS"cave74",
   	]));
}

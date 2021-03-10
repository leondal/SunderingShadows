//cave54.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_exits(([
        "south" : ROOMS"cave52",
        "southwest" : ROOMS"cave51",
        "west" : ROOMS"cave53",
        "northwest" : ROOMS"cave57",
        "north" : ROOMS"cave58",
        "northeast" : ROOMS"cave59",
        "east" : ROOMS"cave55"
   	]));
}

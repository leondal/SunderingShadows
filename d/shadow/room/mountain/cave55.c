//cave55.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the cavern rises "+
       "to the south.\n");
    set_exits(([
        "southwest" : ROOMS"cave52",
        "west" : ROOMS"cave54",
        "northwest" : ROOMS"cave58",
        "north" : ROOMS"cave59",
        "northeast" : ROOMS"cave60",
        "east" : ROOMS"cave56",
   	]));
}

//cave53.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the large cavern rises "+
       "to the west here, but it opens up eastward.\n");
    set_exits(([
        "south" : ROOMS"cave51",
        "southeast" : ROOMS"cave52",
        "north" : ROOMS"cave57",
        "northeast" : ROOMS"cave58",
        "east" : ROOMS"cave54",
   	]));
}

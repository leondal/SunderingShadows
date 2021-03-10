//cave52.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the large cavern rises "+
       "to the east here, but it opens up northward.\n");
    set_exits(([
        "south" : ROOMS"cave50",
        "southwest" : ROOMS"cave49",
        "west" : ROOMS"cave51",
        "north" : ROOMS"cave54",
        "northwest" : ROOMS"cave53",
        "northeast" : ROOMS"cave55"
   	]));
}

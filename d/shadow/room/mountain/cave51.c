//cave51.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the large cavern rises "+
       "to the west here, but it opens up eastward.\n");
    set_exits(([
        "south" : ROOMS"cave49",
        "southeast" : ROOMS"cave50",
        "east" : ROOMS"cave52",
        "north" : ROOMS"cave53",
        "northeast" : ROOMS"cave54"
   	]));
}

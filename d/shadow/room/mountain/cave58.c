//cave58.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the cavern rises "+
       "to the northwest.\n");
    set_exits(([
        "west" : ROOMS"cave57",
        "southwest" : ROOMS"cave53",
        "south" : ROOMS"cave54",
        "southeast" : ROOMS"cave55",
        "east" : ROOMS"cave59",
        "northeast" : ROOMS"cave63",
        "north" : ROOMS"cave62"
   	]));
}

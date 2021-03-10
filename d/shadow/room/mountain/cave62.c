//cave62.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The walls of the cavern rise "+
       "north and east around you.\n");
    set_exits(([
        "southwest" : ROOMS"cave57",
        "south" : ROOMS"cave58",
        "southeast" : ROOMS"cave59",
        "east" : ROOMS"cave63",
   	]));
}

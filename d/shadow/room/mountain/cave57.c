//cave57.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the cavern rises "+
       "to the west and north.\n");
    set_exits(([
        "south" : ROOMS"cave53",
        "southeast" : ROOMS"cave54",
        "east" : ROOMS"cave58",
        "northeast" : ROOMS"cave62",
   	]));
}

//cave63.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The walls of the cavern rise "+
       "to the north.\n");
    set_exits(([
        "west" : ROOMS"cave62",
        "southwest" : ROOMS"cave58",
        "south" : ROOMS"cave59",
        "southeast" : ROOMS"cave60",
        "east" : ROOMS"cave64",
   	]));
}

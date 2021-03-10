//cave64.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The walls of the cavern rise "+
       "to the north and east.  A rough stairway of sorts is "+
       "southeast of here.\n");
    set_exits(([
        "west" : ROOMS"cave63",
        "southwest" : ROOMS"cave59",
        "south" : ROOMS"cave60",
        "southeast" : ROOMS"cave61",
   	]));
}

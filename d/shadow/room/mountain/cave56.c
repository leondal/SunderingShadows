//cave56.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The wall of the cavern rises "+
       "to the south and east.  A rough stairway of sorts is "+
       "northeast of here.\n");
    set_exits(([
        "west" : ROOMS"cave55",
        "northwest" : ROOMS"cave59",
        "north" : ROOMS"cave60",
        "northeast" : ROOMS"cave61",
   	]));
}

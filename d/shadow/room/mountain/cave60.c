//cave60.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"A rough stairway of sorts seems to "+
       "be east of here.\n");
    set_exits(([
        "west" : ROOMS"cave59",
        "southwest" : ROOMS"cave55",
        "south" : ROOMS"cave56",
        "east" : ROOMS"cave61",
        "north" : ROOMS"cave64",
        "northwest" : ROOMS"cave63"
   	]));
}

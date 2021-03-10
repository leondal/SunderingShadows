//cave49.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The large cavern comes to an end here, "+
       "but opens back up northeastward.\n");
    set_exits(([
        "east" : ROOMS"cave50",
        "north" : ROOMS"cave51",
        "northeast" : ROOMS"cave52"
   	]));
}

//cave45.c
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The large cavern comes to an end here, "+
       "but opens back up northward.\n");
    set_exits(([
        "west" : ROOMS"cave49",
        "north" : ROOMS"cave52",
        "northwest" : ROOMS"cave51"
   	]));
}

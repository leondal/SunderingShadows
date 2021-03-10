//cave76.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"There seems to be a hole in the "+
       "floor further south.\n");
    set_exits(([
        "north" : ROOMS"cave75",
        "south" : ROOMS"cave77",
   	]));
}

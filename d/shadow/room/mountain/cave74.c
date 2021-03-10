//cave74.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS"cave73",
        "west" : ROOMS"cave75",
   	]));
}

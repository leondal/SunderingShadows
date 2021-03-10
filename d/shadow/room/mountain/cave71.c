//cave71.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave70",
        "southwest" : ROOMS"cave72",
   	]));
}

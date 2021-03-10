//cave70.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "northwest" : ROOMS"cave69",
        "south" : ROOMS"cave71",
   	]));
}

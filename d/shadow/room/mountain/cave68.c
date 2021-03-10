//cave68.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"cave67",
        "east" : ROOMS"cave69",
   	]));
}

//cave69.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave68",
        "southeast" : ROOMS"cave70",
   	]));
}

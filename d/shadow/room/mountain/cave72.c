//cave72.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "northeast" : ROOMS"cave71",
        "west" : ROOMS"cave73",
   	]));
}

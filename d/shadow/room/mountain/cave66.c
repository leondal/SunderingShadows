//cave66.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"cave65",
        "northeast" : ROOMS"cave67",
   	]));
}

//cave67.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"cave66",
        "northeast" : ROOMS"cave68",
   	]));
}

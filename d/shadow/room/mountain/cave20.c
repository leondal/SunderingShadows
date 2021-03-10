//cave20.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS"cave21",
        "west" : ROOMS"cave15"
   	]));

}

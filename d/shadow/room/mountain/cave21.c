//cave21.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS"cave22",
        "west" : ROOMS"cave20"
   	]));
}

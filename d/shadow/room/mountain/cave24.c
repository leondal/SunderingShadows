//cave24.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "south" : ROOMS"cave22",
        "north" : ROOMS"cave25"
   	]));

}

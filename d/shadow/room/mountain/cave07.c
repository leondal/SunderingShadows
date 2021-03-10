//cave07.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"cave08",
        "east" : ROOMS"cave06"
   	]));

}

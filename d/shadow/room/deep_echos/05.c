//05.c  inherits from 01 like many others

#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"10",
        "east"  : ROOMS"06",
        "west"  : ROOMS"04"
        ]));
}

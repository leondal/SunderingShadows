//02.c  inherits from 01 like many others

#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
        "south" : ROOMS"08",
        "west"  : ROOMS"01",
        "east" : ROOMS"03"
        ]));
}

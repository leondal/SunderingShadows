//13.c  inherits from 01 like many others

#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();

    set_exits(([
        "northwest" : ROOMS"up",
        "southwest" : ROOMS"17",
        "east" : ROOMS"02"
        ]));
}

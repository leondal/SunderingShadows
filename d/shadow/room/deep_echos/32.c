//32.c  inherits from 01 like many others

#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
        
        "west"  : ROOMS"31",
        "east"  : ROOMS"33"
       
        ]));
}

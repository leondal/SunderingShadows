//cave10.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave09",
        "east" : ROOMS"cave11"
   	]));

}

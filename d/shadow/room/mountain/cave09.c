//cave09.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_exits(([
        "west" : ROOMS"cave06",
        "east" : ROOMS"cave10"
   	]));

}

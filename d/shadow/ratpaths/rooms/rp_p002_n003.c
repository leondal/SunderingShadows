#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
                   "west":PATH+"rp_p001_n003",
                   "south":PATH+"rp_p002_n004",
                   "up":"/d/shadow/room/goblin/rooms/inner1",
                   ]));

}

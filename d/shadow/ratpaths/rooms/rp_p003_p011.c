#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "southeast":PATH+"rp_p004_p010",
    "up":"/d/shadow/room/muuldaan/rooms/cavern6",
                   ]));

}

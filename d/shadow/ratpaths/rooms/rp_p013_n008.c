#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p012_n007",
    "up":"/d/darkwood/yntala/rooms/river1",
                   ]));

}

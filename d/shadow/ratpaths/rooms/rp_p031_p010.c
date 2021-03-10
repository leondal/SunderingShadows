#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p030_p011",
    "up":"/d/underdark/upper/tonovitunnel/tonovi02",
                   ]));

}

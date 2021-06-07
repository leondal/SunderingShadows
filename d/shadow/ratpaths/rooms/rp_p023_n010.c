#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_smell("default", "%^BOLD%^%^BLACK%^It smells of waste and shit.");
    set_exits(([
                   "north":PATH+"rp_p023_n009",
                   "southwest":PATH+"rp_p022_n011",
                   "up":"/d/tharis/newtharis/sewers/sewer15",
                   ]));

}

#include <std.h>
#include "../common.h"

inherit RATPATHS_EXIT;

void create(){
    ::create();
    set_exits(([
    "northwest":PATH+"rp_p015_p007",
"southeast":PATH+"rp_p017_p005",
    "up":"/d/shadow/juran/city/r40",
                   ]));

}

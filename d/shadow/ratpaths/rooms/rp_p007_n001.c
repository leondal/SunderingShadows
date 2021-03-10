#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_long(query_long() + " Numerous holes in the walls lead to the underpaths.");
    set_exits(([
    "south":PATH+"rp_p007_n002",
"west":PATH+"rp_p006_n001",
"east":PATH+"rp_p008_n001",
"northeast":PATH+"rp_p008_p000",
"northwest":PATH+"rp_p006_p000",

                   ]));

}

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_name("The beginning of a trail");
        set_short("%^RESET%^%^ORANGE%^The beginning of a trail");
        set_long("%^GREEN%^You stand amongst small %^BOLD%^trees%^RESET%^%^GREEN%^ and large %^BOLD%^shrubs%^RESET%^%^GREEN%^, the foliage "
"just enough to obscure you from the view of those on the nearby road. The narrow %^ORANGE%^trail%^GREEN%^ seems to wind away to the northeast.");
        set_smell("default","%^RESET%^%^ORANGE%^The earthy scents of nature surround you.");
        set_listen("default","%^RESET%^%^ORANGE%^There is the occasional rustle or chirp of wildlife.");
        set_items(([
           ({"trees","shrubs"}) : "The flora here are all smaller specimens, pine trees and boxwoods.",
           "trail" : "Care has clearly been given to keep this trail from becoming too obvious.",
        ]));
        set_exits(([
           "south" : "/d/tharis/road/eroad37",
           "northeast" : ROOMS"elfpath002",
        ]));
}
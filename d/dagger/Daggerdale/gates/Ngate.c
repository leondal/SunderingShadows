#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("The northern gates of Daggerdale");
    set_short("%^BOLD%^%^BLACK%^The northern gates of Daggerdale%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These were once the northern gates of Daggerdale village. The massive %^RESET%^"
"granite walls %^BOLD%^%^BLACK%^surrounding the city are now crumbled, with holes showing and rubble strewn "
"about on the ground. The adamantite chains for the drawbridge are still intact, but the thick wooden bridge "
"itself has been shattered, leaving open access from outside. A tattered %^RESET%^sign %^BOLD%^%^BLACK%^has "
"been trampled into the ground, now impossible to read.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "north" : "/d/dagger/road/road35",
      "south" : STREETS"street38",
    ]));
}

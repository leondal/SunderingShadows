#include <std.h>
#include "../../arctic.h"
inherit ROOM;

void create()
{
    ::create();

    set_terrain(GLACIER);
    set_travel(DIRT_ROAD);
    set_property("light", 2);

    set_name("Road to Mt. Krakus");
    set_short("%^BOLD%^The road to Mt. Krakus%^RESET%^");
    set_long("%^BOLD%^The gentle descent of the trail here continues "
             "towards the waterfall to the northeast, and to the frozen "
             "lake to the east.  All around the frozen lake, towering "
             "walls of granite stretch far into the sky.  It looks as "
             "if the waterfall cut this stony alcove from the mountain "
             "over thousands of years.");
    set("night long", "%^CYAN%^The gentle descent of the trail here continues "
             "towards the waterfall to the northeast, and to the frozen "
             "lake to the east.  All around the frozen lake, towering "
             "walls of granite stretch far into the sky.  It looks as "
             "if the waterfall cut this stony alcove from the mountain "
             "over thousands of years.");
    set_smell("default", "The cool scent of fresh water invigorates you.");
    set_listen("default", "The roar of the waterfall drowns out the sound "
                          "of everything else around you.");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        "lake" : "The small lake is frozen over and covered with a "
        "thin layer of powdery white snow.",
        "waterfall" : "The waterfall is truly impressive, plunging "
        "hundreds of feet before disappearing from view."]));

  set_exits(([
     "east"         : LAKE"lake3",
     "northeast"    : LAKE"road8",
     "west"         : LAKE"road6",
     "south"        : LAKE"lake6",
           ]));

}
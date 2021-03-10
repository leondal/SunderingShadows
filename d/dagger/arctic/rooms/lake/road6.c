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
    set_long("%^BOLD%^As you round the corner of the large rock "
             "protrusion the waterfall comes into full view.  It "
             "is a sight to behold.  Stretching more than five "
             "hundred feet into the air before disappearing back "
             "over the lip of the cliff far, far above.  Down below "
             "it plunges into an open hole in a small frozen lake.  "
             "Gigantic icicles hang from the cliff face, some hundreds "
             "of feet long.%^RESET%^");  
    set("night long", "%^CYAN%^As you round the corner of the large rock "
             "protrusion the waterfall comes into full view.  It "
             "is a sight to behold.  Stretching more than five "
             "hundred feet into the air before disappearing back "
             "over the lip of the cliff far, far above.  Down below "
             "it plunges into an open hole in a small frozen lake.  "
             "Gigantic icicles hang from the cliff face, some hundreds "
             "of feet long.%^RESET%^");  
    set_smell("default", "The cool scent of fresh water invigorates you.");
    set_listen("default", "The roar of the waterfall drowns out the sound "
                          "of everything else around you.");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        ({"rock","protrusion"}) : "A large section of the cliff "
        "protrudes out here, the trail winds around it.",
        "icicles" : "Some of the iciciles are hundreds of feet "
        "long and others are as small as your fingers."]));

  set_exits(([
     "east"         : LAKE"road7",
     "southwest"    : LAKE"road5",
           ]));

}
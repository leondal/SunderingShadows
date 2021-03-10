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
    set_long("%^BOLD%^The trail winds its way southwest around "
        "a tall, jutting portion of rock.  The wind here is "
        "relatively calm compared to the frigid gale back up "
        "the rise to the south.  The sounds of the waterfall "
        "tumbling into a great body of water can be clearly "
        "heard from here.\n"
        "Great icicles hang from the protruding rock.");
    set("night long", "%^CYAN%^The trail winds its way southwest around "
        "a tall, jutting portion of rock.  The wind here is "
        "relatively calm compared to the frigid gale back up "
        "the rise to the south.  The sounds of the waterfall "
        "tumbling into a great body of water can be clearly "
        "heard from here.\n"
        "Great icicles hang from the protruding rock.");
    set_smell("default", "You catch the scent of fresh water in "
                         "the cold air.");
    set_listen("default", "The low roar of the waterfall drowns out "
                          "the sound of the wind here.");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        ({"rock","protrusion"}) : "A large section of the cliff "
        "protrudes out here, the trail winds around it." ]));

  set_exits(([
     "northeast"    : LAKE"road6",
     "southeast"    : LAKE"road4",
           ]));

}
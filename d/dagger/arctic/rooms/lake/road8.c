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
    set_long("%^BOLD%^The waterfall is directly north of here, pouring "
             "its icy waters into the frozen lake.  Millions of frozen "
             "droplets of water bounce off the ice around you, sailing "
             "back up into the air, or sticking fast to the ice or your "
             "clothing.  The granite walls of the canyon all around you "
             "are covered with a layer of ice.  Everything is frozen here.\n"
             "Reflections of light can be seen in the ice all around.");
    set("night long", "%^CYAN%^The waterfall is directly north of here, pouring "
             "its icy waters into the frozen lake.  Millions of frozen "
             "droplets of water bounce off the ice around you, sailing "
             "back up into the air, or sticking fast to the ice or your "
             "clothing.  The granite walls of the canyon all around you "
             "are covered with a layer of ice.  Everything is frozen here.\n"
             "Reflections of light can be seen in the ice all around.");
    
    set_smell("default", "The cool scent of fresh water invigorates you.");
    set_listen("default", "The roar of the waterfall drowns out the sound "
                          "of everything else around you.");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        "reflections" : "The smooth ice holds hazy reflections of "
        "your surroundings.",
        "droplets" : "The droplets hang in the air for a few "
        "seconds before freezing and bouncing off the ice.",
        "waterfall" : "The waterfall is truly impressive, plunging "
        "hundreds of feet over the ice cliff and down into the "
        "frozen lake."]));

  set_exits(([
     "north"        : LAKE"waterfall",
     "east"         : LAKE"lake1",
     "southwest"    : LAKE"road7",
     "south"        : LAKE"lake3",
           ]));

}
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
    set_long("%^BOLD%^The trail here continues to descend to "
             "the northwest.  The wind is stronger to the south, "
             "but still very cold and biting here.  The trail "
             "to the northwest cuts behind a spire of rock and "
             "descends farther still.  The air seems somewhat "
             "warmer in that direction.  The rock walls are "
             "slick with ice here, glittering in the light.");    
    set("night long", "%^CYAN%^The trail here continues to descend to "
             "the northwest.  The wind is stronger to the south, "
             "but still very cold and biting here.  The trail "
             "to the northwest cuts behind a spire of rock and "
             "descends farther still.  The air seems somewhat "
             "warmer in that direction.  The rock walls are "
             "slick with ice here, glittering in the light.");   
    set_smell("default", "The crisp scent of fresh snow drifs in "
                         "from Mt. Krakus to the north.");
    set_listen("default", "A bitter wind whistles through the chill "
                          "mountain air");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        ({"walls","rock","ice"}) : "A thin layer of ice covers the "
        "rock walls." ]));

  set_exits(([
     "northwest"    : LAKE"road5",
     "south"        : LAKE"road3",
           ]));

}
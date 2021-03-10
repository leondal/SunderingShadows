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
    set_long("%^BOLD%^The path begins a steep descent here, "
             "heading between high rock walls to either side.  "
             "The wind howls through the stone corridor, stinging "
             "your face and eyes, tearing at your clothing.  It "
             "seems to grow steadily colder the farther north you "
             "travel.\n"
             "The wind is strong here, and bitterly cold.%^RESET%^");
    set("night long", "%^CYAN%^The path begins a steep descent here, "
             "heading between high rock walls to either side.  "
             "The wind howls through the stone corridor, stinging "
             "your face and eyes, tearing at your clothing.  It "
             "seems to grow steadily colder the farther north you "
             "travel.\n"
             "The wind is strong here, and bitterly cold.%^RESET%^");
    
    set_smell("default", "The crisp scent of fresh snow drifs in "
                         "from Mt. Krakus to the north.");
    set_listen("default", "A bitter wind whistles through the chill "
                          "mountain air");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled." ]));

  set_exits(([
     "north"        : LAKE"road4",
     "south"        : LAKE"road2",
           ]));

}

void init()
{
    ::init();
    if(!random(5) && !TP->id("arcticmon") && !TP->query_true_invis())
    {
        tell_object(TP, "%^CYAN%^The bitter wild whistles around you, the icy "
            "cold burning your face.%^RESET%^");
        tell_room(ETP, "%^CYAN%^"+TP->QCN+" shivers as a icy wind howls "
            "past "+TP->QO+".%^RESET%^", TP);
        TP->do_damage("torso", roll_dice(2,6));
    }
}
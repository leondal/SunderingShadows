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
    set_long("%^BOLD%^The road here travels to the east away "
        "from the drow cave roads and climbs sharply up a steep "
        "rise.  From this vantage point the evergreens of the "
        "forest to the south are clearly visible.  The top "
        "of a great waterfall can be seen far to the northeast.\n"
        "The trees and other vegetation are sparse here%^RESET%^");
    set("night long", "%^CYAN%^The road here travels to the east away "
        "from the drow cave roads and climbs sharply up a steep "
        "rise.  From this vantage point the evergreens of the "
        "forest to the south are clearly visible.  The top "
        "of a great waterfall can be seen far to the northeast.\n"
        "The trees and other vegetation are sparse here%^RESET%^");

    set_climate("arctic");
    
    set_smell("default", "The crisp scent of fresh snow drifts in "
                         "from Mt. Krakus to the north.");
    set_listen("default", "A bitter wind whistles through the chill "
                          "mountain air");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        ({"trees","vegitation"}) : "Small trees and shrubs find what "
        "little hold they can in the rocky mountain soil.",
        "evergreens" : "The tall, vibrant evergreens to the south "
        "look especially inviting from this windy vantage point.",
        ({"waterfall","mist"}) : "Freezing mist can barely be seen "
        "floating into the air over the icy waterfall far to the north."]));

    set_exits(([
              "northeast"   : LAKE"road2",
              "west"        :"/d/dagger/keep/road/road7",
             ]));

    

}






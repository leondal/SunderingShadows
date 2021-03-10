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
    set_long("%^BOLD%^The road here travels to northeast farther "
        "away from the drow cave roads and crests a steep rise.  "
        "The land can be seen for miles to the south.  Far to the "
        "north a spectacular waterfall cascades down the side of "
        "Mt. Krakus.  It falls hundreds of feet before disappearing "
        "from view behind the landscape.\n"
        "The top of this rise is barren of all vegetation.%^RESET%^");
    set("night long", "%^CYAN%^The road here travels to northeast farther "
        "away from the drow cave roads and crests a steep rise.  "
        "The land can be seen for miles to the south.  Far to the "
        "north a spectacular waterfall cascades down the side of "
        "Mt. Krakus.  It falls hundreds of feet before disappearing "
        "from view behind the landscape.\n"
        "The top of this rise is barren of all vegetation.%^RESET%^");
    
    set_smell("default", "The crisp scent of fresh snow drifs in "
                         "from Mt. Krakus to the north.");
    set_listen("default", "A bitter wind whistles through the chill "
                          "mountain air");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        "vegetation" : "No vegetation has managed to take hold "
        "on this windswept rise.",
        "land" : "From here you can see as far south as Daggerdale, "
        "over the forests to the southeast, and even Tonovi is "
        "visible to the southwest.",
        "waterfall" : "The waterfall is truly impressive, plunging "
        "hundreds of feet before disappearing from view."]));

    set_exits(([
        "north"     : LAKE"road3",
        "southwest" : LAKE"road1",
             ]));

}

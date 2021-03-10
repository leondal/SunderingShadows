#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("A road in the city");
    set_short("%^ORANGE%^An abandoned road in the city%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^ORANGE%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^. Beneath its shadow, the streets in "
"this area of the city are more narrow, more haphazard. The road is a collection of unmatched cobblestones, "
"while the buildings have the look of something that has been destroyed and rebuilt a thousand times, as if "
"something constantly rips everything down and the inhabitants build back up. It seems now, however, that "
"finally whoever lived here has surrendered to the inevitable and moved on, for the streets and buildings "
"appear to be deserted. %^GREEN%^W%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ld vegetat%^BOLD%^%^GREEN%^i%^RESET%^"
"%^GREEN%^on %^ORANGE%^grows through %^BOLD%^%^BLACK%^cracks %^RESET%^%^ORANGE%^in the walls, up between "
"buildings, and everywhere it can find space, slowly reclaiming the area. There is an almost tangible "
"feeling of emptiness here.");
    set_smell("default","%^RESET%^%^ORANGE%^The sweet fragrances of nature pervade this section of the city.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^This side of the city is eerily quiet.%^RESET%^");

    set_items(([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      "vegetation" : "%^RESET%^%^GREEN%^Wild vegetation grows everywhere, springing from cracks and pushing "
"through every available space.%^RESET%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}
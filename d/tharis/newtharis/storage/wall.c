#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("By the city walls");
    set_short("%^BOLD%^%^BLACK%^By the city walls%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^RESET%^%^BLUE%^Shadovar %^BOLD%^%^BLACK%^fortress, far in the sky above. It casts the "
"entire city under a pall of unrelenting %^RESET%^darkness%^BOLD%^%^BLACK%^. The city walls rise up "
"before you, stretching towards the distant fortress. The walls themselves are old, made up from giant "
"blocks of %^RESET%^%^WHITE%^granite %^BOLD%^%^BLACK%^cut and placed carefully. Age has worn the stones "
"smooth and there is no purchase to climb. There are signs of repaired damage though, as some spots are "
"li%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^hte%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^ than others. A narrow "
"%^RESET%^%^ORANGE%^path %^BOLD%^%^BLACK%^runs along the wall, most likely used by guards on patrol or "
"those who want to avoid the bustle of the city. %^RESET%^%^GREEN%^Spar%^BOLD%^%^GREEN%^s%^RESET%^"
"%^GREEN%^e v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^getation %^BOLD%^%^BLACK%^fights for survival along "
"the base of the wall.");
    set_smell("default","%^RESET%^%^ORANGE%^The air carries a thousand scents of a busy city.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear the bustle of the citizens going about their day.%^RESET%^");

    set_items (([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      "vegetation" : "%^RESET%^%^GREEN%^Small shrubs and sparse grass fight for survival.%^RESET%^",
      "walls" : "%^BLACK%^%^BOLD%^The walls themselves are old, made up from giant blocks of "
"%^RESET%^%^WHITE%^granite %^BOLD%^%^BLACK%^cut and placed carefully.%^RESET%^",
    ]));
}
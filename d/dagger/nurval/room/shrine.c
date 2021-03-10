#include "../tomb.h"

inherit "/std/temple";

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_temple("nilith");
    set_short("%^BOLD%^%^WHITE%^Shrine%^BLACK%^ of %^ORANGE%^Nilith%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Shrine%^BLACK%^ of %^ORANGE%^Nilith%^RESET%^
%^BOLD%^%^BLACK%^Walls and the ceiling of this room are made of %^WHITE%^skeletons%^BLACK%^. They pile up in their silent postures, with hands open and directed at the altar on the side that faces the exit. The altar is an empty %^ORANGE%^golden%^BLACK%^ throne. Numerous exquisite weapons lie in a pile that envelops it, nearly burying it within. The throne is too big for a human to sit in, but too small for a giant. It has humanoid %^WHITE%^skulls%^BLACK%^ build into its handles. It stands on a raised obsidian platform. Nothing else is in this place, not a single bench.
%^BOLD%^%^ORANGE%^"
        );
    set_exits(
        ([
            "north":ROOMS+"/tomb3",
            ]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_listen("default", "%^ORANGE%^You hear eerie humming coming from the throne.");
    set_smell("default","%^WHITE%^You smell nothing.");
}

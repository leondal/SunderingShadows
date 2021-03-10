#include "../undead.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("The City of Graez");
    set_short("%^GREEN%^A street in the city of Graez");
    set_long("%^GREEN%^A street in the city of Graez%^RESET%^\n"
"This %^ORANGE%^dusty street %^RESET%^travels in a full circuit of twists and "
"turns, around what remains of the city of Graez.  Buildings that once formed "
"part of a %^BOLD%^%^WHITE%^magnificent island empire %^RESET%^lie in rubble "
"and ruin at the roadside.  Armed or injured people, not all of them human, "
"come and go in a seeming constant flow upon these few besieged streets, "
"forming the last defense against the evils that constantly assail the city.");
    set_smell("default","The fresh scent of the ocean drifts through the ruined city.");
    set_listen("default","You hear the sounds of battle in the distance.");
    
    set_exits(([
        "out"     :TOWN"street1",
    ]));
}

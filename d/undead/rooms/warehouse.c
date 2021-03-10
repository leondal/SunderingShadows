#include "../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The City of Graez");
    set_short("%^BOLD%^%^BLACK%^Inside a dark warehouse%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Inside a dark warehouse%^RESET%^\n"
"Many warehouses such as this line the streets, in various stages of "
"%^RED%^disrepair%^RESET%^.  While a few still lie abandoned, most have been "
"put to various uses by the %^CYAN%^stragglers %^RESET%^that remain in this "
"ruined city.  Opportunistic merchants have set up shops in some, while others "
"seem to serve as storage or rough living quarters.  This particular one has "
"boxes and crates piled up against the walls, but has no discernable purpose "
"despite obviously being in use.\n");

    set_smell("default","The fresh scent of the ocean drifts through the ruined city.");
    set_listen("default","You hear the sounds of battle in the distance.");
}

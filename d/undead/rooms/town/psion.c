#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Inside a shabby warehouse");
    set_short("%^RESET%^%^ORANGE%^Inside a shabby warehouse%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Inside a shabby warehouse%^RESET%^\n"
"A lot of effort seems to have gone into making this old warehouse presentable."
"  No %^BOLD%^%^WHITE%^cobwebs %^RESET%^are visible, and the walls and floor of "
"the old building are clean of %^ORANGE%^dust%^RESET%^.  Crates and boxes have "
"been cleared away to allow for some simple shelves, upon which have been "
"carefully placed a variety of %^BOLD%^%^CYAN%^glittering crystals%^RESET%^.  "
"Yet more have been placed at strategic points upon the countertop, the only "
"real furniture in the room, where they catch the %^YELLOW%^light %^RESET%^and "
"splay cheerful patterns upon the ceiling.\n");
    set_smell("default","The fresh scent of the ocean drifts through the ruined city.");
    set_listen("default","You hear the sounds of battle in the distance.");

    set_exits( ([
        "west":TOWN"street2"
    ]) );
}

void reset() {
    ::reset();
    if(!present("sathid")) new(MON"sathid")->move(TO);
}

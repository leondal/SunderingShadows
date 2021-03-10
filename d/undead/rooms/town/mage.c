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
"This small warehouse seems to have been only vaguely converted into the store "
"you now stand in, with the rear of the building still serving more as "
"%^ORANGE%^storage space %^RESET%^than anything resembling a shop.  Crates and "
"boxes are stacked high, all with %^BOLD%^%^BLACK%^writing %^RESET%^scrawled "
"over them to designate their contents.  A particularly large box seems to be "
"serving as the shop counter, with a sign atop it showing a %^YELLOW%^list "
"%^RESET%^of components the shopkeeper is selling today.\n");
    set_smell("default","An acrid whiff of something unnameable bites at your sense of smell.");
    set_listen("default","You hear the sounds of battle in the distance.");

    set_exits( ([
        "east":TOWN"street2"
    ]) );
}

void reset() {
    ::reset();
    if(!present("charlotte")) new(MON"charlotte")->move(TO);
}

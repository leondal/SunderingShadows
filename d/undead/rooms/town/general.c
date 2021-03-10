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
"This seems little more than a warehouse, with crates and boxes all over the "
"place.  It seems the stock here is for sale rather than storage, though, with "
"people regularly coming and going.  %^YELLOW%^Coins %^RESET%^pass between the "
"shopkeeper and the customers, as some hand items over and others take items "
"with them.  There seems no real order to the %^MAGENTA%^chaos %^RESET%^other "
"than this interchange of goods.\n");
    set_smell("default","The fresh scent of the ocean drifts through the ruined city.");
    set_listen("default","You hear the sounds of battle in the distance.");
    set_property("fill waterskin",1);
    set_exits( ([
        "west":TOWN"street1"
    ]) );
}

void reset() {
    ::reset();
    if(!present("xyrren")) new(MON"xyrren")->move(TO);
}

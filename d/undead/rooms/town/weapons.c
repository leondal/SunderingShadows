#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Inside the barracks of Graez");
    set_short("%^RESET%^%^RED%^Inside the barracks of Graez%^RESET%^");
    set_long("%^RESET%^%^RED%^Inside the barracks of Graez%^RESET%^\n"
"This is one of a series of buildings inside the barracks of the city.  Here, "
"the %^BOLD%^%^BLACK%^stone walls %^RESET%^are set about with various weapons "
"of all kinds, from blades to bludgeons, large and small.  A massive glowing "
"%^RED%^forge %^RESET%^lies to the south, often in use and causing the room to "
"become very hot.  Other than this, the room is very %^ORANGE%^spartan%^RESET%^ "
"and obviously is not designed for anything other than functionality.\n");
    set_smell("default","The smell of smoke and iron drifts in the air.");
    set_listen("default","The building is filled with the constant clang of metal on metal.");

    set_exits( ([
        "east":TOWN"street17",
        "south":TOWN"forge",
        "southwest":TOWN"trader",
    ]) );
}

void reset() {
    ::reset();
    if(!present("alainn")) new(MON"alainn")->move(TO);
}

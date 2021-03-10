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
"This large building once served as a warehouse for storage and supplies, but "
"over time and bit by bit, it has given way to the massive %^BOLD%^%^BLACK%^"
"metal workshop %^RESET%^that it has become.  Sprawling piles of armor, weapons "
"and other sundries stack in %^RED%^enormous heaps %^RESET%^all throughout the "
"large stone and metal building.  Piling high and spilling down in unorganized "
"clusters and clumps.  Rare is the piece that appears to be %^GREEN%^whole "
"%^RESET%^and %^CYAN%^finished%^RESET%^.  In fact, more then a few of the items "
"seem to be mish-mashed together out of whatever piece of %^BOLD%^%^BLACK%^"
"metal %^RESET%^was handy at the time.\n");
    set_smell("default","The smell of smoke and iron drifts in the air.");
    set_listen("default","The building is filled with the constant clang of metal on metal.");

    set_exits( ([
        "southeast":TOWN"smith",
        "northeast":TOWN"weapons",
    ]) );
}

void reset() {
    ::reset();
    if(!present("omthgar")) new(MON"omthgar")->move(TO);
}

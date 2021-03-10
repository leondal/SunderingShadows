#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This ruined shop obviously was the site of a pitched battle. There are several "
"large %^RESET%^%^RED%^blast marks %^BOLD%^%^BLACK%^upon the walls and floor, as if two rival mages faced off "
"against each other. You can almost smell the %^YELLOW%^sulfur %^BLACK%^and %^GREEN%^acid%^BLACK%^ from the "
"spells that must have once been thrown about this area.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
      "east" : STREETS"street12"
    ]) );
}

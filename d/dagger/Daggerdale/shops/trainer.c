#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A ruined arena");
    set_short("%^BOLD%^%^BLACK%^A ruined arena%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The walls of this large, open-air arena have been shattered by some great force"
", leaving stones and rubble scattered around the area. %^RESET%^%^RED%^Bloodstains%^BOLD%^%^BLACK%^, even "
"more than would commonly be here, mar the %^RESET%^%^ORANGE%^sandy floor %^BOLD%^%^BLACK%^that would usually "
"be clean and undisturbed, ready for training. A few weapons lie scattered across the ground, long forgotten "
"to lie amidst the ruins.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "north" : STREETS"street20",
    ]));
}
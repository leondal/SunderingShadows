#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("A destroyed building");
    set_short("%^BOLD%^%^BLACK%^A destroyed building%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This building has been completely %^RESET%^%^RED%^destroyed%^BOLD%^%^BLACK%^. "
"The original %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^construction has been burnt and even the heavy "
"furniture is unrecognizable. Several large %^RESET%^%^RED%^scorch marks %^BOLD%^%^BLACK%^mar the walls, and "
"a large crater dominates the center of the room.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
	"west" : STREETS"street32",
    ]) );
}


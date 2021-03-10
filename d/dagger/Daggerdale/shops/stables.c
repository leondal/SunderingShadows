#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A destroyed stable");
    set_short("%^BOLD%^%^BLACK%^A destroyed stable%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This building has been completely %^RESET%^%^RED%^razed%^BOLD%^%^BLACK%^. The "
"original %^RESET%^%^ORANGE%^wooden %^BOLD%^%^BLACK%^construction has been burned and even what used to be "
"stalls are almost unrecognizable. Several large %^RESET%^%^RED%^scorch marks %^BOLD%^%^BLACK%^mar the walls, "
"and a large crater dominates the center of the room.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "west" : STREETS"street31"
    ]));
}


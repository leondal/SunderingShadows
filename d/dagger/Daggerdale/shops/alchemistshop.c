#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(WOOD_BUILDING);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Looking around at the room, it's impossible to tell what it could have been. "
"The level of destruction here is far beyond that which has been seen outside. Its almost as if there were "
"more %^RESET%^%^RED%^explosions %^BOLD%^%^BLACK%^here. Amidst the destruction are charred pieces of what "
"might've once been wood, and %^RESET%^%^CYAN%^melted glass %^BOLD%^%^BLACK%^upon the floor.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
      "north" : STREETS"street24",
      "east" : STREETS"street17",
    ]) );
}
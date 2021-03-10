#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This wrecked room may once have been a bar of some kind. The blasted remains of "
"a fireplace stand against one wall, with pieces of stone strewn about where the opening has been forcefully "
"damaged. The %^RESET%^%^ORANGE%^wooden walls %^BOLD%^%^BLACK%^are charred and %^RESET%^%^RED%^darkly stained"
"%^BOLD%^%^BLACK%^, and the remains of chairs and tables are scattered around the room in pieces. The long "
"bartop itself has been hewn into several pieces, with splinters lying about.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
      "east" : SHOPS"bar"
    ]) ); 
}
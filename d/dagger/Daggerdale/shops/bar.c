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
    set_short("%^BOLD%^%^BLACK%^A ruined shop");
    set_long("%^BOLD%^%^BLACK%^Once perhaps a dining room, this building is now in tatters. The %^RESET%^"
"%^ORANGE%^wooden walls %^BOLD%^%^BLACK%^are charred and %^RESET%^%^RED%^darkly stained%^BOLD%^%^BLACK%^, with "
"the curtains shredded so that only a few loose threads sway in the wind. The remains of chairs and tables are "
"scattered around the room in pieces. An opening remains where a door must once have stood, leading further "
"into the ruined building.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
      "east" : STREETS"street27",
      "west" : SHOPS"tap",
    ]) );
}
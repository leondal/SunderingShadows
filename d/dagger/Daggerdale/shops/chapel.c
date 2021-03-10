#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A damaged church");
    set_short("%^BOLD%^%^BLACK%^A damaged church%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This temple seems to have escaped most of the damage the rest of the area "
"experienced. High vaulted ceilings and stout wooden pews dominate the room, marred by scattered smudges and "
"%^RESET%^%^RED%^scorch marks%^BOLD%^%^BLACK%^, with a few broken benches and ornaments left lying upon the "
"floor. A lingering smell of %^RESET%^%^WHITE%^ash %^BOLD%^%^BLACK%^and %^RESET%^%^WHITE%^smoke %^BOLD%^"
"%^BLACK%^fills the area.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "south" : STREETS"street19",
      "west" : STREETS"street26"
    ]) );
}


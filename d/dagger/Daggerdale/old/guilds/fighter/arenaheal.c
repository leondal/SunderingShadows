
#include <std.h>
#include <arena.h>
inherit ARENAENTER;


void create(){
    :: create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);

    set_short("Arena Entrance");
    set_property("indoors", 1);
    set_property("light", 2);
set_property("no teleport", 1);
    set_long(
      "You are in the entrance to the arena.  To enter for mock combat, type 'enter safe'  To enter for real deadly combat, type 'enter live'"
    );

    set_items(([
      ]));

    set_exits(([
      "south" : "/d/dagger/Daggerdale/guilds/fighter/room1.c",
      ]));

    set_smell("default", "It smells of blood here.");
    set_enter_room("/d/dagger/Daggerdale/guilds/fighter/arena1.c");

    set_listen("default","You can hear the soothing sounds made by the water in the pool.");
}

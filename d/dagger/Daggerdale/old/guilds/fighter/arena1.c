#include <std.h>
#include <arena.h>

inherit ARENA;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_name("Fighter's areana of training.");
set_short("%^BOLD%^Fighter's arena of training.");
    set_long(
      "Hidden away here in a corner of Daggerdale, the great arena of the fighters is here for you to test your skills upon each other.  The room is small and square in shape, with one great pillar in the center.  Pieces of broken weaponry and armor lie around the room, along with traces of blood."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("arena",1);
    set_property("deathmove","/d/dagger/Daggerdale/guilds/fighter/arenaheal.c");
    set_listen("default","you can hear warcries and the clang of weapons upon each other.");
    set_smell("default", "the oils used to maintain weapons and armors can be smelled strong on the wind.");

    set_exits( ([
	"north" : "/d/dagger/Daggerdale/guilds/fighter/arena2",
	"east" : "/d/dagger/Daggerdale/guilds/fighter/arena3",
      ]) );
}

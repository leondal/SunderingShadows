#include <std.h>
#include <arena.h>

inherit ARENA;

void create(){
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("arena", 1);
    set_property("deathmove", "/d/guilds/legion/hall/arena/arenah.c");
    set_short("%^BOLD%^%^BLUE%^Arena of the Ancients");
    set_long(
      "You are in the arena of the Legion of Lost Souls.  All around you in the smoky darkness you see shadows move around you.  On the floor and pillars there are many marks of combat damage, from drops of blood to markings where someone has struck the wall with their weapon."
    );
    set_smell("default", "The arena is filled with a dark smoke.");
    set_listen("default", "In the dark smoke, it is eerily silent.");

    set_items( ([
	"walls" : "These walls are pockmarked and battle damaged.",
      ]) );
    set_exits( ([
	"southeast" : "/d/guilds/legion/hall/arena/arena13.c",
	"south" : "/d/guilds/legion/hall/arena/arena12.c",
      ]) );

}

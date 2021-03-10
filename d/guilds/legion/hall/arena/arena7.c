#include <std.h>
#include <arena.h>

inherit ARENA;

void create(){
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("no teleport", 1);
    set_property("arena", 1);
    set_property("deathmove", "/d/guilds/legion/hall/arena/arenah.c");
    set_short("%^BOLD%^%^BLUE%^Arena of the Ancients");
    set_long(
      "You are on the top floor of the Arena of the Legion.   It is a great plateau on top of the hill the guild is built into.  All around you the mountain rises around you, protecting you from being found."
    );
    set_smell("default", "The arena is filled with a dark smoke.");
    set_listen("default", "In the dark smoke, it is eerily silent.");

    set_exits( ([
	"west" : "/d/guilds/legion/hall/arena/arena6.c",
	"east" : "/d/guilds/legion/hall/arena/arena8.c",
	"northwest" : "/d/guilds/legion/hall/arena/arena3.c",
	"northeast" : "/d/guilds/legion/hall/arena/arena5.c",
	"north" : "/d/guilds/legion/hall/arena/arena4.c",
	"south" : "/d/guilds/legion/hall/arena/joust1.c",
      ]) );
    set_items( ([
	"mountains" : "They sorround you and protect the arena from detection.",
      ]) );

}

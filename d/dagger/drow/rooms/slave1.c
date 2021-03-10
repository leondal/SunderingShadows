#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Slave compound");
    set_long(
	"%^BLACK%^%^BLUE%^You stand within the elven slave compound. "
	"The compound is surrounded by chain link fence. The fence is "
	"covered with barbed wire. Wandering around various areas of "
	"the compound elven men, women and children wander about with "
	"sad misery in their eyes. To the west stands a small wheat "
	"shack. The ground is muddy and a slight drizzle of rain falls "
	"down on you."
    );
    set_listen("default",
	"You hear the rain's patter as it pelts the muddy ground."
    );
    set_smell("default",
	"A depressed mood fills the area."
    );
    set_items(([
	"shack":"%^BOLD%^%^YELLOW%^The shack is made of wheat and has "
	"no door...just a hole in the side wall of it. It has many holes "
	"in it.%^RESET%^",
	(({"slaves","slave","elf","elves"})):"%^MAGENTA%^The poor slaves "
	"are dressed in dirty rags. The elf seems to be nothing more than "
	"a skeleton draped with thin skin as the slaves are very "
	"underfed.%^RESET%^",
	"mud":"There is mud all about.",
	"rain":"%^BLUE%^The rain drizzles down upon the compound. Amazing "
	"how there was no rain in any other part of the city...%^RESET%^",
	"fence":"The fence is very strong and is topped with barbed wire.",
	"wire":"The wire is sharp and sparks with a mystical energy.",
	"energy":"%^BLUE%^%^BOLD%^As you look upon the energy a voice "
	"in your head speaks: %^BLACK%^Seek the old man for the key of "
	"entrance.%^RESET%^"
    ]));
    set_exits(([
	"north": RPATH "slave2",
	"west": RPATH "shack1"
    ]));
}
void reset() {
    ::reset();
    if(!present("slave")) {
	new( MPATH "slv")->move(TO);
	new( MPATH "slv")->move(TO);
    }
}

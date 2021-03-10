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
    set_short("Chain tunnel");
    set_long(
	"%^BLACK%^%^BLUE%^You stand within the elven slave chain "
	"tunnel. The tunnel leads north and south and is used to "
	"provide access to the slave mines from the compound. "
	"The chain fence here has been formed into a tunnel shape. "
	"The ground is muddy and a slight drizzle of rain falls down on you."
    );
    set_listen("default",
	"You hear the rain's patter as it pelts the muddy ground."
    );
    set_smell("default",
	"A depressed mood fills the area."
    );
    set_items(([
	"mud":"There is mud all about.",
	"tunnel":"The tunnel is formed from the same chain as the "
	"fence surrounding the compound.",
	"rain":"%^BLUE%^The rain drizzles down upon the compound. "
	"Amazing how there was no rain in any other part of the "
	"city...%^RESET%^",
	"fence":"The fence is very strong and is topped with barbed wire.",
	"wire":"The wire is sharp and sparks with a mystical energy.",
	"energy":"%^BLUE%^%^BOLD%^As you look upon the energy a voice "
	"in your head speaks: %^BLACK%^Seek the old man for the key of "
	"entrance.%^RESET%^"
    ]));
    set_exits(([
	"south": RPATH "slave3",
	"north": RPATH "slave5"
    ]));
}
void reset() {
    ::reset();
    if(!present("slave")) {
	new( MPATH "slv")->move(TO);
    }
}

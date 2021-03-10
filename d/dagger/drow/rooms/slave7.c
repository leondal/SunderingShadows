#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Slave bridge");
    set_long(
	"%^BLACK%^%^BLUE%^You stand at the foot of a rope bridge "
	"leading across the lake to the cavern wall. Across the bridge "
	"you see an entrance into the cavern. "
	"The chain fence here has been formed into a tunnel shape and "
	"ends at the foot of the bridge. "
	"The ground is muddy and a slight drizzle of rain falls down "
	"on you. To the west is a tunnel leading into the cavern "
	"wall. However, there is a portcullis blocking your progress"
    );
    set_listen("default",
	"You hear the rain's patter as it pelts the lake."
    );
    set_smell("default",
	"A depressed mood fills the area."
    );
    set_items(([
	"mud":"There is mud all about.",
	"tunnel":"The tunnel is formed from the same chain as the fence "
	"surrounding the compound.",
	"rain":"%^BLUE%^The rain drizzles down upon the compound. "
	"Amazing how there was no rain in any other part of the "
	"city...%^RESET%^",
	"fence":"The fence is very strong and is topped with barbed wire.",
	"bridge":"The bridge looks safe enough to support your weight.",
	"portcullis":"%^RED%^There appears to be no way to lift the "
	"portcullis from here.",
	"lake":"The lake is deep, dark and black as the night...the "
	"slaves would not survive escaping into the lake.",
	"wire":"The wire is sharp and sparks with a mystical energy.",
	"energy":"%^BLUE%^%^BOLD%^As you look upon the energy a voice "
	"in your head speaks: %^BLACK%^Seek the old man for the key of "
	"entrance.%^RESET%^"
    ]));
    set_exits(([
	"east": RPATH "slave6"
    ]));
}

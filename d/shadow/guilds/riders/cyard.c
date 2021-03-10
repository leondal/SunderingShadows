//coded by the one the only grendel
#include <std.h>
inherit ROOM;

void create() {
::create();
set_light(2);
set_property("indoors",0);
set_short("Rider's courtyard");
set_property("no teleport", 1);
set_long(
"Here in the middle of the guild hall is a great open air courtyard.  There are many trees and bushes here that give this place a serene feeling.  There are several chairs and tables under umbrellas.  To the east is a pair of great glass doors that lead to the foyer, and to the north a wide hallway leads to the Rider's Great Hall."
);
set_exits(([
"east" : "/d/shadow/guilds/riders/guild2.c",
"north" : "/d/shadow/guilds/riders/greathall.c"
]));
set_items(([
"tree" : "These large oak trees provide a good amount of shade.",
"bush" : "These bushes are teeming with life.",
"chairs" : "these wicker chairs look comfortable",
"tables" : "these tables have several empty glasses from drinks.",
"wall" : "it looks like a wall"
]));
set_smell("default", "You can smell the food and drink float over the walls to you.");
set_listen("default", "you can hear the birds chirp from the trees.");
}

void reset() {
::reset();
if(!present("fountain"))
new("/d/shadow/guilds/riders/obj/fountain.c")->move(this_object());
}

void init() {
::init();

add_action("drink","drink");
}

int drink(string str) {
if(!str) {
write("drink what?");
return 0;
}
if( (str == "from fountain") || (str == "water") || (str == "from water") || (str == "the water") ) {
write("   The cool crystal clear water from the fountain soothes your thirst as you drink deeply.");
say(" "+TPQCN+" drinks deeply of the crystal water in the fountain.");
TP->add_quenched(50);
return 1;
}
}

//	lane1.c
//	Pator@ShadowGate
//	Fri May 12 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_light(0);
    set_indoors(0);
    set_short("Gates towards a lane");
    set("day long",
@DAY
You are standing between some very rusty gates.  They lead to
a lane toward the northwest and to a village toward the east.
The gates are very old and looks like they haven't been used
for ages.  The forest behind the gates is very thick, and can't
be entered.
DAY
    );
    set("night long",
@NIGHT
You notice some rusty gates and a gate towards the northwest. The village is to the east of here and you notice that all is very unpreserved here.
NIGHT
    );
set_listen("default","The woods reveal wood-like noises.");
    set_exits(([
       "east" : "/d/deku/new/town4",
"northwest" : CASTLE+"lane2"
    ] ));
set_items(([ "oaks" : "The oaks are lining the road and are very old.",
	     "forest" : "It is on both sides of the lane and it is too thick to enter.",
	     "castle" : "It is to the north.",
	     "gates" : "The gates are very rusty and their function has been changed to holding birdnests",
	     "birdnests" : "These are normal nests and they are build in the gates"]));
   
}

void reset() {
  ::reset();
  if(!present("gnome")) {
    new("/d/deku/monster/gnome1")->move(this_object());
    new("/d/deku/monster/gnome1")->move(this_object());
  }
}

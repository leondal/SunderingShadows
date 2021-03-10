#include <std.h>

inherit ROOM;
int fall_in();
int is_virtual() { return 1; }

void create() {
set_indoors(0);
 ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
 set_light(2);
set_short("%^BOLD%^%^YELLOW%^A small patch of ruins");
 set_long(
@MELNMARN
   %^BOLD%^In the desert%^RESET%^
     There are ruins here that seem to get more frequent toward the north.
This possibly could be all that remains of some grand fortress in the desert.
You're tempted to treck forth north a little to explore.
MELNMARN
 );
 set_exits(([
     "west":"/d/shadow/virtual/desert/25,44.desert",
     "north":"/d/shadow/virtual/desert/24,45.desert",
     "south":"/d/shadow/virtual/desert/26,45.desert",
     "east":"/d/shadow/virtual/desert/25,46.desert"
]));
set_smell("default","You smell the odors of a bustling city.");
set_listen("default","You hear the sounds of people moving in the city.");
set_items(([
({"hole","spot","black","black spot"}):
@HOLE
You see a deep dark hole in the sand. From this distance
it appears to be risky to get close to.
HOLE
]));
set_search("hole",(:"fall_in":) );
}
int fall_in(){
	tell_object(TP,
@FALL
You get too close to the hole trying to search it.
You fall into the hole, and find yourself trapped.
FALL
);
tell_room(environment(TP),TPQCN+" falls into a hole in the sand.",TP);
TP->move("/d/shadow/virtual/level1/1,1.level1");
}

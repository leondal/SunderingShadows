#include <std.h>

inherit ROOM;
int fall_in();
int is_virtual() { return 1; }

void create() {
set_indoors(0);
 ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(RUTTED_TRACK);
 set_light(2);
set_short("%^BOLD%^%^YELLOW%^A small patch of ruins");
 set_long(
@MELNMARN
%^BOLD%^You are in a vast desert.%^RESET%^
All around you, is nothing but sand. Suddenly, out 
of the corner of your eye, you notice a black spot 
in the sand. Upon closer examination, you see it
is a hole in the ground.
MELNMARN
 );
 set_exits(([
     "west":"/d/shadow/virtual/desert/18,44.desert",
     "south":"/d/shadow/virtual/desert/19,45.desert",
     "east":"/d/shadow/virtual/desert/18,46.desert"
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

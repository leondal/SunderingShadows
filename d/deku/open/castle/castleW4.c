//	/realms/pator/castle/castleW4.c
//	Written by pator@ShadowGate
//	Tue May 9  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
   set_short("Inside the western wing");
    set_long(
@HALL
  You are walking in a hall in the western wing.  To the south there is the western tower and to the north you can see the armoury.
HALL
    );
set_smell("default","You smell nothing special.");
set_listen("default","You hear sounds from above");
    set_exits(([
       "south" : CASTLE+"castleW3.c",
       "north" : CASTLE+"castleW6.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick."
    ] ));
}

//	/realms/pator/castle/castleE9.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("The hallway to the kitchen");
    set_long(
@PATOR
This is the hallway that connects the kitchen to the dining room. Not much
can be seen except of the curtain that prohibits you to look at the 
dining room.
PATOR
    );
set_smell("default","You smell the last meal. Hmmmm delicious.");
    set_exits(([
       "east" : CASTLE+"castleE8.c",
       "west" : CASTLE+"castleE10.c"
       ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
      "curtain" : "A curtain that blocks your sight if the dining room. It once was red and was smooth but time have made it ugly to look at."   ] ));
}


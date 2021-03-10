//	/realms/pator/castle/castleW1.c
//	Written by pator@ShadowGate
//	Fri Apr 21  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Inside the guardquarters");
    set_long(
@QUARTERS
You are inside the quarters of the castle guards. It is a MESS in here !!
No one bothers to clean up this room and you see the result of this anarchy very clearly !! To the south there is a door, from where you hear the snoaring of the sleeping guards. To the east there is the entrance gate and to the west you go towards the western tower.
QUARTERS
    );
set_smell("default","You smell the decayed left-overs from yesterdays meal.");
set_listen("default","You hear snoaring from the south.");
    set_exits(([
       "east" : CASTLE+"castle2.c",
       "west" : CASTLE+"castleW2.c"
    ] ));
    set_items(([
       "sign" : "A nice wooden sign with 'HAY' written on it.",
       "door" : "A heavy wooden door, locked from the inside !",
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "mess" : "You see what the word tells you : a M E S S !!"
    ] ));
}
void reset() 
{ ::reset();
  if (!(present("knave"))) {
    new(CASTLE+MONSTERS+"knave")->move(this_object());
                           }
}

//	/realms/pator/castle/castlec2.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit "/std/room";

void init() 
  {
  ::init();
  }


void reset() 
    {
    ::reset();
    }

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_light(0);
    set_indoors(1);
    set_short("Down the dungeon ramp");
    set_long(
@PATOR
You are standing in knee deep water down the dungeon ramp. In early years 
they dropped people here with heavy stones on their necks to kill to almost
completely but they where revived and dropped again !
PATOR
    );
    set_exits((["up" : CASTLE+"castleD2.c" ]));

    set_smell("default","You smell very cool and fresh air.");
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "ramp" : "Made out of slippery stones.",
    ] ));

}



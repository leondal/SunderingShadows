//	castle5.c
//	Written by Pator@ShadowGate
//	Wed May 3  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_author("pator");
    set_light(2);
    set_indoors(0);
    set_short("In the castleyard.");
    set_long(
@CASTLEYARD
You are in the large castleyard. You see the well to the south. This is the part where the knaves practice their skills to become knights. There aren't many knights left, so everybody can have a try to prove their skill
and stamina. You see a dummy and some wooden swords for practice. That is all there is here, for the real stuff is put away in the armoury.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");

set_listen("default","You hear some sounds from within the castle.");
    set_exits(([
       "south" : CASTLE+"castle4",
      "southwest" : CASTLE+"castleW9",
   "northwest" : CASTLE+"castle6",
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them.",
       "dummy" : "This is a very old and well used dummy. The knaves use it to practice their skills on.",
         "wooden sword" : 
@PATOR
These swords are made of some wood and seem very solid and heavy. 
They are used by the knaves to practice their swordplay.
PATOR
    ] ));
}



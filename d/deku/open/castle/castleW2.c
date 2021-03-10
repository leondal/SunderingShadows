//	/realms/pator/castle/castleW2.c
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
    set_short("Outside the guardquarters");
    set_long(
@HALL
You are outside the quarters of the castle guards. To the west there is the western tower. The hall just connects these two rooms and has no special features.
HALL
    );
set_smell("default","You smell something horrible from the east.");
set_listen("default","You hear sounds from above");
    set_exits(([
       "east" : CASTLE+"castleW1.c",
       "west" : CASTLE+"castleW3.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "mess" : "You see what the word tells you : a M E S S !!"
    ] ));
}

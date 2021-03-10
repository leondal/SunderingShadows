//	/realms/pator/castle/castleCH2.c
//	Written by pator@ShadowGate
//	Tue May 9 1995

#include <castle.h>

inherit ROOM;


void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Inside the chapel");
    set_long(
@PATOR
You are at the far end of the chapel and you notice that there are marks on the floor where once stood the altar. You don't know what you should think but it looks sad .. a chapel without an altar.
PATOR
    );
set_smell("default","You smell incense and candlewax.");
set_listen("default","You hear churchmusic.");
    set_exits(([
       "east"  : CASTLE+"castleCH1.c" 
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "candles" : "They are in great quantities and they are all lit.",
       "marks" : "They sure are from moving around a heavy object.",
       "St. Anton" : "A statue depicting this most famous priest."
    ] ));
}

//	/realms/pator/castle/castleE10.c
//	Written by pator@ShadowGate
//	Wed May 3 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
   set_short("The castle's dining room");
    set_long(
@PATOR
You are in the dining room of the Marleen castle. You see a long dining table. This table is made of some fine wood, but it is very strong altogether. There are some chairs standing about and along the east wall there are some benches.
To the south there is a hallway into the yard. The kitchen is to the east
and to the west are the western towers.
PATOR
    );
   set_smell("default","You smell that the workers have cleaned the dining room after the last big party here.");
   set_listen("default","You seem to hear some noises from the yard.");
    set_exits(([
       "east" : CASTLE+"castleE9.c",
       "west" : CASTLE+"castleW12.c",
       "south" : CASTLE+"castle8.c",
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
      "table" : "The table is finely crafted out of some nice wood.",
      "chair" : "This chair is made of the same wood as the table.",
      "chairs" : "These chairs are made of the same wood as the table.",
      "benches" : "These benches are made of wood. Solid and strong." ]));
    }


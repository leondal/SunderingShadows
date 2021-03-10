//	/realms/pator/castle/castleE8.c
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
    set_short("The castle's kitchen");
    set_long(
@PATOR
You are in the kitchen of the Marleen castle. You see a stove and some cupboards. In the middle of the room there is a huge workbench.
Also a big table and 5 wooden chairs can be seen.
The east tower is to the east and the storageroom is to the south. You think that you can see a staircase going down into the cellar.
PATOR
    );
set_smell("default","You smell the last meal. Hmmmm delicious.");
    set_exits(([
       "east" : CASTLE+"castleE7.c",
       "west" : CASTLE+"castleE9.c",
       "south" : CASTLE+"castleE8a.c",
       "down" : CASTLE+"castleC1.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "workbench" : "This workbench is make out of wood and is very huge. There are drawers in it, but they seem to be locked.",
      "cupboard" : "This cupboard contains all the dishes and other materials used for eating",
      "table" : "The table is rough and made of wood.",
      "chair" : "This chair is made of the same wood as the table.",
      "chairs" : "These chairs are made of the same wood as the table."	 ] ));
}
void reset()
{ ::reset();
  if (!(present("castle cat"))) {
	new(CASTLE+MONSTERS+"C_cat")->move(this_object());
			        }
}

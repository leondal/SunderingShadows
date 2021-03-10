//	/realms/pator/castle/castleE8a.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit ROOM;


void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Inside the kitchen storage room");
    set_long(
@PATOR
You are in the kitchen storage room. You see shelves containing all sorts of food. You wonder who is gonna eat all this?
PATOR
    );
set_smell("default","You smell very cool and fresh air.");
    set_exits(([
       "north" : CASTLE+"castleE8.c" ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "shelves" : "There are lots of them and they are all filled with food.",
       "food" : "Lots and lots of delicious, nutricious things "
    ] ));
}

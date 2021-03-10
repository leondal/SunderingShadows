//	/realms/pator/castle/castleE2.c
//	Written by pator@ShadowGate
//	Fri Apr 21 06:26:58 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_author("pator");
    set_light(1);
    set_indoors(1);
    set_short("Near the stables");
    set_long(
@STABLES
You are in a room near the stables. When you look around you see a door with the sign "HAY" on it. Further there isn't much to see than the stone walls with horse shoes hanging on them.
STABLES
    );
set_smell("default","You smell the stables and the hay from behind the door.");
set_listen("default","You hear the stables as the walls block all outside noise.");
    set_exits(([
       "east" : CASTLE+"castleE3",
       "west" : CASTLE+"castleE1"
    ] ));
    set_items(([
       "sign" : "A nice wooden sign with 'HAY' written on it.",
       "door" : "A heavy wooden door, locked from the inside !",
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "horseshoes" : "The horseshoes are old and seem to be worn for many miles.",
       "horseshoe" : "The horseshoes are old and seem to be worn for many miles."
    ] ));
}

//	/realms/pator/castle/castleE5.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_author("pator");
    set_light(1);
    set_indoors(1);
    set_short("In the eastern hallway");
    set_long(
@PATOR
  You are in a hallway on the eastside of the castle.  When you look around you see thick stone walls, all covered with war trophies from ancient times.  You notice that the doors to the chapel are open.
PATOR
    );
set_smell("default","You smell very damp and hot air.");
set_listen("default","You hear church music comming from the chapel.");
    set_exits(([
       "north" : CASTLE+"castleE6",
       "south" : CASTLE+"castleE4",
       "west"  : CASTLE+"castleCH1" 
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
      "trophies" : "These trophies were won a long time ago when the knights ruled this place"
    ] ));
}

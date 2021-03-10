//	/realms/pator/castle/castleE4.c
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
    set_short("Near the eastern tower");
    set_long(
@PATOR
    You are in a room north of the eastern tower. When you look around you see thick stone walls, all covered with war trophies from ancient times.
    When you look at one of the trophies, you notice that a staircase is behind it leading down! You feel that the dungeon must be there.
PATOR
    );
set_smell("default","You smell very damp and hot air.");
set_listen("default","It is just if something cold runs down your spine when you hear nothing");
    set_exits(([
       "north" : CASTLE+"castleE5",
       "south" : CASTLE+"castleE3",
       "down"  : CASTLE+"castleD1"
    ] ));
    set_invis_exits(({"down"}));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
      "trophies" : "These trophies were won a long time ago when the knights ruled this place"
    ] ));
}

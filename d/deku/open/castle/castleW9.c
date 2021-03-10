//	/realms/pator/castle/castleW9.c
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
    set_short("Inside the gallery");
    set_long(
@HALL
The general opinion is that this gallery is very bad. 
But it has its advantages : It connects the southern wing 
with the north wing, which you should try to get to!
HALL
    );
   set_listen("default","You hear sounds from the yard.");
    set_exits(([
       "northeast" : CASTLE+"castleW12.c",
       "south" : CASTLE+"castleW7.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
    ] ));
}

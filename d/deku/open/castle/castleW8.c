//	/realms/pator/castle/castleW8.c
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
    set_short("Between the northwestern tower and the armoury");
    set_long(
@HALL
You are between the northwestern tower and the armoury. The hall is very bare in here and you don't think staying here will help you in any way.
HALL
    );
set_smell("default","You smell nothing special.");
set_listen("default","You hear sounds from the north.");
    set_exits(([
       "northeast" : CASTLE+"castleW10.c",
       "south" : CASTLE+"castleW6.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
    ] ));
}

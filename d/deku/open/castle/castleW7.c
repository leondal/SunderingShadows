//	/realms/pator/castle/castleW7.c
//	Written by pator@ShadowGate
//	Thu May 11  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Under the gallery");
    set_long(
@HALL
You are under a gallery and from here you can go to the yard and into the hall leading to the armoury.
HALL
    );
set_smell("default","You smell nothing because the wind carries all smells away.");
set_listen("default","You hear sounds from above");
    set_exits(([
       "west" : CASTLE+"castleW6.c",
       "south" : CASTLE+"castleW5.c",
       "northeast" : CASTLE+"castleW9.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "mess" : "You see what the word tells you : a M E S S !!"
    ] ));
}

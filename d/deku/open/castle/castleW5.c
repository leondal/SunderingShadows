//	/realms/pator/castle/castleW5.c
//	Written by pator@ShadowGate
//	Thu May 11  1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
    set_light(1);
    set_indoors(0);
    set_short("Inside the yard's gallery");
    set_long(
@HALL
You are walking under a very bad gallery. It has lots of holes in it and it hasn't been looked after for quite some time! You are walking under a roof, but you know you will be wet when it starts to rain.
HALL
    );
   set_smell("default","You smell the yard and its surroundings.");
set_listen("default","You hear sounds from the yard");
    set_exits(([
       "north" : CASTLE+"castleW7.c",
       "southwest" : CASTLE+"castleW3.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "mess" : "You see what the word tells you : a M E S S !!"
    ] ));
}

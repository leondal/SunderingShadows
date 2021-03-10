// /d/tharis/Tharis/tower1.c //
#include <std.h>
#include "../tharis.h"

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1);
   set_short("One of the gate watch Towers");
    set_long(
@OLI
	You are in one of the watch towers for the North Gate. 
The room is barren, except for a table and some chairs. The 
guards now use this for a lounge and common room. There are often
off duty guards in here.
	There is the staircase to the street below and also one to
the upper part of the tower. To the west is the wall, and to the
east is the walkway over the gate itself.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"east":"/d/tharis/Tharis/over_gate",
"west":"/d/tharis/Tharis/wall1",
"up":"/d/tharis/Tharis/tower1t",
"down":ROOMS"main1"
 ] ));
set_items(([
"table":"The table is cluttered with various papers and a mug or two."
]));
}

void reset(){
int num;
int i;
 ::reset();
  if(!present("patrol") && !random(4)) {
num=random(4);

for(i=0;i<num;i++){
  new("d/tharis/monsters/wall_patrol")->move(TO);
}
}
}

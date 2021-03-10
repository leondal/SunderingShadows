// /d/tharis/Tharis/tower9.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1);
   set_short("One of the watch Towers");
    set_long(
@OLI
        You are in the northern tower to the east gate. The room is
barren, except for a table and some chairs. The guards now use
this for a lounge and common room. There are often off duty  
guards in here.
        There are staircases to the upper part of the tower and to the
ground. To the north is the wall and to the south leads over the east 
gate.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
 "south" : "/d/tharis/Tharis/over_gate2",
"north" : "/d/tharis/Tharis/wall21",
  "up":"/d/tharis/Tharis/tower9t",
  "down":"/d/tharis/Tharis/estreet10"
 ] ));
set_items(([
"table":"The table is cluttered with various papers and a mug or two."
]));
}
void reset(){
 ::reset();
  if(!present("patrol")){
	new("d/tharis/monsters/wall_patrol")->move(TO);
     new("d/tharis/monsters/wall_patrol")->move(TO);
}
}

#include <std.h>
#include "../lizard.h"
inherit ROOM;

void create(){
::create();
set_name("Underground Lake");
set("short","Dark and water filled cavern.");
set("long","%^BOLD%^%^BLUE%^You are standing in very cold water in a large cavern.  "+
        "The water is shallow in most places you have been, no more than waist "+
        "deep on a normal sized human.  Who can say if the it gets deeper the farther "+
        "you wade.  Stalactites dangle from the ceiling and glisten with a fine coat "+
        "of water.  The ceiling is high above you somewhere in the darkness.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("no invis",1);
set_property("light",1);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The caves smell musty and damp.");
set_listen("default","An occasional drop from a stalactite splashes to the water.");
set_items(([
"walls":"Much like what you would expect cave walls to be like, hard, wet and cool to the touch.",
   "floor":"Littered with rubble from broken stalactites watching your step and watching your head may prove interesting.",
   "stalactites":"Hanging high above your head...sure hope they do not crash down upon you.",
   "stalactite":"Hanging high above your head...sure hope they do not crash down upon you.",
   "water":"Very cold and dark the water seeps inside your clothing like the kiss of death."
   ]));
set_exits(([
   "north":LROOMS+"l6",
   "northeast":LROOMS+"l7",
   "east":LROOMS+"l11",
   "southeast":LROOMS+"l17",
   "south":LROOMS+"l16",
   "southwest":LROOMS+"l15",
   "west":LROOMS+"w1"
 ]));
}

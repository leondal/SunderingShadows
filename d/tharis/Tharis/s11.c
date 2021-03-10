//s11.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

int FLAG;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(BACK_ALLEY);
   set_property("light",2);
   set_property("indoors",1);

   set_short("Large dark room");

   set_long(
@JAVAMAKER
   %^BLUE%^Large dark room%^RESET%^
This is a large dark room. There is a good sized round table
and a set of chairs in the center of the room. You quickly
realize that this a meeting place of some form. The room
is well swept and clean. The walls are hung with various
tapestries.
JAVAMAKER
   );

   set_smell("default","The dank musty atmosphere is oppressive.");
   set_listen("default","You hear the scratching of rats and the trickle of water.");
   set_items(([
      "tapestries":"These hanging hang loosely, covering large portions of the walls. They seem to be generic tapestries of no real consequence.",
      "table":"This table is well kept and lacks the divots and dings that tables in dark rooms usually have.",
   ]));

   set_exits(([
      "north":ROOMS"s10",
      "south":ROOMS"jewelry",
   ]));

   set_invis_exits(({"south",}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({"south",}),({"south_preExit",}));
   set_post_exit_functions(({}),({}));
   set_door("door",ROOMS"jewelry","south","Blah");
   set_open("door",0);
   set_locked("door",1);
}


void reset(){
   ::reset();
   FLAG = 0;
}

void init(){
   ::init();
   add_action("pull","pull");
   add_action("pull","move");

}



int south_preExit(){
     if(!FLAG){
      tell_object(TP,"You cannot go that way.");
      return 0;
   }
   return 1;
}


int pull(string str){
   if(str != "tapestry" && str != "tapestries")
      return notify_fail("Pull what?\n");

   tell_object(TP,"You notice that one of the tapestries was covering a door to the south.");
   FLAG = 1;
   return 1;
}

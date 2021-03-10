//hill2.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("Rolling hills");
   set_long(
@JAVAMAKER
You are on the edge of some gently rolling hills. There is
a pathway to the west and more hills generally eastward.
You can see closely spaced tracks in the dirt.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tracks":"There are tracks of small pack animals and people.",
   ]));

   set_exits(([
      "north":HILL"hill1",
      "east":HILL"hill5",
      "northeast":HILL"hill4",
      "southeast":HILL"hill6",
      "west":ROAD"road11",
      "northwest":ROAD"road10",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}








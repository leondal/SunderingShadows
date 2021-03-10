//road4.c

#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/inherit/roadrats";
object ob;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);

   set_short(
@JAVAMAKER
A wide gravel trail
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are at a bend in a wide trail leading to the city to 
the west and some small hills to the southeast. Open
land stretches out to the north and you can see a forest
off to the southwest.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ]));

   set_exits(([
      "west":ROAD"road3",
      "southeast":ROAD"road5",
//      "northeast" : ROAD"path1",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   ob = new("/d/newbie/obj/misc/1sign");
   ob->set_file("/d/newbie/obj/misc/sign2.txt");
   ob->move(TO);
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}








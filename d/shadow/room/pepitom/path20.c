//path20.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
A Small Path
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on a small unkept path through the woods.
It is mostly overgrown, but you can make out the path.
The trees loom over head, blocking out most of the daylight.
You see a shack to the south.
JAVAMAKER
   );

   set_smell("default","You smell the Fresh air drifting from the trees.");
   set_listen("default","You can hear trustling in the bushes.");
   set_items(([
   ]));

   set_exits(([
      "north":ROOMS+"path19.c",
      "south":ROOMS+"shack.c",
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








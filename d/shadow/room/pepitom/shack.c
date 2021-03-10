//shack.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
An Old Shack
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are in a small one room shack  .
There is junk scattered about the place.
There is what appears to be a bed in the far corner.
In the other corner, there is a small desk and chair.


JAVAMAKER
   );

   set_smell("default","You smell stale air in the shack.");
   set_listen("default","You hear the forest sounds from outside.");
   set_items(([
      "desk":"You see a desk with papers and open scrolls scattered about.",
      "junk":"You see rags, dirty dishes, and garbage.",
      "bed":"You see a pile of rags arranged into a bed.",
      "chair":"You see a small wooden chair.",
   ]));

   set_exits(([
      "north":ROOMS+"path20.c",
      "down":ROOMS+"basement.c",
   ]));

   set_invis_exits(({"down",}));
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








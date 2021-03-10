//ferry01.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
Ferry Road
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on an unused path that leads to the lake.
The brush has grown over most of the path, 
but you can still make it out.

JAVAMAKER
   );

   set_smell("default","You smell the Fresh air drifting from the lake");
   set_listen("default","You can hear the waves on the beach.");
   set_items(([
   ]));

   set_exits(([
      "north":ROOMS+"ferry02.c",
      "south":ROOMS+"wroad24.c",
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








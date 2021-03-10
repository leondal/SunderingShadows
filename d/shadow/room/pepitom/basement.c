//basement.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-2);
   set_property("indoors",1);
   set_property("no teleport",1);

   set_short(
@JAVAMAKER
Dark Basement
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are in a dark basement. 
You have a hard time seeing,
you trip from time to time.
JAVAMAKER
   );

   set_smell("default","");
   set_listen("default","");
   set_items(([
   ]));

   set_exits(([
      "up":ROOMS+"shack.c",
   ]));

   set_invis_exits(({"up",}));
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









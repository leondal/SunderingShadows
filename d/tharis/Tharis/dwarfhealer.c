//dwarfhealer.c

#include <std.h>
#include "../tharis.h"

inherit HEALER;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",1);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Underground healer's
JAVAMAKER
   );

   set_long(
@JAVAMAKER
   %^RED%^The underground healer's%^RESET%^
This dark room houses the underground's healer.  He's good
natured enough about the whole thing.  The dirty stone walls
are covered with white linen.  The little wooden chair here
provides some measure of relief for Heldien.
JAVAMAKER
   );

   set_smell("default","You smell some soap and some basic herbs.");
   set_listen("default","You hear the dripping of water through the cracks in the ceiling.");
   set_items(([
       "linen":"This linen is white but dirty. Evidently nothing has a chance to get cleaned down here.",
      "chair":"This is the only place for someone to sit. Heldien seems to actually enjoy the opportunity to sit here.",
   ]));

   set_exits(([
      "east":ROOMS"s4",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_name("heldien");
}


void reset(){
   if(!present("heldien")){
      new(MON"heldien")->move(TO);
   }
   ::reset();

}

void init(){
   ::init();

}








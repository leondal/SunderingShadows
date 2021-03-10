//recruiter.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
A Tharis recruiting station
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^YELLOW%^A Tharis recruiting station%^RESET%^
This finely decorated room holds a desk and a pair of oil lamps,
pictures of Law and Order cover the walls. You see drawings
of various people receiving awards. Behind the desk is a picture
of the Duke of Tharis.
JAVAMAKER
   );

   set_smell("default","Paper and ink mingle with leather and steel.");
   set_listen("default","Papers rustle, boards creak as people walk in and out.");
   set_items(([
      "drawings":"These drawings are of medals and symbols and soldiers.",
      "desk":"This is a solid oak desk, it is cluttered with papers.",
      "duke":"The Duke has a long beard and a thin mustache in the picture. He is wearing a decorative Chain mail armor and stands posed with both hands resting on the hilt of his sheathed sword.",
   ]));

   set_exits(([
      "west":ROOMS"main2",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_door("recruiter door",ROOMS"main2","west",0);
}


void reset(){
   ::reset();
}

void init(){
   ::init();
}








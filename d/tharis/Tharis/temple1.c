//temple1.c

#include <std.h>
#include "../tharis.h"

inherit "/std/temple";

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
%^RED%^Hidden Temple of Mask%^RESET%^
JAVAMAKER
   );

   set_long(
@JAVAMAKER
   %^RED%^Hidden Temple of Mask%^RESET%^
This temple of mask is a secret place. The normal officials
of Tharis controling taxation and balance of various deities
have failed to sniff this temple out. This is a plain temple but
it is infact frequented by the ShadowLord himself due to the
sway he holds with a large portion of the Tharis under society.
The altar here is simple, for this is an area to plan the next
step in Mask's schemes. There is a small stone tablet here.
JAVAMAKER
   );

   set_smell("default","You smell the wiffs of incense.");
   set_listen("default","There seems to be an electricity in the room.");
   set_items(([
      "tablet":"This reads simply, >Mask will regain what Cyric has taken. The time for games is over. The ShadowLord has seen what is needed and what will be done.<",
   ]));

   set_exits(([
      "out":ROOMS"a18",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_temple("mask");
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}








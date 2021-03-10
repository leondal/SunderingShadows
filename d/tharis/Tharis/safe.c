//safe.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(BACK_ALLEY);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Safe Room
JAVAMAKER
   );

   set_long(
@JAVAMAKER
    %^RED%^Safe room%^RESET%^
This is a small safe room. It's well hidden behind the The Merchant's
Cup. There isn't much to this room. The room is a little dark
box. The walls are bare. You notice that the floor is trodden clean.
JAVAMAKER
   );

   set_smell("default","This is a stale and musty room.");
   set_listen("default","You hear the muffled shouts of some merchant yelling for more wine.");
   set_items(([
      "south wall":"It looks false on closer inspection.",
      "walls":"You notice that the east and south walls are newer than the surrounding walls.",
      "floor":"The floor here is trodden clean, as if there is a high volume of traffic. The flow almost seems to be from the east to the south.",
      "east wall":"This wall looks as if it can be simply entered.",
   ]));

   set_exits(([
      "east":ROOMS"cup",
      "south":ROOMS"s1",
   ]));

   set_invis_exits(({"east",}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}
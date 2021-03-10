//s7.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

int FLAG;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(BACK_ALLEY);
   set_property("light",0);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Back Passage
JAVAMAKER
   );

   set_long(
@JAVAMAKER
    %^RED%^Back Passage%^RESET%^	
This passage leads through some of the dark places
of Tharis. The under ground society of Tharis bases a lot of activities
from these passages. The great stone structures that form
the city of Tharis obviously have left these gaps that now house
much of the less tasteful citizens of Tharis.
JAVAMAKER
   );

   set_smell("default","The dank musty atmosphere is oppressive.");
   set_listen("default","You hear the scratching of rats and the trickle of water.");
   set_items(([
      "floor":"The floor has marks of passage. You can see the signs work toward the southwest.",
   ]));

   set_exits(([
      "southwest":ROOMS"s8",
      "east":ROOMS"s6",
   ]));

}

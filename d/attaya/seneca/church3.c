#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_short("Bell tower");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@DESC
You stand at the base of the circular staircase that winds around
the interior of the bell tower. Looking up, you can see about a 
hundred feet to the massive bronze bells that hang in the bell 
tower and sing to Seneca. A metal gate stands here to block this 
staircase off from the rest of the church.
DESC
   );
   set_exits(([
      "up":"/d/attaya/seneca/church4",
      "west":"/d/attaya/seneca/church2",
   ]));
   set_door("gate", "/d/attaya/seneca/church2", "west", 0);
   set_open("gate", 0);
   set_items(([
      "gate" : "It is a heavy iron gate but it doesn't appear locked.",
      "bells" : "The bells are enormous and made of brass, they hang into this room from a heavy rod about a hundred feet above you.",
   ]));
}


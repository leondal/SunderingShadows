#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_short("Base of the bell tower");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@DESC
You are in a large cylindrical room. Looking up, you can see about 
a hundred feet to the massive bronze bells that hang in the bell 
tower and sing to Seneca. A metal gate closes off the staircase 
that winds around the walls of the circular tower and provides 
access to the bells.
DESC
   );
   set_exits(([
      "staircase" : "/d/attaya/seneca/church3",
      "west" : "/d/attaya/seneca/church",
   ]));
   set_door("gate", "/d/attaya/seneca/church3", "staircase", 0);
   set_open("gate", 0);
   set_items(([
      "gate" : "It is a heavy iron gate but it doesn't appear locked.",
      "bells" : "The bells are enormous and made of brass, they hang into this room from a heavy rod about a hundred feet above you.",
   ]));
}

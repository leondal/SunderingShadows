#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Outside the Bank of Attaya.");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
Before you stands the Seneca branch of the %^CYAN%^Bank of Attaya%^RESET%^.  
It is a large fortress-like structure that has been designed 
to survive natural disasters and siege. The marble walls and 
columns are accented with blue glass and brass metalwork that 
is quite intricate. This building houses the wealth of empires 
and is the life blood of this coastal city. Tall spruce and 
fir trees line a small winding walkway that gives a scenic walk 
through the landscaping. A wooden bridge crosses a small stream 
as you near the door.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/bank",
      "east" : "/d/attaya/seneca/street2",
      "north" : "/d/attaya/seneca/road39"
   ]));
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The health green grass has been recently cut.",
      "trees" : "They are ancient evergreens that tower above you and cast shade upon the bank.",
      "bridge" : "It is a small decorative wooden bridge over a man made stream.",
      "stream" : "It is a small man-made stream with large oriental fish in it!",
      "fish" : "They are large goldfish that are nearly a foot in length.  They glisten in the sunlight.",
   ]));
}
           

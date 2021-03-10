#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Main Square at the center of Seneca.");
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_long(
@DESC
Here is the square of the city of Seneca.  Attacked by Intruder 
in an attempt to destroy the ancient and only remaining enclave 
of good on this island, the %^CYAN%^Cathedral%^RESET%^ stands to the south.  To the 
east and west you can see where the road continues, and to the 
south is a small garden before the %^CYAN%^Cathedral%^RESET%^.
DESC
   );
   set_listen("default", "The gentle trickle of the water falling from tier to tier soothes your soul.");
   set_exits(([
      "north" : "/d/attaya/seneca/street3",
      "east" : "/d/attaya/seneca/street5",
      "west" : "/d/attaya/seneca/street7",
      "south" : "/d/attaya/seneca/street4",
   ]));
   set_items(([
      "bricks" : "They are identically sized and formed bricks of granite.",
      "trees" : "Several majestic Norfolk Pines stand at least a hundred feet tall and rise from the earth beneath the square.",
      "statues" : "They are statues built to honour the founders of Seneca.  One represents Lord Seneca and the rest are members of his family and court.",
      "lord seneca" : "He is a strong, determined man who reaches his hands into the waters of the fountain.",
      "buildings" : "They are well kept buildings. Many are brightly painted.",
      "street" : "This is a busy street that is paved with bricks.  They are tight fitting and worn smooth from being tread heavily upon.",
   ]));
   find_object_or_load("/d/npc/celastral");
   find_object_or_load("/d/attaya/seneca/mon/trainer");
}

void reset() {
   ::reset();
   if(!present("fountain"))
      new("d/attaya/seneca/obj/fountain")->move(this_object());
}

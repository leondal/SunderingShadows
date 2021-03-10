#include <std.h>
#include "../../../elfisland1.h"

inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("night light",1);
   set_property("light",1);
   set("short", "An orc camp");
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^ORANGE%^The trees in this area of the forest look hurt. A lot of them seem as"+
      " if the branches were ripped off by brute force. It was no doubt done by the orcs that built"+
      " this camp. Around you are different little foot worn paths leading to the different tents."+
      " In the middle of the camp is one large tent."
   );
   set_smell("default","%^RESET%^%^GREEN%^The smell of the wolf hides fill the air.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^The sounds of life in the camp surround you.%^RESET%^");
   set_items( ([
      "trees" : "The trees look damaged and hurt from the abuse by those that inhabit this area.",
      "large tent" : "There is one large tent that stands out among everything else in this camp.",
   ]) );
}

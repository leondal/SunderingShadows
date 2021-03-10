#include <std.h>
#include "../../../elfisland1.h"

inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set("short", "An orc tent.");
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set("long",
      "%^RESET%^%^ORANGE%^You stand inside one of the smaller tents of the camp. These tents are"+
      " scattered about in the small clearings the forest provides. The cover is made of several"+
      " wolf hides as are the rest of the camp grounds. The hides are held up by broken tree branches"+
      " and appear to be quite sturdy if nothing else. There is not much in this tent other than a"+
      " few bones."
   );
   set_smell("default","%^RESET%^%^GREEN%^The smell of the wolf hides fill the air.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^The sounds of life in the camp surround you.%^RESET%^");
   set_items( ([
      "bones" : "There are a few bones scattered around the room. One pile in particular is very high.",
      "pile" : "There appears to be something hidden under the pile of bones.",
   ]) );
}

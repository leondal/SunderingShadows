#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This wider path goes on west and east from here. To the west you can see a rather sizeable"+
      " clearing. There are many different paths heading from the clearing to the west. To the east is the way to the entrance"+
      " of the village. When you look off to the northwest you can see a broad staircase leading inside a tree."
   );
   set_items( ([
      "clearing":"The path appears to open into a gathering space to the west.",
   ]) );
   set_exits( ([
      "west" : TOWN+"center",
      "east" : TOWN+"road01",
   ]) );
}

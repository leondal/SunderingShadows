#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The path closes off from the clearing to the north on this tiny trail."+
      " The walkway is very narrow between the trees and allows only one person to walk through"+
      " at a time. You can tell the path is well walked from the way the grass grows along the way."
      " The tiny trail continues on a ways down to the south."
   );
   set_items( ([
      "trail":"The trail is obviously well used as the grass seems to grow around the walkway.",
   ]) );
   set_exits( ([
      "north" : TOWN+"center",
      "south" : TOWN+"road06",
   ]) );
}

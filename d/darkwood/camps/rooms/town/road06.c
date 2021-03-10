#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The tiny trail stretches on from north to the south from here. The path"+
      " remains narrow until it seems to open up into a wide space to the south. The trees continue"+
      " to line the edge of the path, but seem to break open to the south, providing a boundary between"+
      " the thick of the forest and this open space to the south."
   );
   set_items( ([
      "clearing":"There appears to be a clearing up ahead apart from the thick of the forest.",
   ]) );
   set_exits( ([
      "north" : TOWN+"road05",
      "south" : TOWN+"park",
   ]) );
}

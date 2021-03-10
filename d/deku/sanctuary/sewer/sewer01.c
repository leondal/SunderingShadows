#include <std.h>
#include "../dragon.h"

inherit BSEWER;

void create() {
   ::create();
   set_property("light", -1);
   set_property("indoors", 1);
   set_property("no teleport",1);
   set_short("Disgusting sewer");
   set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of %^RED%^Sanctuary%^BLACK%^. They are"+
      " filled with many disgusting objects. The tunnel stretches off toward"+
      " the west, and a grate is set in the east wall, near the ceiling."
   );
   set_items(([
     "sewers":"The disgusting tunnels of waste under Sanctuary.",
     "grate":"The grate is old and rusty.  It is set far up on the eastern wall."]
   ));
   set_exits(([
     "up": TOWN+"square",
     "west": SEWER+"sewer05"
   ]));
}

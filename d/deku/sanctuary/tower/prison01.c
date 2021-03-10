#include <std.h>
#include "../dragon.h";

inherit BPRISON;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This is a small room. It does not have very much at all"+
      " to it except the stairs that lead down to the old cellar. You assume that"+
      " was the sole purpose of this space. Right across from you are a couple of"+
      " boxes, but they appear empty on first sight. The walls, ceiling, and floor"+
      " are as damp as the rest of this abandoned and old structure."
   );
   set_items( ([
      ({"walls","ceiling","floor"}) : "The walls, ceiling, and floor are damp and bare.",
      "boxes" : "The boxes are empty and just laying in a heap.",
   ]) );
   set_exits( ([
      "stairs" : TOWER+"bottom19",
      "east" : TOWER+"prison02"
   ]) );
}

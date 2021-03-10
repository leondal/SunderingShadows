#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_short("Sanctuary Sewers");
   set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange objects. The tunnel stretches off for miles"+
      " toward the south. Light comes from the room toward the east."
   );
   set_exits(([
      "east" : SEWER+"sewer01",
      "south" : SEWER+"sewer06"
   ]));
   set_items(([
      "sewers":"The disgusting tunnels of waste under Sanctuary."
   ]));
}

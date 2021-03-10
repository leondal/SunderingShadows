#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_short("Seneca Pawn Shop");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_long(
@DESC
Huge amounts of equipment are piled high in here. On the far 
wall is a large oak desk where anything of value can be bought 
and sold. Many adventurers frequent this shop as many of the 
world's most powerful warriors sell items here from distant 
lands and from deep recesses of dark dungeons. The ceiling in 
here is painted black and marked with hundreds of stars that 
glow through tiny holes between the ceiling and the roof. You 
begin to wonder what is hidden in the attic from which the light 
seeps through.
DESC
   );
   set_smell("default", "The air in here is somewhat musty from countless used items.");
   set_listen("default", "People rummage through piles all around you.");
   set_exits(([
      "out" : "/d/attaya/seneca/pawnyard",
   ]));
   set_door("door", "/d/attaya/seneca/pawnyard", "out", 0);
   set_open("door", 0);
}

void reset() {
   ::reset(); 
   if(!present("cervantes"))
      new("/d/attaya/seneca/mon/cervantes" )->move(TO);
}

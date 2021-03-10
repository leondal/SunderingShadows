#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Tanar on the Dagger Sea");
  set_long(
  "Tanar on the Dagger Sea.\n"
    "  Torm's marketplace stretches out with many people from all lands doing business among its tents, booths and goods strewn mats."
    "  The Dagger Sea comes right up to the edge of the road to the rocks that Torm is built on."
  "  On the sea to the east, between the scattered warehouses, you can see many ships going to or from the docks north and south of you."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled about the city, moving from the rocks of the"+
  " Dagger Sea to the east, and stretching whispy tendrils down the"+
  " empty streets and silent warehouses.  It appears to be a natural phenomenon and was"+
  " probably once used to keep pirates and such at bay during the"+
  " night, no one would be foolish enough to try and dock a ship in"+
  " the fog with all the rocks about."
  );
  set_exits(([
  "north":TCITY+"c47",
  "south":TCITY+"c66",
  "east":TCITY+"warehouse",
  "west":TCITY+"c57",
  ]));
}

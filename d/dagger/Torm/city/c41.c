#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
  set_door("door",TCITY+"c52","south","Torm masterkey");
  //set_door("bar door",TCITY+"c52","south","masterkey");
  //set_door("door",TCITY+"c42","north","masterkey");
   set_short("Mainstreet Torm");
  set_long(
  "Mainstreet Torm.\n"
  "  You can hear the bustle of this large seaport around you."
    "  The calls of vendors are heard far off to the east near the center of the city and the gates of Torm are to the west."
  "  Mainstreet here leads from the gates to the center of the city to the east."
  "  People wander in and out of the resturant to the south with smiles on their faces."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city of Torm.  It makes the night"+
  " air a little bit more chilly, and makes traveling around at night"+
  " a bit more difficult if you don't already know your way.  Tanar road"+
  " runs north and south, and the closed gates of Torm are just"+
  " barely seen to the west."
  );
  set_exits(([
  //"north":TCITY+"c42",
  "east":TCITY+"c43",
  "west":TCITY+"c40",
  "south":TCITY+"c52",
  ]));
  set_open("door",1);
  set_locked("door",0);
  "/d/dagger/Torm/city/c52"->set_open("door",1);
}

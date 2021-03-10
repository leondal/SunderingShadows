#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
      set_short("Tanar at the sea's edge");
  set_door("door",TCITY+"c30","north","masterkey");
  set_long(
      "Tanar at the sea's edge.\n"
    "  Tanar road continues here along the north side of Torm's Harbor."
   "  A small dark building with the sign of a frosted mug over a pig's head has a door to the north."+
   " Tanar road continues a little ways to the south and then curves to the west."
  );
  set("night long",
  "%^BLUE%^"
   "The building to the north has a sign with a %^BOLD%^%^CYAN%^frosted mug"
   " %^RESET%^%^BLUE%^ on it while light from the windows chases away the fog"+
   " that settles over the city at night.  To the east you can see"+
   " the boardwalk extending into the foggy sea."
  );
   set_items(([
   ({"building","dark building","small dark building"}) : "There is a small, stone building to the north. It has the sign of a frosted mug over a pig's head, and is obviously a tavern of some sort.",
   "sign" : "The sign holds the picture of a frosted mug over a pig's head, so is probably a tavern or some sort.",
   ]));
  set_exits(([
  "north":TCITY+"c30",
  "west":TCITY+"c27",
  "east":TCITY+"c18",
  "south":TCITY+"c39",
  ]));
//   if(query_night() == 1) { changed by Lujke April 15 2007, to keep the
                             // bar open all night
//    set_open("door",0);
//    set_locked("door",1);
//    "/d/dagger/Torm/city/c30"->set_open("door",0);
//   }
//   else {
      set_open("door",1);
      set_locked("door",0);
      "/d/dagger/Torm/city/c30"->set_open("door",1);
//   }
}


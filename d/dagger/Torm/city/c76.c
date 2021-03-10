#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Tanar road on the Dagger Sea");
  set_long(
  "Tanar road on the Dagger Sea.\n"
  "  The rocks here that Torm is built on glisten as the Dagger Seas waves roll against them."
    "  Boardwalks stretch out over the waters north and south of you on the harbor, while many boats sail around to them, are unloading off them, or leaving again for the open waters."
   "  A pair of tall gates to the west blocks the way into the warehouses that are owned by some of the shipping companies that frequent Torm."
  );
  set_door("gates",TCITY+"c102","west","Torm masterkey");
  set("night long",
  "%^BLUE%^"
    "Fog spills off the Dagger Sea into the city of Torm, clinging to"+
   " the ground and making it sometimes difficult to tell where you're"+
  " going.  You can still hear the waves crashing against the rocks,"+
  " letting you know that the sea is close by.  Boardwalks stretch"+
  " out over the dark waters to the north and south of you.  A tall gate"+
  " to the west stands closed against the night."
  );
  set_exits(([
  "west":TCITY+"c102",
  "north":TCITY+"c66",
  "south":TCITY+"c83",
  ]));
}

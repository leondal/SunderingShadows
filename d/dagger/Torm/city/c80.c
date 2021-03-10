#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_door("door",TCITY+"c96","north","Torm masterkey");
  set_short("Tanar south by the gates of Torm");
  set_long(
  "Tanar south by the gates of Torm.\n"
  "  Tanar road runs along the south wall of Torm here flanked on both sides by houses and shops."
  "  To the east you can see the south gates of Torm standing open."
  "  A set of crossed swords over a shop to the north describes the type of shop it is and a sound of ringing metal comes through its open door."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city and Tanar south.  Houses and"+
  " shops line the road, but all their doors and windows are closed"+
  " against the chill night air.  The fog makes it a little difficult"+
  " to tell where you're going."
  );
  set_exits(([
  "north":TCITY+"c96",
  "east":TCITY+"c81",
  "west":TCITY+"c79",
  ]));
}

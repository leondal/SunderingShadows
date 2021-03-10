#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("South Tanar by the gates of Torm");
  set_long(
  "South Tanar by the gates of Torm.\n"
  "  Houses line the south of the road here against the outer walls of Torm while a tall wall blocks your view north."
  "  Tanar continues east and west here with the south gates of Torm to the west."
  "  You can start to see the Dagger Sea far off to the east now."
  );
  set("night long",
  "%^BLUE%^"
  "Dark houses line the south of the road here while a tall wall blocks"+
  " your view north.  A light fog has settled over the city, but it"+
  " mostly clings to the ground here and obscures your view of the road."
  );
  set_exits(([
  "east":TCITY+"c83",
  "west":TCITY+"c81",
  ]));
}

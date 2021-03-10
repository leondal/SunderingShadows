#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Crossroads in northern Torm");
  set_long(
  "Crossroads in northern Torm.\n"
  "  North Tanar road meets here with State road which leads south towards the center of Torm."
  "  Tanar continues east and west here following the outer wall of the city."
   "  Straight south of here leads to the busy marketplace."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, it slightly obscures your"+
  " path.  The road here leads east and west while another road starts"+
  " leading south into more fog."
  );
  set_exits(([
  "up":TCITY+"c4a",
  "east":TCITY+"c5",
  "west":TCITY+"c3",
  "south":TCITY+"c13",
  ]));
}

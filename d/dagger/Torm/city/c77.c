#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Street in southwest Torm");
  set_long(
  "Street in southwest Torm.\n"
  "  Torm stretches out to the east and south of you from here."
    "  A walled compound's gates are to the northeast from you here and roads lead north and east as well as a set of stairs that lead up to a watchtower on the outer walls."
   "  Houses line the streets and people wander about going about their daily business around you."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city.  Stairs lead to a watchtower"+
  " that rises above the fog.  The gates to a walled compound are"+
  " northeast of here.  The streets lie quiet and you hear only the"+
  " wind blowing through the streets and the crashing of the waves in"+
  " the distance.  All the shutters of the houses that line the street"+
  " are closed."
  );
  set_exits(([
  "up":TCITY+"c77a",
  "north":TCITY+"c71",
  "northeast":TCITY+"c99",
  "east":TCITY+"c78",
  ]));
}

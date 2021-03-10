#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Steet in northwest Torm");
  set_long(
  "Street in northwest Torm.\n"
    "  A walled compound fills your view to the south here."
  "  The houses of Torm line the wall to your north and the road runs east and west here following the city walls."
  );
  set("night long",
  "%^BLUE%^"
  "A walled compound rises up out of the fog to the south of you."+
  "  The road runs east and west here along the city wall to the north."
  "  All the houses have closed their windows, and everyone seems to"+
  " be fast asleep."
  );
  set_exits(([
  "east":TCITY+"c4",
  "west":TCITY+"c2",
  ]));
  set_items(([
  (({"walled compound","compound"})):"You can barely see the top of the spire of a grand mansion beyond them.",
  "houses":"The houses of Torm's citizens are small and for the most part well built and cared for.  The doors lie shut and locked.",
  ]));
}

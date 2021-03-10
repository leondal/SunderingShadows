#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("State road beside the marketplace");
  set_long(
  "State road beside the marketplace.\n"
  "  State road runs north and south here, with a small side road running west to Tanar road."
    "  Torm's great open marketplace overflows onto the road here from the west." 
  "  Many vendors wander the marketplace hawking their goods to the people of all the lands of shadow who wander about searching for what they need."
  );
  set("night long",
  "%^BLUE%^"
    "A great empty marketplace fades into the fog to the west.  Roads"+
   " run north, south and east from here but it is hard to tell where"+
   " they lead in the dark of night with all the fog."
  );
  set_exits(([
  "north":TCITY+"c54",
  "east":TCITY+"c63",
  "south":TCITY+"c72",
  "west":TCITY+"c61",
  ]));
}
void reset(){
   ::reset();
   if(query_night()) return;
   if(!present("buemor",TO)) {
      new(MON+"armorer1.c")->move(TO);
      new(MON+"citizen.c")->move(TO);
   }
}

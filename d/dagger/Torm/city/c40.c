#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Main street Torm, by the west gates");
  set_long(
  "Main street Torm, by the west gates.\n"
    "  You stand just inside Torm's west gates."
    "  Main street runs east to the city's center while Tanar street goes north and south following the walls around the city."
    "  All around you the citizens of Torm go about their buisness with a great many travelers from distant ports here as well going about their business."
  );
  set("night long",
  "%^BLUE%^"
    "The bronze gates of Torm lie closed to the West while the city lies"+
  " dark and lifeless in all other directions.  This is a town that"+
  " rises at the crack of dawn and goes to bed at sunset it seems."
    "  A light fog blankets everything around you, making the footing"+
   " a bit treacherous.  Main street runs west while Tanar road runs"+
   " north and south disappearing into the night."
  );
   add_item("gates","You can see the large city gates to the west.");
  set_exits(([
  "up":TCITY+"c40a",
  "north":TCITY+"c32",
  "east":TCITY+"c41",
  "west":TCITY+"c1",
  "south":TCITY+"c51",
  ]));
}
void reset(){
  ::reset();
  if(!present("torm guardsman",TO)) {
     new(MON+"guard2.c")->move(TO);
  }
}

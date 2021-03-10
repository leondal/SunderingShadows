#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_short("Boardwalk on the Dagger Sea");
  set_long(
   "Boardwalk on the Dagger Sea.\n"
   "  The Dagger Sea stretches out to the eastern horizon while Torm's"+
   " cityline is dotted with spires to the west.  Small birds fly about,"+
   " hunting for scraps from meals, or preferably a tasty fish.  Sailors"+
   " wander about the boardwalk mingling with the citizens of Torm out"+
   " here for their own reasons, whatever they might be.  Many ships are"+
   " in the process of docking, unloading or leaving for other ports."
  );
  set("night long",
 "%^BLUE%^"
    "The Dagger Sea is covered in a light fog that sends wispy tendrils"+
    " out into the city.  Beneath your feet are the dark waters of the"+
    " sea that seem almost to be a bottomless black void, you can't even"+
    " make out the tallest of the waves.  The boardwalk is quiet at"+
    " night, with most of the citizens already gone to bed, and few"+
    " ships daring to brave the rocks that are hidden by the fog to"+
    " dock here at night.  The planks beneath your feet are slightly"+
    " damp, and you must be careful of your footing."
  );
  set_smell("default",
  "You smell salt in the air from the Dagger Sea."
  );
  set_listen("default",
  "The waves of the sea wash against the docks."
  );
  set_items(([
  ]));
}
void reset(){
  int i,j;
  ::reset();
  j=random(3);
  if(query_night()) return;
  if(!present("dayperson")) {
     switch(random(10)) {
        case 0..1:
           new(MON+"citizen.c")->move(TO);
           break;
        case 2:
           new(MON+"fisherman.c")->move(TO);
           break;
        case 3..4:
           new(MON+"citizen.c")->move(TO);
           break;
        case 5:
           new(MON+"guard2.c")->move(TO);
           break;
        case 6..7:
           new(MON+"piratec.c")->move(TO);
           break;
        case 8..9:
           new(MON+"dockworker.c")->move(TO);
           break;
     }
  }
  if(!present("sea gull")) {
    new(MON+"seagull.c")->move(TO);
  }
}

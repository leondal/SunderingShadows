#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_short("Boardwalk on the Dagger Sea");
  set_long(
   "  The Dagger Sea stretches out to the horizons to the east while Torm's cityline is dotted with spires to the west."
  "  Small birds and sailors wander about the boardwalk mingling with the citizens of Torm out here for their own reasons, whatever they might be."
   "  To the south the door of a nice looking restaurant stands open, inviting all those of the higher classes who don't have to work during the day to come in, sit down, and have a cool drink and fine meal."
  );
  set("night long",
 "%^BLUE%^"
    "Fog spills off the Dagger Sea into the city of Torm, clinging to"+
   " the ground and making it sometimes difficult to tell where you're"+
  " going.  The planks of the boardwalk beneath your feet are slightly"+
  " damp and your footing is a little treacherous.  You can hear the"+
  " waves crashing against the rocks, letting you know that the sea"+
  " is around you.  The boardwalk continues to the north, but just"+
  " to the south is a large restaurant with the door closed against"+
  " the chill night air, but you can see lights on inside."
  );
   add_item("restaurant","The restaurant to the south looks like a fine establishment indeed.  An image of a seahorse hangs over the door.");
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","The waves of the sea wash against the docks.");
  set_exits(([
  "north":TCITY+"c87",
  "south":TCITY+"c94",
  ]));
  set_door("door",TCITY+"c94","south","Torm masterkey");
   if(query_night() == 1) {
      set_open("door",0);
      "/d/dagger/Torm/city/c94"->set_open("door",0);
   }
   else {
      set_open("door",1);
      "/d/dagger/Torm/city/c94"->set_open("door",1);
   }
}

void reset(){
  int i,j;
  ::reset();
  j=random(3);
  if(!query_night()) {
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
         if(!present("sea gull",TO)){
            new(MON+"seagull.c")->move(TO);
         }
      }
   }
}

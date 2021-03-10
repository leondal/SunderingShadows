#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit VAULT;

void create() {
    ::create();
   set_travel(DIRT_ROAD);
   set_terrain(BEACH);
    set_property("light", 2);
  set_open("gates",1);
  set_door("gates",TCITY+"c89","north","Torm masterkey");
  set_short("South of the south gates of Torm");
    set_long(
  "%^CYAN%^"
  "The walls of Torm run east and west of here with a gate just to your"+
  " north leading into it.  A great golden beach starts almost from the"+
  " south of the walls which come right to the edge of the sea.  Small"+
  " huts can be seen to the east along the coast of the sea."
    );
  set("night long",
  "%^BLUE%^"
  "The walls of Torm run east and west of here with a closed gate just"+
  " to your north blocking off the city.  Although the gates remain"+
  " closed, they are not kept locked, and anyone entering or leaving"+
  " by them is asked to close them afterwards.  Most of the shops are"+
  " probably closed, however, but will open again at the crack of dawn."
  );
    set_items(([
  "spires" : "Great spires rise above a few grand buildings in the city.",
  "sea" : "The great Dagger Sea stretches off to the horizon. A few"+
  " ships lay anchored off the city waiting to dock.",
      ]));
    set_exits(([
  "southwest":ROAD+"path21",
  "north":TCITY+"c89",
  "east":ROAD+"path23",
      ]));
  set_listen("default","Seabirds chirp in the air over the boardwalks.");
    set_smell("default","Salty sea air mixes with the smells of many types of cooking.");
   if(query_night() == 1) {
      set_open("gates",0);
      "/d/dagger/Torm/city/c89"->set_open("gates",0);
   }
   else {
      set_open("gates",1);
      "/d/dagger/Torm/city/c89"->set_open("gates",1);
   }
}

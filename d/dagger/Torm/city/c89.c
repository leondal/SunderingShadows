#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_door("gates","/d/dagger/Torm/road/path22","south","Torm masterkey");
  set_open("gates",0);
  set_short("South gates of Torm");
  set_long(
  "South gates of Torm.\n"
    "  The gates of Torm hang open here to accommodate all travelers through its walls."
    "  Even closed they don't look like they'd keep anyone out, but the thought makes you feel this is an open city to the visitors of the lands."
    "  This gate appears less used than the other main one to the west, mainly because the only ones through here are the fishermen that live south of the city along the sandy shores of the Dagger Sea."
  );
  set("night long",
  "%^BLUE%^"
    "The gates of Torm lie closed at night.  Travelers who are coming"+
   " and going are asked to please close the gates after their entrance"+
   " or departure.  A light fog blankets the ground and obscures some"+
  " of the streets from view."
  );
  set_exits(([
  "north":TCITY+"c81",
  "south":ROAD+"path22",
  ]));
   if(query_night() == 1) {
      set_open("gates",0);
   }
   else {
      set_open("gates",1);
   }
}
void reset(){
  ::reset();
  if(!(query_night())) {
     if(!present("torm guard",TO)) {
        new(MON+"guard4.c")->move(TO);
     }
  }
}

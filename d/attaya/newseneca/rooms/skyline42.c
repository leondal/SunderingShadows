//skyline42
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To the east is a larger yard "+
      "leading to a shop with a %^GREEN%^green roof%^RESET%^, "+
      "while to the west you see the entrance to a %^ORANGE%^"+
      "stable%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"stable",
      "east" : ROOMS"souveniryard",
      "north" : ROOMS"skyline41",
      "south" : ROOMS"skyline43"
   ]));
   set_door("sliding door","/d/attaya/newseneca/rooms/stable","west",0,0);
   set_door_description("sliding door","%^ORANGE%^This wide door "+
      "slides back, leaving a large opening through which to bring "+
      "in mounts.  The door is reinforced with iron bands and has "+
      "an even stronger outer door that can be let down in storms.%^RESET%^");
   set_door("gate","/d/attaya/newseneca/rooms/souveniryard","east",0);
   set_door_description("gate","%^ORANGE%^This small gate separates "+
      "Sol Boulevard from the small pathway leading to a shop "+
      "in the east.%^RESET%^");
   if(query_night()==1){
      set_open("sliding door",0);
      "/d/attaya/newseneca/rooms/stable"->set_open("sliding door",0);
   }else{
      set_open("sliding door",1);
      "/d/attaya/newseneca/rooms/stable"->set_open("sliding door",1);
   }
}
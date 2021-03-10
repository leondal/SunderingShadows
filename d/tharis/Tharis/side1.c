//side1.c
//updated by Circe 12/17/04 with new desc, etc.
#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
   set_property("no sticks",1);
   set_property("light",2);
   set_name("A short side street");
   set_short("A short side street");
   set_long(
@JAVAMAKER
%^MAGENTA%^A Short Side Street%^RESET%^
This short side street is close-quartered.  The large %^BOLD%^stone
walls %^RESET%^are very close here, making you the press of passersby 
almost as if you were in a cattle shoot.  Most people seem 
to keep quiet with their heads down, moving quickly into and
out of the %^ORANGE%^building %^RESET%^to the southeast.
JAVAMAKER
   );

   set_smell("default","The smells of the city mingle around you.");
   set_listen("default","The low hum of the crowd can be heard around you.");
   set_items(([
      ({"walls","wall"}) : "The walls here are close.  You "+
         "feel them weigh in on you.  At times you think this "+
         "part of Tharis was very well carved straight from the "+
         "mountain.",
      ({"store","building","general store"}) : "The store to the "+
         "southeast seems to be a general store.  People emerge "+
         "from it carrying all manner of packages and parcels."
   ]));

   set_exits(([
      "door":ROOMS"general",
      "northwest":ROOMS"main6"
   ]));
   set_door("door",ROOMS"general","door","blah");
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/
//side2.c
//updated by Circe 12/17/04 with new desc
#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
   set_property("no sticks", 1);
   set_property("light",2);
   set_name("A short side street");
   set_short("A short side street");
   set_long(
@JAVAMAKER
%^MAGENTA%^A short side street%^RESET%^
This short side street is close-quartered.  The large %^BOLD%^stone
walls%^RESET%^ are very close here.  You hear the bustle of a busy
%^YELLOW%^tavern %^RESET%^coming through the closed door to the southwest.
As people pass, you see some patting their bellies with a 
satisified look.
JAVAMAKER
   );
   set_smell("default","The smells of bread and meat waft through "+
      "the door as it opens and closes.");
   set_listen("default","The low hum of the crowd can be heard around you.");
   set_items(([
      ({"walls","wall"}) : "The walls here are close.  You "+
         "feel them weigh in on you.  At times you think this "+
         "part of Tharis was very well carved straight from the "+
         "mountain.",
      ({"bar","tavern","building"}) : "The squat building to the "+
         "southwest is made of aged wood and seems to have stood "+
         "the test of time.  Light pours through the windows, along "+
         "with the sound of raucous laughter."
   ]));
   set_exits(([
      "door":ROOMS"tavern",
      "northeast":ROOMS"main6"
   ]));
   set_door("door",ROOMS"tavern","door",0);
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/
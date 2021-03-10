#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("Inside the Canyon");
   set_short("Inside the Canyon");
   set_long("%^BOLD%^Inside the Canyon%^RESET%^\n"
"You are deep in the canyon now.  It is cool and dark here.  The canyon walls rise up on both sides, closing "
"you in.  This is an oppressive place.  It is very dark and gloomy here.  The light that reaches the canyon "
"from the outside is very dim.\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You hear the sound of crumbling bits of rock and dirt falling.");

   set_items(([
     ({"canyon walls","walls"}) : "The granite canyon walls are cool to the touch, small streams of "
"%^BOLD%^%^CYAN%^water%^RESET%^ trickle from them.",
     "water" : "This is %^BOLD%^%^CYAN%^clear water%^RESET%^ running out of the rocks."
   ]));

   set_exits(([
     "south":CAVES"canyons3",
     "east":CAVES"canyons5"
   ]));
}

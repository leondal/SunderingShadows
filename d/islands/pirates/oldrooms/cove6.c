//cove6.c

#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){ 
set_monsters(({MON"citizen.c"}),({3}));
   ::create();
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);

   set_short(
@JAVAMAKER
Main Street
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^WHITE%^Main Street Near Trail%^RESET%^
You have entered the shabby village.  You can hear the 
cries of the vendors in the market.   Shadows pass around
you making you clutch your purse and watch your back.
To the north hangs a sign saying Shawologon's Weapons.
To the south hangs a sign saying Apliton's Armor.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");
   set_items(([
       "ocean":"The ocean spreads out before you to the horizon.",
       "village":"You now have a clear view of the village buildings.  They seem to have been built out of pieces of old ships.",
      "Bridge":"This stone bridge looks sturdy enough.",
      "streets":"The streets are more like paths but they get the job done.",
   ]));

   set_exits(([
      "south":CAVES"armor",
      "north":CAVES"weapon",
"east":CAVES"cove5",
"southwest":CAVES"cove7"
   ]));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}








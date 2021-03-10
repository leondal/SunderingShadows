//armor.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_short("Apilton's Armor Shop");
   set_long(
@JAVAMAKER
%^BOLD%^%^WHITE%^Apliton's Armory%^RESET%^
This run down building is Apilton's armor shop.  It's more like
junk shop with bits and pieces of rusted armor lie about the place.
A counter is along the east wall of the place.  The exit is to the 
the north.
JAVAMAKER
   );

    set_smell("default","You smell the hot forge.");
    set_listen("default","The clank of the hammer against an anvil.");
   set_items(([
       "scraps":"You can see bits and scraps of rusted armor, toughened hide, and metal shavings.  This place is a mess.",
       "counter":"This beaten old counter looks like it was made from the captain's desk of an old ship.",
   ]));

   set_exits(([
      "north":CAVES"cove6",
   ]));
}


void reset(){
   ::reset();
      if(!present("apilton")){
        new(MON+"apliton")->move(TO);
      }
}

void init(){
   ::init();

}








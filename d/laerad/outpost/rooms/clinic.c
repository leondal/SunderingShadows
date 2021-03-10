#include <std.h>
#include "../outpost.h"
inherit HEALER;
void create()
  {
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
    set_short("Outpost healer");
  set_property("light",2);
  set_property("indoors",1);
  set_long(
    "Torm Outpost healing clinic\n"+
    "%^BOLD%^%^WHITE%^This is still a rough house where many of the inside walls still only consist of rough wooden boards. The walls "+
	"are full of shelves with countless of vials, bottles and various herbs. In the end of the room a large table. serving both as counter "+
	"and as operation table are places and right behind it is the owner of the clinic%^RESET%^.\n"
  );
   set_smell("default","The clinic smells of astringents and herbs.");
    set_listen("default","You can hear the groans of some of the patients.");
   set_items(([
   "table" : "The table is cleanly dressed in white linen to help prevent transference of disease.",
   "floor" : "The floor is kept immaculately clean.",
   "herbs" : "There is a shelf of herbs in one corner of the room, it has many different types on it, some fresh and some dried.",
   ]));
  set_name("alexandia");
  set_exits(([
  "south":ROOMS"11",
  ]));
}

void reset(){
  ::reset();
  if(!present("alexandia")){ new(MOBS"healer")->move(TO);}
  set_name("alexandia");
  }

  
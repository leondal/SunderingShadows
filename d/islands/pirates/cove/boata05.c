#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"pirateguard",MON"pirateguard2"}),({1,1}));
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Corridor");
   set_short("Corridor");
   set_long("%^BOLD%^Corridor%^RESET%^\n"
"This dark hallway leads to the sleeping quarters of the ship's pirates.  The floor, walls and roof are all "
"made of the same old %^ORANGE%^wood%^RESET%^, creaking as the boat rocks on the water.  Very little light "
"reaches here, making it hard to distinguish much amidst the %^BLACK%^%^BOLD%^shadows%^RESET%^.  There is "
"the outline of a doorway on either side of the corridor here, and another at the far end.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"floor","walls","roof","wood"}):"The floor, walls and roof are all made of the same old%^ORANGE%^ "
"wood%^RESET%^, that creaks as the ship moves.  The wood looks quite old, and is in desperate need of a "
"polish.",
     ({"doorway","doorways"}):"There are the outlines of three doorways here - one on either side of the "
"corridor, and another at the far end.",
     "shadows":"The corridor is shrouded in %^BLACK%^%^BOLD%^shadow%^RESET%^, making it hard to distinguish "
"details of the area around you."
   ]));
   set_exits(([
     "maindeck":COVE"boata02",
     "east":COVE"boata06",
     "west":COVE"boata07",
     "south":COVE"boata08"
   ]));
   set_pre_exit_functions(({"south",}),({"GoThroughDoor",}));
}

int GoThroughDoor(){
   if(avatarp(TP)) return 1;
   if(!present("pirate")) return 1;
   tell_object(TP,"The guards are in your way, there's no way you can push or sneak past them.");
   return 0;
}

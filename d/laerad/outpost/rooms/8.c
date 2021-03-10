#include <std.h>
#include "../outpost.h"

inherit STORAGE"road";

void create(){
   ::create();
   set_long(TO->query_long()+"%^BOLD%^%^BLACK%^There is a sign hanging over a open door on the western building%^RESET%^\n");
   add_item("sign","%^ORANGE%^This is a common wooden sign. %^BOLD%^%^WHITE%^Captains Dalvin's office.");
   set_exits(([
      //"southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  "south" : ROOMS"9",
	  "west" : ROOMS"office",
	  "north" : ROOMS"7",
   ]));

}
#include <std.h>
#include "../outpost.h"

inherit STORAGE"road";

void create(){
   ::create();
   set_long(TO->query_long()+"%^BOLD%^%^BLACK%^There is a sign hanging over a closed door on the northern building.%^RESET%^\n");
   add_item("sign","%^ORANGE%^This is a common wooden sign. %^BOLD%^%^WHITE%^Rations office opening soon.");
   set_exits(([
      //"southwest" : ROOMS"4",
      //"northeast" : ROOMS"5",
	  "south" : ROOMS"8",
	  "west" : ROOMS"6",
   ]));

}

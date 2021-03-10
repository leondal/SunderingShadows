#include <std.h>
#include "../elf.h"


inherit WATER;

void create(){
   ::create();
    set_short("%^BOLD%^BLUE%^Sunken Tower%^RESET%^");
    set_long(query_short()+"\nThis is a sunken leaning tower.  "+
    "Only the top with ramparts is showing.  The rest is "+
    "sunken into the gray mud.  There are some steps going"+
    " down into darkness.  While the tower is sunken, the "+
    "interior seems to still be accessable.");
    set_smell("default","It is hard to smell being underwater.");
    set_listen("default","You hear the swushing of water currents.");
   set_exits(([
      "down" : ROOMS"/shore/tower1",
      "south" : ROOMS"/shore/ruin15",
   ]));
   set_items(([
      (({"tower"})) :
        "This is the remains of a tower.  It is tilted and sticking out of the gray mud.",
      (({"ramparts","rampart"})) : "only the ramparts of this tower are showing.  The rest is sunken into the mud.",
 	   ]));
}


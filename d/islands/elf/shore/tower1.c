#include <std.h>
#include "../elf.h"


inherit WATER;

void create(){
   ::create();
    set_short("%^BOLD%^BLUE%^Sunken Tower%^RESET%^");
    set_long(query_short()+"\nThis is a room within the sunken "+
    "tower.  The place is in ruins but it looks like it might"+
    " have been a study for a mage's tower.  Remains of ruined"+
    " items lay scattered about.  It is dark and looks like "+
    "anything of value was ruined long ago.");
    set_smell("default","What does sea water smell like?");
    set_listen("default","You hear the swushing of water currents.");
   set_exits(([
      "up" : ROOMS"/shore/tower0",
   ]));
   set_items(([
      (({"tower"})) :
        "This is the remains of a tower.  It is tilted and sticking out of the gray mud.",
 	   ]));
}
void reset(){
   ::reset();
   if(!present("daelas",TO))
     new(MON"daelas")->move(TO);
}

#include <std.h>
#include "../elf.h"


inherit WATER;

void create(){
   ::create();
    set_short("%^BOLD%^BLUE%^Castle Ruins%^RESET%^");
    set_long(query_short()+"\nThis is the underwater ruins"+
    " outside a %^CYAN%^castle%^RESET%^.  Everything is mostly"+
    " bricks half burried in the sea %^CYAN%^floor%^RESET%^.  "+
    "There is a gate leaning into the crumpled keep to the south."+
    "Maybe at one time this was the entrance to a powerful fort.");
    set_smell("default","It is hard to smell being underwater.");
    set_listen("default","You hear the swushing of water currents.");
   set_exits(([
      "north" : ROOMS"/shore/ruin12",
      "south" : ROOMS"/shore/castle1",
   ]));
   set_door("gate",ROOMS"/shore/castle1","south","nokey");
   set_open("gate",0);
   set_locked("gate",0);
   set_items(([
      (({"castle"})) :
        "This is the remains of a castle.  It is almost completely destroyed and covered in the mud of the sea floor.",
      (({"floor"})) : "The sea floor is mostly gray mud.",
 	   ]));
}


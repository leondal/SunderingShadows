//cave22.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of "+
      "this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic "+
      "workmanship suggest "+
      "that the dwarves who make their home here have expanded "+
      "and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings "+
      "%^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed "+
      "every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march "+
      "along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab "+
      "walls of the tunnels.  Two tunnels "+
      "intersect here, with one leading and south and the "+
      "other heading west."
      "\n"
    );

    set_exits(([
        "north" : ROOMS"cave24",
        "south" : ROOMS"cave23",
        "west" : ROOMS"cave21"
   	]));

}
/*
void reset() {
  ::reset();
  if(!present("guard")) {
   if(sizeof(children(MOBS"dwarf")) < 10) 
    new(MOBS"dwarf")->move(TO);
  }
}
*/
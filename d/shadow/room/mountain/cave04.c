//cave04.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship suggest "+
      "that the dwarves who make their home here have expanded and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls of the tunnels.  A few "+
      "strange bones are scattered on the floor here."
      "\n"
    );
    add_item("bones","Several long bones lie on the floor.  None of them has any meat left at all, and "+
      "they all have been gnawed extensively.  It seems perhaps something viscious might live "+
      "in this cave.");
    set_exits(([
        "south" : ROOMS"cave03",
        "north" : ROOMS"cave05"
   	]));
}

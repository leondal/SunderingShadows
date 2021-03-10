//cave06.c
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
      "creating a sense of being in the open air despite the drab walls of the tunnels.  A large "+
      "%^BOLD%^%^BLACK%^hole %^RESET%^is in the ceiling here, and from it, a %^ORANGE%^knotted "+
      "rope %^RESET%^dangles."
      "\n"
    );
    add_item("rope","The sturdy rope hanging from the ceiling has been knotted at intervals.  It "+
      "would probably be easy to climb.");
    add_item("hole","The large hole it the ceiling is nearly perfectly round and allows a bit "+
      "of light in from the upper level.");
    set_exits(([
        "up" : ROOMS"cave03",
        "west" : ROOMS"cave07",
        "east" : ROOMS"cave09"
   	]));

}

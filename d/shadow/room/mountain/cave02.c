//cave02.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this "+
      "tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic "+
      "workmanship suggest "+
      "that the dwarves who make their home here have expanded and "+
      "improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings "+
      "%^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every "+
      "fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along "+
      "the walls between the arches, "+
      "creating a sense of being in the open air despite the drab "+
      "walls of the tunnels.  Light pours "+
      "in from the south, while further north it fades into darkness."+
      "\n"
    );
    set_exits(([
        "south" : ROOMS"cave01",
        "north" : ROOMS"cave03"
   	]));
}

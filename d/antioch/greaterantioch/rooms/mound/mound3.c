#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "west"  : MOUND"mound2",
      "east"  : MOUND"mound7",
      "north" : MOUND"mound4",
      "south" : MOUND"mound9",
   ]));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^The tunnel opens here widely in what looks to be"+
            " a large living area. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel continues in all directions here,"+
            " branching out throughout the area.";
}

string thislong(){
   return b_long+roomlong+a_long;
}

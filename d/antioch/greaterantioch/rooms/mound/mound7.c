#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "west"  : MOUND"mound3",
      "east"  : MOUND"mound8",
   ]));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^The tunnel narrows here sharply as it slopes out"+
            " of the main chamber to the west. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel continues to the east, sloping,"+
            " deeper into the mound.";
}

string thislong(){
   return b_long+roomlong+a_long;
}

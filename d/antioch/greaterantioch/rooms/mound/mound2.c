#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "west"  : MOUND"mound1",
      "east"  : MOUND"mound3",
   ]));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^The tunnel narrows here slightly, sloping more steeply"+
            " as it continues deeper into the hole. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel continues to the east, moving more"+
            " rapidly to the depths of the mound, which seems to open up to the"+
            " east.";
}

string thislong(){
   return b_long+roomlong+a_long;
}

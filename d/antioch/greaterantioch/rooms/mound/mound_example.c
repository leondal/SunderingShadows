#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, n_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "out"   : FOOTHILLS"foothills37",
      "east"  : MOUND"mound2",
   ]));
   roomlong = MOUNDINH->query_long();
   n_long = "%^BOLD%^%^RED%^This is some new stuff to see if this way works.%^RESET%^  ";
}

string thislong(){
   return n_long+roomlong;
}

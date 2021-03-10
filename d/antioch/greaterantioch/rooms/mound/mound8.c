#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "west"  : MOUND"mound7",
   ]));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^The tunnel ends here at a rough wall. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel cannot continue to the east, making you have to turn around.";
}

string thislong(){
   return b_long+roomlong+a_long;
}

#include <std.h>
#include "../../newbie.h"
inherit VAULT;

void init() {
   ::init();
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   tell_object(TP,"%^YELLOW%^Offestry town has been updated! Transporting you "
"back to the square.%^RESET%^");
   TP->move(MAINTOWN"square");
}

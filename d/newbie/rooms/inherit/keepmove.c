#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

void init() {
   ::init();
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   tell_object(TP,"%^YELLOW%^Offestry Keep has been updated! Transporting you "
"back to the start.%^RESET%^");
   TP->move(ROOMS"path1");
}

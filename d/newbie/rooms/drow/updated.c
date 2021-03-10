#include <std.h>
#include "../../newbie.h"
inherit VAULT;

void init() {
   ::init();
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   tell_object(TP,"%^YELLOW%^The drow caverns have been moved and changed! Transporting you back to the ruins.%^RESET%^");
   TP->move("/d/newbie/rooms/ruins/church2");
}

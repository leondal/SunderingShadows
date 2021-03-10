#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   ::create();
   
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail ends here at a large %^BOLD%^%^BLACK%^"+
   "hole%^RESET%^%^GREEN%^ in the ground or continues northward.%^RESET%^");
   set_exits(([
    "northeast":FROAD+"16",
   ]));
   
   add_item(({"hole", "large hole"}), "%^BOLD%^%^BLACK%^You can make out that the hole opens into a large "+
   "cavern. You could %^RED%^descend%^BOLD%^%^BLACK%^ into it if you had the proper tools and were "+
   "so inclined.%^RESET%^");
   
   set_climb_exits((["descend" : ({CAVES"dn1", 5, 5, 100}) ]));
   set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
}

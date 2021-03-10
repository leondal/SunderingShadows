//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JALLEY;

void create(){
    	::create();
         set_search("default","You find a hidden passage leading %^BOLD%^%^BLACK%^down%^RESET%^ into the %^BOLD%^%^BLACK%^darkness%^RESET%^.");
    	set_exits(([
                "north" : JROOMS+"a5",
                "down" : "/d/underdark/juran/tun01"
    	]));
   set_invis_exits(({"down"}));
}

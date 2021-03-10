#include <std.h>
#include "../defs.h"
inherit INH+"alley";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  To the northwest, you can see where this street meets with one of the main "
"thoroghfares of the city.%^RESET%^\n");

   add_item(({"houses","buildings","walls"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, obviously "
"belonging to very high-ranked houses by their extravagant architecture and style.  To the east is a grand enclosure with "
"high walls of %^ORANGE%^s%^BOLD%^%^BLACK%^ton%^RESET%^%^ORANGE%^e %^BLUE%^that allow no ability to see within, although "
"you can often hear the sounds and shouts of combat floating over them.  To the west, the rear of a fenced compound "
"encloses a massive stalactite that sweeps down from the ceiling to the cavern's floor.  You can see smaller stalagmites "
"rising up around it from here with %^WHITE%^finely-w%^BOLD%^%^WHITE%^rou%^RESET%^ght me%^BOLD%^ta%^RESET%^l bridges "
"%^BLUE%^spanning the gaps between each one.  In the northwestern portion of the enclosure is another pillar that reaches "
"toward the roof, this one made of %^BOLD%^%^BLACK%^black ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^.%^RESET%^");
   set_exits(([
     "northwest":ROOMS"northeast2",
     "south":ROOMS"alley11",
   ]));
}

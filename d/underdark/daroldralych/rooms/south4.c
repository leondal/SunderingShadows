#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what is probably "
"the middle-class section of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n"
"%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d%^BOLD%^"
"%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the ceiling "
"too high up to be seen by any form of normal vision.  At short intervals along the length of the street are slender "
"carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of pale "
"%^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  In the distant north, this "
"street meets the city square, while just to the south you can see a closed gate.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"mid-ranked houses judging by their appearance.  The western enclosure consists of several short, sturdy buildings, only "
"one of which seems large enough to contain living quarters for a drow house.  From the others echoes the %^RED%^l%^BOLD%^"
"o%^YELLOW%^u%^RESET%^%^RED%^d %^BLUE%^impact of metal upon metal.  The buildings of the eastern side bear little of "
"interest, none standing out against another; if nothing else, they bear less of the magnificent architecture seen "
"elsewhere in the city.  No doubt to the east lies a lower-class section of town.%^RESET%^");
   set_exits(([
     "north":ROOMS"south3",
     "south":ROOMS"outer11",
   ]));
}

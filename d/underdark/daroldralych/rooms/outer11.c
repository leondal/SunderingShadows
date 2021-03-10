#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^You stand at the intersection of two major roads, one of which runs in a circuit around the city's outer limits"
", while the other leads directly to its heart.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^"
"n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d"
"%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the "
"ceiling too high up to be seen by any form of normal vision.  At short intervals along the length of the street are "
"slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of "
"pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  Rising up on the "
"southern side of the road are the walls of the cavern, dotted with the occasional mid- or lower-class drow house carved "
"into the dull surface of the rock itself.  Due south of here lie closed gates.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^The northern corners of the street is bordered by the city's buildings.  To "
"the west are the middle-class residences, but gradually moving east they lose much of their flourish and style, probably "
"bordering on what passes for a lower-class section of this city.%^RESET%^");
   add_item(({"wall","walls"}),"%^BLUE%^The southern side of the road is bordered by the walls of the cavern, which rise "
"up and disappear into the %^MAGENTA%^da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ke%^BOLD%^%^BLACK%^ne%^RESET%^%^MAGENTA%^d "
"%^BLUE%^limits of your vision above.  The occasional signs of a mid- or lower-class drow house are dotted across its "
"stony surface, carved into the face of the rock itself.  If anything, there seem far more living spaces situated within "
"this vast cavern's walls than upon its floor, sign perhaps that only the most prestigious of lineages are afforded the "
"central space.%^RESET%^");
   set_exits(([
     "north":ROOMS"south4",
     "south":ROOMS"gatesouth",
     "east":ROOMS"outer12",
     "west":ROOMS"outer10",
   ]));
}

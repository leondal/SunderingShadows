#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what seems perhaps "
"to be the slums, though in such a fine city as this, that can only be seen in a lack of delicate architecture and the "
"occasional empty building.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^"
"e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar"
"%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the ceiling too high up "
"to be seen by any form of normal vision.  At short intervals along the length of the street are slender carved posts of "
"%^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae"
"%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  A fair distance to the northwest this "
"street meets the city square.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"the lowest-ranked houses.  They bear little of interest, none standing out against another; if nothing else, they bear "
"less of the magnificent architecture seen elsewhere in the city.  No doubt you stand within a lower-class section of "
"town.");
   add_item(({"street","streets"}),"%^BLUE%^The stone street is smooth beneath your feet, although it seems a little more "
"%^ORANGE%^gru%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^by %^BLUE%^here than elsewhere in the city.%^RESET%^");
   set_exits(([
     "northwest":ROOMS"southeast2",
     "southeast":ROOMS"outer16",
   ]));
}

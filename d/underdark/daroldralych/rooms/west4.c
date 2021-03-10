#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what must be the "
"upper-class section of the city, judging by the buildings on either side of you.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^"
"t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for "
"ease in walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s"
"%^BLUE%^ fills the air above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals "
"along the length of the street are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^"
"%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint "
"light around it.  In the distant east, this street meets the city square, while just to the west you can see a small "
"gate leading out of the city.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings.  To the north is a "
"large, round-shaped building of grand size, carrying balconies and bridges lit by the faint glow of %^MAGENTA%^fae"
"%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^, clearly an upper-class house by the extravagance of its design.  To the "
"south is what must be only a mid-ranked house, particularly elegant in its design, but far smaller and almost delicate "
"in stature.%^RESET%^");
   set_exits(([
     "east":ROOMS"west3",
     "west":ROOMS"outer4",
   ]));
}

#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what is obviously "
"the upper-class section of the city, judging by the buildings on either side of you.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^"
"t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for "
"ease in walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s"
"%^BLUE%^ fills the air above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals "
"along the length of the street are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^"
"%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint "
"light around it.  To the southeast this street meets the city square, while the northwestern road leads into the "
"warehouse district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, obviously belonging "
"to very high-ranked houses by their extravagant architecture and style.  The buildings to the south re possibly the most "
"%^MAGENTA%^la%^RED%^vi%^MAGENTA%^sh %^BLUE%^you have seen in the entire city - a series of structures with slender towers"
", numerous balconies, and leaping spans that arc between the towers and stalagmites.  The northeastern house strikes "
"quite a contrast to this, as it seems more like a military compound than anything else.  Its lacks the usual grace of "
"drow architecture, instead much more rigid and sturdy in design.  You can see many soldiers moving about the grounds.  A "
"heavily guarded gate, marked with the insignia and name of the house, allows access to this house from the "
"road.%^RESET%^");
   add_item(({"gate","compound"}),({"%^BLUE%^A heavily guarded gate leads to the enclosed compound to the northeast, "
"where unusually sturdy and squat buildings can be seen, as well as the constant movement of drow soldiers.  The gate "
"itself is marked with the insignia and name of a drow house.%^RESET%^"," %^BOLD%^%^BLACK%^House "
"Zanyl'thirr%^RESET%^","drow"}));
   add_item(({"structure"}),"%^BLUE%^Within the southern compound rise the spires of a %^MAGENTA%^la%^RED%^vi"
"%^MAGENTA%^sh %^BLUE%^series of buildings.  Elegant spans leap from towers to balconies, fragile beyond belief but "
"standing nonetheless.  Surely this degree of stoneworking rivals even the finesse of surface elves.");
   set_exits(([
     "northwest":ROOMS"dock4",
     "southeast":ROOMS"square1",
   ]));
}

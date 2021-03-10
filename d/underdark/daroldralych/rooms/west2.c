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
"light around it.  South of the road is a small doorway, opening in from the street to what looks like a shop of sorts.  "
"To the east this street meets the city square, while distantly in the west you can see a small gate leading out of the "
"city.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"very high-ranked houses judging by their appearance.  On the southern side of the road is a complex of several sections, "
"designed more in simple %^CYAN%^e%^MAGENTA%^le%^CYAN%^ga%^MAGENTA%^nc%^CYAN%^e %^BLUE%^than the extravagance of the "
"upper houses, and with a lesser display of guardian force.  A doorway in from the street opens to one such section here"
", into what appears to be a scribe's office.  The buildings to the north, however, are possibly the most %^MAGENTA%^la"
"%^RED%^vi%^MAGENTA%^sh %^BLUE%^you have seen in the entire city.  The massive structure consists of slender towers, "
"numerous balconies, and arching bridges that leap between the stalagmites that surround it.%^RESET%^");
   add_item(({"complex","building","scribe"}),"%^BLUE%^South of the road lies a complex of many buildings, some extending "
"further down the street to the east.  They are designed with simple %^CYAN%^e%^MAGENTA%^le%^CYAN%^ga%^MAGENTA%^nc%^CYAN%^"
"e%^BLUE%^, nowhere near that of the northern compound but impressive nonetheless.  Here, too, there is less of a display "
"of guardian force, though whether their defenses are more subtle cannot be discerned from the street.  The closest part "
"of the compound is a building here that opens onto the street, into what appears to be a messenger's office.%^RESET%^");
   add_item(({"compound","structure"}),"%^BLUE%^To the north lies an extravagant compound, within which rise the "
"spires of a %^MAGENTA%^la%^RED%^vi%^MAGENTA%^sh %^BLUE%^series of buildings.  Elegant spans leap from towers to balconies"
", fragile beyond belief but standing nonetheless.  Surely this degree of stoneworking rivals even the finesse of surface "
"elves.");
   set_exits(([
     "east":ROOMS"west1",
     "west":ROOMS"west3",
     "south":ROOMS"poffice",
   ]));
}

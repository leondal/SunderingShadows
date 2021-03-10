#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what is probably "
"the upper or middle-class section of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d"
"%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the "
"ceiling too high up to be seen by any form of normal vision.  At short intervals along the length of the street are "
"slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of "
"pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  To the northeast this "
"street meets the city square, while a little southwest it opens out onto the busy marketplace.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"high- or mid-ranked houses judging by their appearance.  The enclosure to the southeast retains two buildings, one "
"smaller and with the appearance of living quarters, while the other is far larger.  You can't tell from here what would "
"be in the large building.  On the northwest side of the road is a complex of several sections, designed more in simple "
"%^CYAN%^e%^MAGENTA%^le%^CYAN%^ga%^MAGENTA%^nc%^CYAN%^e %^BLUE%^than the extravagance of the upper houses, and with a "
"lesser display of guardian force.  A relatively plain gate, marked with the insignia and name of the house, allows "
"access to this enclosure from the road.%^RESET%^");
   add_item("gate",({"%^BLUE%^A plain gate leads to the enclosed compound to the northwest.  It is marked with the "
"insignia and name of a drow house.%^RESET%^"," %^BOLD%^%^BLACK%^House Phaeraan%^RESET%^","drow"}));
   set_exits(([
     "northeast":ROOMS"square7",
     "southwest":ROOMS"southwest2",
   ]));
}

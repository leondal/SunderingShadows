#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is one of the city's main roads, leading out from the centre square through what is probably "
"the upper or middle-class section of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n"
"%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d"
"%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the "
"ceiling too high up to be seen by any form of normal vision.  At short intervals along the length of the street are "
"slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of "
"pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  At each side of the "
"road here, small alleys split apart from the main thoroughfare to wind away through the houses into %^BOLD%^%^BLACK%^s"
"%^RESET%^h%^BOLD%^%^WHITE%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^.  To the northeast this street meets the city "
//"square, while immediately southwest it opens out onto the busy marketplace.%^RESET%^\n");
"square, while immediately southwest, blockades have been set up to restrict any further passage.  There is definite "
"activity beyond, but it's hard to tell exactly what it entails.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"high- or mid-ranked houses judging by their appearance.  The enclosure to the east retains two buildings, one "
"smaller and with the appearance of living quarters, while the other is far larger.  You can't tell from here what would "
"be in the large building.  On the northern side of the road is a complex of several sections, designed more in simple "
"%^CYAN%^e%^MAGENTA%^le%^CYAN%^ga%^MAGENTA%^nc%^CYAN%^e %^BLUE%^than the extravagance of the upper houses, and with a "
"lesser display of guardian force.  A relatively plain gate, marked with the insignia and name of the house, allows "
"access to this enclosure from the road.%^RESET%^");
   add_item(({"alleys","alley","small alleys"}),"%^BLUE%^At either side of the road, small alleyways split away from the "
"main street and wind off into the %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^WHITE%^d%^RESET%^o%^BOLD%^%^BLACK%^ws %^RESET%^"
"%^BLUE%^between the houses.%^RESET%^");
   set_exits(([
     "northeast":ROOMS"southwest1",
//     "southwest":ROOMS"market4",
     "northwest":ROOMS"alley4",
     "southeast":ROOMS"alley5",
   ]));
}

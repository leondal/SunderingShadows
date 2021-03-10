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
"%^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  At each side of the road "
"here, small alleys split apart from the main thoroughfare to wind away through the houses into %^BOLD%^%^BLACK%^s"
"%^RESET%^h%^BOLD%^%^WHITE%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^.  To the north, this street meets the city "
"square, and to the south you can see a closed gate.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably belonging to "
"mid-ranked houses judging by their appearance.  The enclosure to the west retains two buildings, one smaller and with "
"the appearance of living quarters, while the other is far larger.  You can't tell from here what would be in the larger "
"one.  The buildings of the eastern side bear little of interest, none standing out against another.  They are well-made "
"as far as construction goes, but they most definitely lack the magnificence and grace of the upper-class buildings"
".%^RESET%^");
   add_item(({"alleys","alley","small alleys"}),"%^BLUE%^At either side of the road, small alleyways split away from the "
"main street and wind off into the %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^WHITE%^d%^RESET%^o%^BOLD%^%^BLACK%^ws %^RESET%^"
"%^BLUE%^between the houses.%^RESET%^");
   set_exits(([
     "north":ROOMS"south2",
     "south":ROOMS"south4",
     "west":ROOMS"alley6",
     "east":ROOMS"alley7",
   ]));
}

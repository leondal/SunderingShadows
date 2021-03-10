#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is obviously a major thoroughfare, part of the one that circuits the city's outer limits.  "
"Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground "
"beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^"
"%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the ceiling too high up to be seen by any form of "
"normal vision.  At short intervals along the length of the street are slender carved posts of %^BLACK%^%^BOLD%^ob"
"%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^"
"%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  Rising up on the northern side of the road are the walls "
"of the cavern, dotted with the occasional mid- or lower-class drow house carved into the dull surface of the rock itself"
".  The road continues east through what must be the upper-class section of the city, while the cavern opens abruptly at "
"a road junction just to the southwest, where the vast surface of the %^BOLD%^black lake %^RESET%^%^BLUE%^becomes "
"visible.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the southern side of the road rise the buildings of the upper-class.  "
"The closest one obviously belong to very high-ranked house, by its sheer size alone.  It is a grand enclosure with high "
"stone walls allows no ability to see within, although you can often hear shouts of %^RED%^c%^BOLD%^o%^RESET%^%^RED%^mbat "
"%^BLUE%^floating above the wall.%^RESET%^");
   add_item(({"wall","walls"}),"%^BLUE%^The northern side of the road is bordered by the walls of the cavern, which rise "
"up and disappear into the %^MAGENTA%^da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ke%^BOLD%^%^BLACK%^ne%^RESET%^%^MAGENTA%^d "
"%^BLUE%^limits of your vision above.  The occasional signs of a mid- or lower-class drow house are dotted across its "
"stony surface, carved into the face of the rock itself.  If anything, there seem far more living spaces situated within "
"this vast cavern's walls than upon its floor, sign perhaps that only the most prestigious of lineages are afforded the "
"central space.  The cavern walls drop away abruptly just to the west, where the vast surface of the %^BOLD%^black lake "
"%^RESET%^%^BLUE%^opens to view.%^RESET%^");
   set_exits(([
     "southwest":ROOMS"northeast2",
     "east":ROOMS"outer26",
   ]));
}

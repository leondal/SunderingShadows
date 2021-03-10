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
"%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  Rising up on the western side of the road are the walls of "
"the cavern, dotted with the occasional mid- or lower-class drow house carved into the dull surface of the rock itself.  "
"The road continues north through what must be the upper-class section of the city, while further south it intersects "
"with another street.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the eastern side of the road rise the buildings of the upper-class.  "
"The closest enclosure holds a large, round-shaped building of grand size, carrying balconies and bridges lit by the "
"faint glow of %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^, clearly an upper-class house by the "
"extravagance of its design.");
   add_item(({"wall","walls"}),"%^BLUE%^The western side of the road is bordered by the walls of the cavern, which rise "
"up and disappear into the %^MAGENTA%^da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ke%^BOLD%^%^BLACK%^ne%^RESET%^%^MAGENTA%^d "
"%^BLUE%^limits of your vision above.  The occasional signs of a mid- or lower-class drow house are dotted across its "
"stony surface, carved into the face of the rock itself.  If anything, there seem far more living spaces situated within "
"this vast cavern's walls than upon its floor, sign perhaps that only the most prestigious of lineages are afforded the "
"central space.  A %^BOLD%^%^BLACK%^tunnel%^RESET%^%^BLUE%^ branches away from the road here, leading past a heavily-"
"barred gate into the wall of the cavern.%^RESET%^");
   add_item(({"gate","tunnel"}),({"%^BLUE%^A heavily-barred gate prevents entry to the tunnel that leads into through the "
"western cavern wall from the road.  It is marked with the insignia and name of a drow house.  Behind it, you can see "
"where the tunnel opens into a large cavern, segregated from the city proper.%^RESET%^"," %^BOLD%^%^BLACK%^House "
"Desphrayl%^RESET%^","drow"}));
   set_exits(([
     "north":ROOMS"outer2",
     "south":ROOMS"outer4",
   ]));
}
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
"light around it.  On the northern side of the road is a small, squat stalagmite with an open doorway.  To the west this "
"street meets the city square, while distantly in the east is a gate leading out of the city.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings.  The northern "
"enclosure obviously belongs to very high-ranked house, by its extravagant architecture and style.  A fenced compound "
"encloses a massive stalactite of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y s%^RESET%^to%^BOLD%^%^BLACK%^ne"
"%^RESET%^%^BLUE%^, that sweeps down from the shadowed ceiling all the way to the cavern's floor.  Smaller stalagmites "
"rise up around it, all obviously inhabited, and with finely-wrought bridges of %^WHITE%^gl%^BOLD%^e%^RESET%^%^WHITE%^am"
"%^BOLD%^in%^RESET%^%^WHITE%^g ^%^BLUE%^metal spanning the gaps between each one.  One lone stalagmite in the "
"northwestern corner of the enclosure is separately fenced to the rest.  The buildings south of the road, however, are "
"far less elegant as they lead out of the upper-class sector.  They are well-made as far as construction goes, but they "
"most definitely lack the magnificence and grace of the northern buildings.%^RESET%^");
   add_item("stalagmite","%^BLUE%^A small, squat stalagmite sits at the northern side of the road.  It has obviously been "
"put to use as some sort of public facility, as the door has been left open.%^RESET%^");
   set_exits(([
     "west":ROOMS"east1",
     "east":ROOMS"east3",
     "north":ROOMS"library",
   ]));
}

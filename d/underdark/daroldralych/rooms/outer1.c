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
"The road continues south through what must be the upper-class section of the city, and to the north intersects with the "
"edge of the warehouse district.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon the eastern side of the road rise the buildings of the upper-class.  "
"The closest enclosure actually includes a section of the nearby warehouse district itself, full of smaller buildings "
"with a number of servants going to and fro conveying a variety of items.  Within the centre is a somewhat larger complex "
"that probably serves as the living quarters, as it still carries the particularly extravagant drow-style architecture of "
"the upper-class houses.  There is a tall, heavily-wrought gate here, marked with the insignia and name of the house, "
"that allows access to this house from the road.%^RESET%^");
   add_item(({"wall","walls"}),"%^BLUE%^The western side of the road is bordered by the walls of the cavern, which rise "
"up and disappear into the %^MAGENTA%^da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ke%^BOLD%^%^BLACK%^ne%^RESET%^%^MAGENTA%^d "
"%^BLUE%^limits of your vision above.  The occasional signs of a mid- or lower-class drow house are dotted across its "
"stony surface, carved into the face of the rock itself.  If anything, there seem far more living spaces situated within "
"this vast cavern's walls than upon its floor, sign perhaps that only the most prestigious of lineages are afforded the "
"central space.%^RESET%^");
   add_item("gate",({"%^BLUE%^A tall, heavily-wrought gate leads into the extravagant building to the east.  It is marked "
"with the insignia and name of a drow house.%^RESET%^"," %^BOLD%^%^BLACK%^House Ainenthraith%^RESET%^","drow"}));
   set_exits(([
     "north":ROOMS"dock1",
     "south":ROOMS"outer2",
   ]));
}

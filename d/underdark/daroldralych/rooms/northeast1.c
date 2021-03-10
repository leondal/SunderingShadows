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
"light around it.  To the southwest this street meets the city square, while to the southeast runs a short path up to a "
"stalagmite of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y s%^RESET%^to%^BOLD%^%^BLACK%^ne%^RESET%^%^BLUE%^.  "
"Northeast, the road curves away out of sight.%^RESET%^\n");

   add_item(({"houses","buildings"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, obviously belonging "
"to very high-ranked house, by their extravagant architecture and style.  To the southeast, a fenced compound encloses a "
"massive stalactite of %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y s%^RESET%^to%^BOLD%^%^BLACK%^ne%^RESET%^%^BLUE%^, "
"that sweeps down from the shadowed ceiling all the way to the cavern's floor.  Smaller stalagmites rise up around it, "
"all obviously inhabited, and with finely-wrought bridges of %^WHITE%^gl%^BOLD%^e%^RESET%^%^WHITE%^am%^BOLD%^in%^RESET%^"
"%^WHITE%^g ^%^BLUE%^metal spanning the gaps between each one.  One lone stalagmite in the northwestern corner of the "
"enclosure is separately fenced to the rest, and accessable from here by way of a short stone path.  The northwestern "
"house strikes quite a stark contrast to this, as it seems more like a military compound than anything else.  Its "
"lacks the usual grace of drow architecture, instead much more rigid and sturdy in design.  You can see many soldiers "
"moving about the grounds.%^RESET%^");
   add_item(({"path","stalagmite","stalactite"}),"%^BLUE%^To the southeast is an imposing compound.  Inside descends a "
"massive stalactite, reaching from the shadow-swept cavern roof above all the way to the ground, and surrounded by "
"smaller stalagmites on all sides.  One of these stalagmites has been separately fenced, and a short path leads into it "
"from here where a %^CYAN%^glo%^GREEN%^wi%^CYAN%^ng %^BLUE%^portal offers entry within.");
   set_exits(([
     "northeast":ROOMS"northeast2",
     "southwest":ROOMS"square3",
     "southeast":ROOMS"tower1",
   ]));
}

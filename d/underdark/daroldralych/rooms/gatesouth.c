#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_property("no invis",1);
   set_name("The southern gate");
   set_short("%^RESET%^%^BLUE%^The southern gate%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The southern gate%^RESET%^\n"
"%^BLUE%^You've reached the southern gates of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^"
"%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only "
"%^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air "
"above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals along the street's edges "
"are slender carved posts of obsidian, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire"
"%^BLUE%^ that sheds faint light around it.  Rising up before you are a pair of massive %^RED%^woo%^ORANGE%^de%^RED%^n "
"gates %^BLUE%^that allow passage out of the city, presumably into wild underdark.  The gates are set within the cavern's "
"walls and are firmly closed, leaving no way to go around or above them.  Back toward the north is an intersection of "
"this road and another, and past that is what appears to be the city's centre.%^RESET%^\n");

   add_item(({"gate","gates"}),"%^BLUE%^The southern end of the road comes to an end at a pair of massive %^RED%^woo"
"%^ORANGE%^de%^RED%^n gates%^BLUE%^, set within the walls of the cavern itself.  They are firmly closed, and so large are "
"they that they seal all the way to the roof of the tunnel beyond, preventing any access to the wild underdark.%^RESET%^");
   set_exits(([
     "north":ROOMS"outer11",
//     "south": exit to wild dark,
   ]));
}

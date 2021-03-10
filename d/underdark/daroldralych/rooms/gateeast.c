#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_property("no invis",1);
   set_name("The eastern gate");
   set_short("%^RESET%^%^BLUE%^The eastern gate%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The eastern gate%^RESET%^\n"
"%^BLUE%^You've reached the eastern gates of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^"
"%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only "
"%^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air "
"above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals along the street's edges "
"are slender carved posts of obsidian, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire"
"%^BLUE%^ that sheds faint light around it.  Rising up before you are a pair of massive %^RED%^woo%^ORANGE%^de%^RED%^n "
"gates %^BLUE%^that stand open, allowing passage to the main trail out of the city and into wild underdark.  Back toward "
"the west is an intersection of this road and another, and past that is what appears to be the city's centre.%^RESET%^\n");

   add_item(({"gate","gates"}),"%^BLUE%^The eastern end of the road comes to an end at a pair of massive %^RED%^woo"
"%^ORANGE%^de%^RED%^n gates %^BLUE%^that stand open, allowing passage out of the city to the east.  So large are they "
"that, when closed, they would seal all the way to the roof of the tunnel beyond, preventing all access to the city "
"itself.%^RESET%^");
   set_exits(([
     "west":ROOMS"outer21",
     "east": "/d/underdark/mid/main01",
   ]));
}

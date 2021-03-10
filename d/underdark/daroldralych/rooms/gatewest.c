#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_property("no invis",1);
   set_name("The western gate");
   set_short("%^RESET%^%^BLUE%^The western gate%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The western gate%^RESET%^\n"
"%^BLUE%^You've reached the western gates of the city.  Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^"
"%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, allowing for ease in walking.  Only "
"%^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air "
"above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals along the street's edges "
"are slender carved posts of obsidian, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire"
"%^BLUE%^ that sheds faint light around it.  Set into the wall of the cavern are a pair of small %^RED%^woo%^ORANGE%^de"
"%^RED%^n gates %^BLUE%^that allow passage out of the city, into what appears to be a fairly small corridor beyond.  Back "
"toward the east is an intersection of this road and another, and past that is what appears to be the city's centre"
".%^RESET%^\n");

   add_item(({"gate","gates"}),"%^BLUE%^The western end of the road comes to an end at a pair of small %^RED%^woo"
"%^ORANGE%^de%^RED%^n gates %^BLUE%^that stand open, allowing passage out of the city to the west.  They are not of "
"particular size, but the tunnel beyond seems small enough that when closed, they would seal all the way to the roof, "
"preventing all access to the city itself.%^RESET%^");
   set_exits(([
     "east":ROOMS"outer4",
     "west":"/d/underdark/juran/tunnel1",
   ]));
}

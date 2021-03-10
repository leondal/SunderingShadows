#include <std.h>
#include "../defs.h"
inherit INH+"square";

void create(){ 
   ::create();
   set_long("%^BLACK%^%^BOLD%^City square%^RESET%^\n"
"%^BLUE%^This small area forms the central square of the city.  Streets of smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^"
"%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^branch off in all directions, leading into various sections of "
"the city itself.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s "
"%^BLUE%^fills the air above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals "
"around the outer perimeter of the square are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian"
"%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds "
"faint light around it.  Directly north of you is the centre of the square, where stands a particularly %^RED%^ex"
"%^MAGENTA%^q%^BOLD%^u%^WHITE%^i%^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^RED%^te %^BLUE%^statue.  Still further north again "
"looms the imposing outline of the temple.%^RESET%^\n");

   add_item(({"statue","elaborate statue"}),"%^BLUE%^To the north, in the centre of the square, you can see the "
"outline of the %^RED%^ex%^MAGENTA%^q%^BOLD%^u%^WHITE%^i%^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^RED%^te %^BLUE%^statue that "
"marks the city's centre.%^RESET%^");
   set_exits(([
     "north":ROOMS"square5",
     "south":ROOMS"south1",
     "east":ROOMS"square9",
     "west":ROOMS"square7",
   ]));
}

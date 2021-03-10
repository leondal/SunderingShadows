#include <std.h>
#include "../defs.h"
inherit INH+"square";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City square%^RESET%^\n"
"%^BLUE%^This small area forms the central square of the city.  Streets of smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^"
"%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^branch off in all directions, leading into various sections of "
"the city itself.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s "
"%^BLUE%^fills the air above you, the ceiling too high up to be seen by any form of normal vision.  At short intervals "
"around the outer perimeter of the square are slender carved posts of %^BLACK%^%^BOLD%^ob%^RESET%^si%^BOLD%^%^BLACK%^dian"
"%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^%^MAGENTA%^ie fire%^BLUE%^ that sheds "
"faint light around it.  Immediately before you stands a statue of %^RED%^ex%^MAGENTA%^q%^BOLD%^u%^WHITE%^i%^MAGENTA%^s"
"%^RESET%^%^MAGENTA%^i%^RED%^te %^BLUE%^craftsmanship to mark the city's centre, while looming over you to the north "
"stands the imposing outline of the temple.%^RESET%^\n");

   add_item(({"statue","elaborate statue"}),"%^BLUE%^Before you is a statue of %^RED%^ex%^MAGENTA%^q%^BOLD%^u%^WHITE%^i"
"%^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^RED%^te %^BLUE%^beauty and craftsmanship, marking the very centre of the city.  It is "
"carved in the shape of a lithe drow female, clad only in meagre garments that look almost like strands of a %^RESET%^"
"sp%^BOLD%^i%^RESET%^der's w%^BOLD%^e%^RESET%^b %^BLUE%^and leave very little to the imagination.  She is forever frozen "
"in the pose of a %^CYAN%^gr%^GREEN%^ac%^CYAN%^ef%^GREEN%^u%^CYAN%^l %^BLUE%^dancer, with one arm outstretched and the "
"other by her side, standing upon the toes of only one slender foot.  Across her bare skin crawl the shapes of countless "
"tiny %^BOLD%^%^BLACK%^obsi%^RESET%^di%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^spiders, while others yet living mingle with "
"their lifeless simulacra.%^RESET%^");
   set_exits(([
     "north":ROOMS"square2",
     "south":ROOMS"square8",
     "east":ROOMS"square6",
     "west":ROOMS"square4",
     "northeast":ROOMS"square3",
     "southeast":ROOMS"square9",
     "northwest":ROOMS"square1",
     "southwest":ROOMS"square7",
   ]));
}

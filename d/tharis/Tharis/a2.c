//updated by Circe 9/9/04 to add new shop.
#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
   set_property("light",1);
   set_name("Narrow Alley in Tharis");
   set_short("Narrow Alley in Tharis");
   set_long(
@CIRCE
%^MAGENTA%^Narrow Alley in Tharis%^RESET%^
The %^BOLD%^tall buildings %^RESET%^of the city block out much of the 
%^YELLOW%^light %^RESET%^here on the ground, leaving the %^BOLD%^stone alley 
%^RESET%^in %^BOLD%^%^BLACK%^shadow%^RESET%^.  Though far from clean, the alleyway 
has not piled with %^ORANGE%^refuse %^RESET%^quite as badly as other areas in 
the city.  Small patches of %^GREEN%^mold %^RESET%^grow between the cracked 
stones, making footing a little slippery.  The main 
thoroughfare seems to be back to the east, while this 
little alley continues west.
CIRCE
   );
   set_smell("default","The air here is slightly stale and smells lightly of sweat.");
   set_listen("default","You hear the bustle of the town to the east.");
   set_items(([
      "stone":"The stones here have not been tended since the "+
         "erection of the walls around them. They are split and dirty.",
      "mold":"The mold growing between the stones and within the "+
         "cracks is a vivid green that makes footing a little uncertain.",
      ({"building","buildings"}):"Crowding the alley are tall buildings "+
         "made of both stone and wood.  From here, all you can see are "+
         "the backs, though it seems there might be one narrow opening "+
         "to the west.",
      ({"refuse","piles of refuse"}):"There are no piles of refuse "+
         "here, though scattered pieces line the bases of the buildings."
   ]));
   set_exits(([
      "east":ROOMS"main3",
      "west":ROOMS"a1",
   ]));
}


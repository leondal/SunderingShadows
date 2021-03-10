//updated by Circe 5/30/04 with color, etc.
// Stable of the Crown and Castle, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// cncstable.c

#include <std.h>
#include "../include/tabor.h"

inherit STABLE;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A stable");
  set_long(
@TABOR
%^BOLD%^Stable of the Crown and Castle, Tabor%^RESET%^
%^ORANGE%^The wooden stables of the %^YELLOW%^Crown and Castle Inn %^RESET%^%^ORANGE%^are in fantastic 
shape, giving evidence to the care Tabor must take with its horses.  
Each %^RED%^stall %^ORANGE%^is wide, giving the horse plenty of room, while the tops 
end just above the horse's shoulders, allowing him space to look 
out and receive a treat.  %^YELLOW%^Shelves %^RESET%^%^ORANGE%^line the back wall, full of 
%^WHITE%^bags of grain %^ORANGE%^and even a few crates of %^RED%^carrots%^ORANGE%^.  A very small 
bag has spilled open, revealing %^BOLD%^%^WHITE%^sugar cubes %^RESET%^%^ORANGE%^inside.  The front 
of the stables closes with double doors, while a single door 
stands open, leading to a %^GREEN%^grassy tethering area %^ORANGE%^out back.

%^RESET%^You can look at the %^MAGENTA%^sign %^RESET%^here to see what horses are for sale.

The courtyard of the inn is to the north.
TABOR
  );
  set_smell("default","You smell the pungent odor of straw and manure.");
  set_listen("default","You hear the sounds of horses all around you.");
  
  set_exits( ([
    "north"  : ROOMDIR+"cncinn",
    "south" : ROOMDIR+"cncstable1"
  ]) );
  set_items(([
    "horses":"You see a row of stalls down the length of the main aisle "+
	  "of the barn.  Over the top of many stall doors, you can see horses "+
	  "looking at you curiously.",
    "aisle":"The aisle is long and wide with a hard packed dirt floor "+
	  "that looks recently raked.  You see stable hands tacking up horses "+
	  "for customers.",
    "stalls":"The stalls all have split doors, an upper and a lower.  "+
	  "During the day, the upper doors are generally open allowing the "+
	  "horses to look out.",
    ({"shelves","grain","bags","bags of grain","crates","carrots"}) : "The "+
        "far wall is lined with shelves, each bulging with supplies for "+
        "the horses here.  Crates of carrots, bags of grain, and all the "+
        "brushes, harnesses, and other tack needed are here, attesting "+
        "to the fact that these horses are well-tended.",
    ({"bag","cubes","sugar cubes"}) : "%^BOLD%^The bag of sugar cubes "+
        "has spilled open, leaving a few cubes lying on the shelves.  "+
        "Most horses love these as special treats."
  ]));
  set_animal(({"horse","pony","donkey"}),({"/d/shadow/mon/horse","/d/common/mounts/pony","/d/common/mounts/donkey"}));
  set_animal_price(({"horse","pony","donkey"}),({75,45,30}));
  set_stalls(10);
  ::fill_stalls();
}

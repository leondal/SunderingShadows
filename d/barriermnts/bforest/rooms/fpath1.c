//fpath1
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
   set_exits(([
"cave":"/d/barriermnts/bpeak/rooms/dcave8",
"southwest":INRMS+"fpath2",
]));
  
   set_long("%^RESET%^%^GREEN%^This %^ORANGE%^forest path %^GREEN%^can hardly be called a path at all, in fact,"
" it resembles something more along the lines of a game trail. Trees tower above you and sway slightly in the"
" breeze that makes its way through this mountainous valley, and a wide array of bushes, vines and brambles"
" spill out onto the path, making it that much more difficult to get through cleanly.  Despite the thickness"
" of the forest here, a certain unease proliferates throughout the air, clinging to the area like a %^BOLD%^%^BLACK%^"
"dense fog %^RESET%^%^GREEN%^that will not go away.  The %^ORANGE%^path %^GREEN%^ends at a"
" %^BOLD%^%^BLACK%^cave %^RESET%^%^GREEN%^here.%^RESET%^\n");
   set_smell("default","You smell the fresh scent of pine.%^RESET%^");
   set_listen("default","With the exception of the leaves rustling in the wind, it is deadly quiet.");
   set_items(([
      ({"path","forest path","trail","game trail"}):"%^RESET%^%^ORANGE%^The forest path is littered with fallen leaves and is quite slippery.",
      "mountains":"%^RESET%^%^BLUE%^Mountains loom high overhead on all sides of this forest.",
      ({"bushes","vines","brambles"}):"%^GREEN%^Bushes and brambles lay low on the forest floor, spilling out into the pathway that you walk along while vines cling to the trees, their bushy leaves creating an overhanging that nearly blocks out all sunlight.",
      ({"trees","forest"}):"%^GREEN%^The trees here grow proud and tall and are covered with thick vines whose loose leaves hang over the pathway.",  
      "leaves":"%^RESET%^%^ORANGE%^Fallen leaves and debris litter the pathway, making it nearly impossible to distinguish.",  
      "cave":"%^BOLD%^%^BLACK%^The opening of the cave is set into the side of the cliff face.  It looks like it has been dug out carelessly, as loose rock hangs around the opening with each piece looking as though it were ready to crumble away at any given moment.", 
     "cliff":"%^RESET%^%^ORANGE%^The cliff towers over five hundred feet above you and seems to cast a shadow over the forest.", 
]));
}



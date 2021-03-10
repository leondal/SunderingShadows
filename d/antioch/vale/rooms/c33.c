#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_short("%^CYAN%^A clearing%^RESET%^");
   set_long(
   "This area of the vale is not quite as overgrown and untamed. The"+
	" grass only stretches up a few inches and is a lighter shade of"+
	" green. More flowers have been able to reach up through the layer"+
	" of grass and they grow close to the ground in many different"+
   " shades. There is a large wall of brush and hedges in the center of the"+
   " clearing. It doesn't really seem as though someone tends this"+
   " area, as much as it feels that nature has yielded to whoever is"+
   " living here. Directly to the west is one of the many huts that"+
   " are scattered across the clearing."
   );
   set("night long",
   "Starlight washes over this little clearing. You can see it clearly"+
   " reflecting off the large wall of brambles and bushes in the center"+
   " of the clearing, light even reflects off the pointy thorns that"+
   " you hadn't even noticed before. The grass is much shorter here,"+
   " allowing for more flowers to grow along the ground. To the west"+
   " is one of the huts that you noticed are scattered about the"+
   " clearing."
   );
   set_smell("default","The delicate scent of flowers fills your nostrils.");
   set_listen("default","Bird song echoes throughout the vale.");
   set_items(([
   "grass" : "The grass is much shorter here, and a lighter shade of green.",
   "flowers" : "Several flowers have sprouted up along the ground,"+
   " there is a plethora of beautiful hues.",
   "huts" : "There are several huts that you can see scattered"+
   " throughout the clearing. They appear to be rather simple.",
   ({"wall","brambles","bushes"}) : "In the center of the clearing is"+
   " a large wall of bushes and brambles. It is rather strange, it"+
   " appears to be growing as a wall all by itself, but that seems"+
   " rather impossible...",
   "thorns" : "Looking closely you can see sharp thorns in the wall"+
   " of brambles. You would not want to attempt to climb over or"+
   " through that!",
   ]));
   set_exits(([
   "south" : ROOMS+"c31",
   "east" : ROOMS+"v42",
   "north" : ROOMS+"c36",
   ]));
}

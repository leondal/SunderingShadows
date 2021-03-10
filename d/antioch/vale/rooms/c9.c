#include <std.h>
#include "../vale.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_short("In front of a hut");
   set_long(
      "%^GREEN%^This area of the %^BOLD%^vale %^RESET%^%^GREEN%^is "+
      "not quite as overgrown and untamed.  The %^BOLD%^grass %^RESET%^"+
      "%^GREEN%^only stretches up a few inches and is a lighter shade of"+
      " %^BOLD%^green%^RESET%^%^GREEN%^.  More %^MAGENTA%^f%^BOLD%^l%^RED%^"+
      "o%^YELLOW%^w%^RED%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^s %^GREEN%^"+
      "have been able to reach up through the layer"+
      " of grass, and they grow close to the ground in many different"+
      " shades.  You can see a few %^ORANGE%^huts %^GREEN%^scattered "+
      "about the %^CYAN%^clearing%^GREEN%^.  There is a large wall "+
      "of %^ORANGE%^brush %^GREEN%^and %^BOLD%^hedges %^RESET%^"+
      "%^GREEN%^in the center of the %^CYAN%^clearing%^GREEN%^.  "+
      "It doesn't really seem as though someone tends this"+
      " area, as much as it feels that nature has yielded to whoever is"+
      " living here.\n\n"+
      "A door leading into one of the huts is directly north of you.\n"
   );
   set("night long",
      "%^BOLD%^%^WHITE%^Starlight %^RESET%^%^BLUE%^washes over this "+
      "little %^CYAN%^clearing%^BLUE%^.  You can see it clearly"+
      " reflecting off the large wall of %^ORANGE%^brambles "+
      "%^BLUE%^and %^GREEN%^bushes %^BLUE%^in the center"+
      " of the %^CYAN%^clearing%^BLUE%^, %^RESET%^light %^BLUE%^"+
      "even reflects off the pointy %^ORANGE%^thorns %^BLUE%^that"+
      " you hadn't even noticed before.  The %^GREEN%^grass "+
      "%^BLUE%^is much shorter here,"+
      " allowing for more flowers to grow along the ground.  A "+
      "few %^ORANGE%^huts%^BLUE%^"+
      " are scattered about the %^CYAN%^clearing%^BLUE%^, and "+
      "the entrance to one is directly north of you.\n"
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
   "west" : ROOMS+"v80",
   "east" : ROOMS+"c10",
   "north" : ROOMS+"hut2",
   "south" : ROOMS+"v28"
   ]));
   set_door("door",ROOMS+"hut2","north",0);
}

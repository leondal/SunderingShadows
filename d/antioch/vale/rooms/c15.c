#include <std.h>
#include "../vale.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_travel(FOOT_PATH);
   set_terrain(MEADOWLANDS);
   set_name("Before a hut");
   set_short("%^ORANGE%^Before a hut%^RESET%^");
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
      " living here. To the south, the entrance to a hut lays.\n"
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
      " are scattered about the %^CYAN%^clearing%^BLUE%^.  To the"+
      " south, the entrance to a hut lays.\n"
   );
   set_smell("default","The delicate scent of flowers fills your nostrils.");
   set_listen("default","Bird song echoes throughout the vale.");
   set_items(([
      "grass" : "%^BOLD%^%^GREEN%^The grass is much shorter here, and a lighter shade of green.",
      "flowers" : "%^MAGENTA%^Several flowers have sprouted up along the ground,"+
         " there is a plethora of beautiful hues.",
      "huts" : "%^ORANGE%^There are several huts that you can see scattered"+
         " throughout the clearing. They appear to be rather simple.",
      ({"wall","brambles","bushes"}) : "%^GREEN%^In the center of the clearing is"+
         " a large wall of bushes and brambles. It is rather strange, it"+
         " appears to be growing as a wall all by itself, but that seems"+
         " rather impossible...",
      "thorns" : "%^ORANGE%^Looking closely you can see sharp thorns in the wall"+
         " of brambles. You would not want to attempt to climb over or"+
         " through that!"
   ]));
   set_exits(([
   "west" : ROOMS+"c14",
   "east" : ROOMS+"c16",
   "north" : ROOMS+"c21",
   "south" : ROOMS+"hut3",
   ]));
   set_door("door",ROOMS+"hut3","south",0);
}

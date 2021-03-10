#include <std.h>
#include "../vale.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
   set_name("Before a hut");
   set_short("%^ORANGE%^Before a hut%^RESET%^");
   set_long(
      "%^BOLD%^%^GREEN%^You are walking along the edges of "+
      "the %^RESET%^%^ORANGE%^wall of brambles %^BOLD%^%^GREEN%^that "+
      "surrounds the center of the clearing in the northern half of "+
      "%^CYAN%^Moonstone Vale%^GREEN%^.  It is impressively thick, "+
      "at least several feet from what you can tell.  It is also "+
      "very tall, reaching over fifteen feet into the air at least.  "+
      "The %^RESET%^%^GREEN%^bushes %^BOLD%^and %^RESET%^%^ORANGE%^"+
      "brambles %^BOLD%^%^GREEN%^have woven themselves together in "+
      "an intricate weave that makes the wall incredibly strong as "+
      "well as impossible to see through.  You see no signs of "+
      "tampering with nature to make it twist into this shape, "+
      "and yet there is not a leaf or branch jutting out of place."+
      "To the north, the entrance to one of the huts lays.\n"
   );
   set("night long",
      "Moonlight %^BLUE%^washes over the wall that you are "+
      "standing next to, making the normally %^GREEN%^dark "+
      "green leaves %^BLUE%^shine like tiny %^BOLD%^%^WHITE%^silver "+
      "mirrors%^RESET%^%^BLUE%^.  You can see sharp %^ORANGE%^"+
      "thorns %^BLUE%^reflecting in the %^RESET%^pale light "+
      "%^BLUE%^and would not want to get stuck by them.  The "+
      "wall itself appears to be several feet deep and "+
      "reaches high into the air.  You see no way to pass "+
      "through it or get over it.  You also see no evidence "+
      "that this wall has been tended to, it is as though the bushes "+
      "and brambles have woven themselves together into this wall all "+
      "on their own.  To the north, the entrance to one of the huts lays.\n"
   );
   set_smell("default","You can smell the shrubbery here.");
   set_listen("default","You hear bird song in the distance.");
   set_items(([
      "grass" : "%^BOLD%^%^GREEN%^The grass is much shorter here, and a lighter shade of green.",
      "flowers" : "%^MAGENTA%^Several flowers have sprouted up along the ground,"+
         " there is a plethora of beautiful hues.",
      "huts" : "%^ORANGE%^There are several huts that you can see scattered"+
         " throughout the clearing. They appear to be rather simple.",
      ({"wall","brambles","bushes"}) : "%^GREEN%^Running around the center of the"+
         " clearing is a large wall of bushes and brambles. It is rather"+
         " strange, it appears to be growing as a wall all by itself, but"+
         " that seems rather impossible. You wonder what it is protecting.",
      "thorns" : "%^ORANGE%^Looking closely you can see sharp thorns in the wall"+
         " of brambles. You would not want to attempt to climb over or"+
         " through that!"
   ]));
   set_exits(([
   "west" : ROOMS+"c42",
   "east" : ROOMS+"c40",
   "north" : ROOMS+"hut7",
   ]));
   set_door("door",ROOMS+"hut7","north",0);
}

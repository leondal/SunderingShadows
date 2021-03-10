//add creature
#include "../kildare.h"

inherit PIER;

void create(){
   ::create();
   set_indoors(1);
   set_property("light",-1);
   set_terrain(BUILT_TUNNEL);
   set_travel(RUTTED_TRACK);
   set_name("On the shore of a subterranean lake");
   set_short("%^BOLD%^%^BLACK%^On the shore of a subterranean lake%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The narrow tunnel opens here into "+
      "a wide cave.  A %^RESET%^%^CYAN%^faint breeze %^BOLD%^%^BLACK%^"+
      "brings the scent of stale water, rising from a %^RESET%^"+
      "%^BLUE%^vast subterranean lake %^BOLD%^%^BLACK%^stretching "+
      "into the %^RESET%^gloom%^BOLD%^%^BLACK%^.  The dust of the "+
      "floor gives way in this cavern to %^GREEN%^phosphorescent moss "+
      "%^BLACK%^that lightens the darkness with a faint %^GREEN%^"+
      "glow%^BLACK%^.  The surface of the %^RESET%^%^BLUE%^lake "+
      "%^BOLD%^%^BLACK%^is glassy, disturbed only by occasional "+
      "%^RESET%^%^CYAN%^r%^BLUE%^i%^CYAN%^p%^BLUE%^p%^CYAN%^l"+
      "%^BLUE%^e%^CYAN%^s %^BOLD%^%^BLACK%^as if made by some "+
      "%^RESET%^unseen paddler%^BOLD%^%^BLACK%^.  The cavern likely "+
      "continues much deeper into the earth, but the way is blocked "+
      "by the %^CYAN%^icy waters %^BLACK%^of the %^RESET%^%^BLUE%^"+
      "forbidding lake%^BOLD%^%^BLACK%^.  The view to the "+
      "northwest is likewise blocked by a sharp bend leading "+
      "to the tunnel, making this a rather secluded, if %^RESET%^"+
      "forlorn%^BOLD%^%^BLACK%^, grotto.%^RESET%^\n");
   set_listen("default","The faint sound of %^CYAN%^lapping water "+
      "%^GREEN%^echoes on the walls.");
   set_smell("default","The stench of dead animals and bird droppings is somewhat more bearable here.");
   set_items(([
      ({"depressions","raised places","wall","walls"}) : "The depressions and corresponding "+
         "raised places form mock mountains and valleys all along the "+
         "walls.  The wall seems to lie in wait for some hapless person to "+
         "brush against it.",
      ({"floor","tunnel"}) : "The floor of this tunnel is uneven, and it "+
         "looks to have been carved by unskilled hands working quickly.  "+
         "It features several ridges ready to catch an unwary toe.",
      ({"lake","subterranean lake"}) : "The lake is dark and stretches as far "
         "as the eye can see, though that isn't very far at all.  Waves "
         "lap gently on the shore, though there seems to be no breeze here.",
      ({"waters","icy waters"}) : "The water appears black in the glow "
         "of the phosphorescent moss covering the rocks.",
      ({"moss","phosphorescent moss"}) : "%^BOLD%^%^GREEN%^The moss covers "
         "the rocks of the cavern, bathing the whole area in a faint ghostly "
         "green glow.%^RESET%^",
      ({"rocks","floor"}) : "The jagged rocks have been worn smooth near the "
         "shore of the lake, making footing treacherous. Most of the rocks "
         "are covered in the phosphorescent moss that seems to flourish here."
   ]));
   set_fish((["eyeless trout":5, "cave fish":10, "ghost trout":50]));
   set_water_body("subterranean lake");
   set_max_fishing(2);
   set_chance(12);
   set_max_catch(8);
   set_exits(([
      "northwest" : ROOMS"hiddentunnel3"
   ]));
}
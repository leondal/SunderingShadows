#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_name("Ancient Barrows");
   set_short("%^BOLD%^%^BLACK%^Ancient Barrows%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^RESET%^%^BLUE%^This enormous circular %^ORANGE%^chamber "+
      "%^BLUE%^is carved from the %^RESET%^mountain %^BLUE%^itself "+
      "and serves as the %^ORANGE%^center point %^BLUE%^for the "+
      "various %^ORANGE%^hallways %^BLUE%^and %^ORANGE%^passages "+
      "%^BLUE%^that snake their way through the %^RESET%^mountain"+
      "%^BLUE%^.  These %^BOLD%^%^BLACK%^barrows %^RESET%^%^BLUE%^"+
      "served as the %^RESET%^tombs %^BLUE%^for the ancient "+
      "firbolgs of %^GREEN%^"+
      "Lothwaite%^BLUE%^, a practice which still continues today.  "+
      "Brilliant %^ORANGE%^golden torches %^RESET%^%^BLUE%^ bathe "+
      "the area in %^RESET%^f%^BOLD%^l%^RESET%^i%^BOLD%^c%^RESET%^"+
      "k%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^YELLOW%^"+
      "light%^RESET%^%^BLUE%^, illuminating all but the uppermost "+
      "reaches of the %^BOLD%^%^BLACK%^ceiling%^RESET%^%^BLUE%^.  "+
      "There, %^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^f%^MAGENTA%^"+
      "l%^BLUE%^i%^MAGENTA%^t %^BLUE%^and %^MAGENTA%^d%^BLUE%^a"+
      "%^MAGENTA%^n%^BLUE%^c%^MAGENTA%^e %^BLUE%^on a %^CYAN%^"+
      "cool breeze %^BLUE%^that moves eternally through the "+
      "%^RESET%^barrows%^BLUE%^.  %^ORANGE%^Archways%^BLUE%^ with "+
      "onion-shaped tops open up all around, leading into hallways "+
      "in each direction, except west.  In that direction, the smooth "+
      "%^BOLD%^%^BLACK%^w%^YELLOW%^a%^BLACK%^l%^YELLOW%^l %^RESET%^"+
      "%^BLUE%^has been covered by the %^BOLD%^%^BLACK%^spiral "+
      "staircase %^RESET%^%^BLUE%^descending "+
      "from above.%^RESET%^"+
      "\n");
   set_items(([
      ({"chamber","passageway","passageways","hallways","hallway"}) : "These "+
         "hallways seem to be endless, moving deeper into the mountains.  "+
         "The ground is exceedingly level, with never a rise or dip, and "+
         "the smooth stone walls twist and turn, limiting view.",
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of the "+
         "caverns are flawlessly smooth and seem to emit a coldness all "+
         "their own.  They are shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
      ({"torch","torches","torchlight"}) : "%^YELLOW%^Unlike most torches, "+
         "these are not made of simple wood with fuel-soaked cloth.  Instead, "+
         "each torch has been formed from solid gold and set with %^BLUE%^"+
         "sapphires %^YELLOW%^and %^CYAN%^diamonds%^YELLOW%^.  Strangely, "+
         "you notice no source of fuel that would explain the burning of "+
         "any of the torches.",
      ({"dome","ceiling","ceilings","onion dome","domes"}) : "The ceilings "+
         "high overhead are hidden in the shadows, but an occasional leap "+
         "of the torchlight reveals onion-shaped domes overhead.  They are "+
         "carved to give the illusion of windows, but only serve to emphasize "+
         "the fact that you are indeed far underground with no way out.",
      ({"shadow","shadows"}) : "The flickering light of the torches sends "+
         "shadows dancing high up the walls, hiding the ceiling from view "+
         "except for brief moments.  They sometimes seem to be hiding something.",
      ({"archway","archways"}) : "The onion-shaped archways rise high "+
         "overhead.  They are carved in relief and offer ghostly support "+
         "to the hallways.",
      ({"stairs","stairway","staircase","spiral staircase","landing"}) :
         "The stairs are carved from the natural stone of the "+
         "mountainside and glitter in the light of countless "+
         "torches.  They lead upward into the darkness above."
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The cool breath of a tomb is the only smell in the air.");
   set_exits(([
      "northwest" : PATHEXIT"b51",
      "north" : PATHEXIT"b2",
      "northeast" : PATHEXIT"b17",
      "east" : PATHEXIT"b23",
      "southeast" : PATHEXIT"b34",
      "south" : PATHEXIT"b39",
      "southwest" : PATHEXIT"b45",
      "up" : PATHEXIT"b_start"
   ]));
 }
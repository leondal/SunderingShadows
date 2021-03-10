//Octothorpe (8/12/08)
//Underdark Mining Caverns Neutral Cavern Room Bravo 2

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^At the base of a %^RESET%^limestone "+
      "%^BOLD%^%^BLACK%^column\n "+
      "This cavern opens up into a large, beehive-shaped void.  A massive "+
      "column of %^RESET%^limestone %^BOLD%^%^BLACK%^juts out of the floor "+
      "of the cavern here, reaching all the way up the ceiling.  Veins of "+
      "an unusual crystal spread over the surface of the rocky column.  The "+
      "%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^n %^BLACK%^and "+
      "%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^rpl%^RESET%^"+
      "%^MAGENTA%^e %^BOLD%^%^BLACK%^crystals glow eerily on the column, "+
      "providing a bizarre source of illumination to the cavern.  %^CYAN%^"+
      "Po%^RESET%^o%^CYAN%^ls %^BOLD%^%^BLACK%^of water collect on the "+
      "cavern floor under the overhanging stalactites.  Curious looking "+
      "calcite deposits, known as flowstones, form along the walls and the "+
      "floor of the cavern.  Although there is a significant amount of "+
      "moisture present, there is a complete lack of any identifiable flora "+
      "in this cavern.%^RESET%^\n");
   add_item(({"column","formation"}),"%^BOLD%^%^BLACK%^This craggy formation "+
      "reaches from floor to ceiling, and is so massive that it almost "+
      "appears to support the ceiling of the cavern.  Veins of crystals, "+
      "known as faerzress, run along the surface of the rock.  The crystals "+
      "are either a dull %^GREEN%^g%^BOLD%^re%^RESET%^%^GREEN%^e%^BOLD%^n "+
      "%^BLACK%^or %^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^rp%^RESET%^"+
      "%^MAGENTA%^l%^BOLD%^e%^BLACK%^, and give off a glow that slightly "+
      "illuminates the cavern in an eerie cast.  Due in part to the crags "+
      "on the column it would seem as if you could %^RESET%^climb %^BOLD%^"+
      "%^BLACK%^it with some relative ease, with the right tools.");      
   set_listen("default","A nearly piercing buzzing noise emanates from the rock column.");
   set_exits(([
      "north":RMS"nucaverna2",
      "east":RMS"nucavernb3",
      "south":RMS"nucavernc2",
      "southwest":RMS"nucavernc1",
      "west":RMS"nucavernb1",
      "northwest":RMS"nucaverna1",      
   ]));
   set_climb_exits(([
      "climb" : ({RMS"nucavernz1",25,20,300}),
   ]));
   set_fall_desc("You land with a good thud on the limestone floor "+
   "below...");
}
//Octothorpe (1/24/09)
//Underdark Mining Caverns Neutral Cavern Room Alpha 5

#include <std.h>
#include "../defs.h"
inherit INH+"nucavern2";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An eerily %^GREEN%^g%^BOLD%^l%^RESET%^"+
      "%^GREEN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng "+
      "%^BOLD%^%^BLACK%^cavern\n "+
      "This cavern opens up into a large, beehive-shaped void. The "+
      "center of this cavern is dominated by a massive column that "+
      "reaches up to the ceiling of the chamber. Veins of an unusual "+
      "crystal spread over the surface of the rock formation. The "+
      "%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^n %^BLACK%^and "+
      "%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^rpl%^RESET%^"+
      "%^MAGENTA%^e %^BOLD%^%^BLACK%^crystals glow eerily on the "+
      "column, providing a bizarre source of illumination to the "+
      "cavern. %^CYAN%^Po%^RESET%^o%^CYAN%^ls %^BOLD%^%^BLACK%^of "+
      "water collect on the cavern floor under the overhanging "+
      "stalactites. Curious looking calcite deposits, known as "+
      "flowstones, form along the walls and the floor of the cavern. "+
      "Although there is a significant amount of moisture present, "+
      "there is a complete lack of any identifiable flora in this "+
      "cavern.\n "+
      "A hole on the cavern floor allows access to the depths "+
      "below.%^RESET%^\n");
   add_item(({"hole","depths"}),"%^BOLD%^%^BLACK%^The edges of this "+
      "opening are worn down to a smooth patina. Even with the glow "+
      "from the faerzress, it is impossible to see the bottom of the "+
      "hole.%^RESET%^");
   set_exits(([
      "west":RMS"nucaverna4",
   ]));
   set_climb_exits(([
      "descend" : ({RMS"kobcavernd2",25,20,200}),
   ]));
   set_fall_desc("You land with a good thud on the limestone floor "+
   "below...");
}
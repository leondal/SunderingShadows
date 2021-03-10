//ranger_talos.c - Reward for Riddle Quest.  Circe 7/12/05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
   set_name("longbow");
   set_id(({"bow","long bow","longbow","lightning storm","storm"}));
   set_obvious_short("%^BOLD%^%^BLACK%^an %^YELLOW%^etched "+
      "%^BLACK%^black longbow%^RESET%^");
   set_short("%^BOLD%^%^YELLOW%^Lightning %^BLACK%^Storm%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^This longbow is made of deep ebony wood lacquered to a high shine.  Jagged %^YELLOW%^lightning bolts %^BLACK%^filled with molten gold streak across its surface, leaving behind angry storm clouds of %^RESET%^%^BLUE%^blue and gray%^BOLD%^%^BLACK%^.  The storm inside is magically created to roil and strike, keeping the fury ever close at hand.%^RESET%^
CIRCE
   );
   set_lore(
@CIRCE
Rangers of the Destroyer seem at first to be something of an impossibility, for how can one focused on destruction follow the path of the ranger?  Actually, though, the destructive forces are every bit as necessary in nature as those that generate life.  Rangers of the Stormlord are not welcomed by other rangers, but many druids see their role as a necessary one - so long as they do not get out of bounds, of course.
CIRCE
   );
   set_property("lore difficulty",12);
   set_unwield("%^BOLD%^%^BLACK%^You sense the storm subside "+
      "as you sheath the bow.%^RESET%^");
}

//ranger_istishia.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("istishia bow");
   set_id(({"greenish blue longbow","bow","longbow","long bow","wave","cresting wave"}));
   set_obvious_short("A greenish blue longbow");
   set_short("%^GREEN%^C%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^t%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^g %^CYAN%^W%^RESET%^%^CYAN%^a%^BOLD%^v%^RESET%^%^CYAN%^e%^RESET%^");
   set_long(
@CIRCE
%^CYAN%^This elegantly styled longbow has been carved in the shape of a cresting wave.  Each end of the bow curves back slightly and has been carved into the image of a stylized wave, complete with %^BOLD%^%^WHITE%^whitecaps%^RESET%^%^CYAN%^.  The bow widens in the middle, and the handle looks to be made of %^BOLD%^%^MAGENTA%^coral%^RESET%^%^CYAN%^.  All along the bow swim images of merpeople flitting about with dolphins and stranger sea creatures.  All together, the bow has a whimsical, nautical feel perfect for those at home on the seas.
CIRCE
   );
   set_lore(
@CIRCE
Bowmen of the Waterlord are uncommon, but not unheard of.  Typical longbows do them little good in the water, but those who choose to travel on land often carry one with them.  This longbow was granted to Thamior Siannodel, an elven ranger in the Waterlord's service for his efforts.  Thamior was responsible for keeping the waterways clean and safe while the fiefdom of Drogheda was being built ages ago.  Working peacefully with the nereids and the citizens of Drogheda, Thamior was able to ensure the survival of some of the realm's most lively waterways.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^CYAN%^The crashing of waves fills your ears as you release the bow.");
}
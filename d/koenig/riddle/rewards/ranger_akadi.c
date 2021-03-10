//ranger_akadi.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("akadi bow");
   set_id(({"light blue longbow","bow","longbow","long bow","breath","freedom","breath of freedom"}));
   set_obvious_short("A light blue longbow");
   set_short("%^BOLD%^%^CYAN%^Breath of %^BLUE%^Free%^WHITE%^d%^BLUE%^om%^RESET%^");
   set_long(
@CIRCE
%^BOLD%^%^CYAN%^This unique longbow is made of willow wood that has been %^WHITE%^bleached %^CYAN%^in the %^YELLOW%^sun %^CYAN%^and lacquered with a light blue varnish.  The %^YELLOW%^light %^CYAN%^glints and reflects off the bow in a chaotic dance of freedom.  No designs have been carved into the bow's smooth surface, but %^WHITE%^fluffy clouds %^CYAN%^seem to move just underneath the surface, blown by some unseen wind.  The bow has been strung with a transparent string that seems to sing as it is released.
CIRCE
   );
   set_lore(
@CIRCE
Rangers of Akadi prize their freedom over all else.  They follow where the winds lead, and they often abandon a cause because a better or more interesting one comes up.  Still, they follow the goodness in their hearts, and they would never pursue a goal that brought harm to the natural world.  Willow wood, such as that that forms this bow, is seen as a symbol of freedom by Akadians, who praise its whispy branches that float on the air rather than remaining bound to the earth.  Though she is ever a fickle goddess, the Queen of Air is said to have once dropped a bow like this from a spinning whirlwind at the feet of one of her most devoted rangers.  Whether the bow was meant as a reward for good work or was simply a whim is unknown.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^BOLD%^%^CYAN%^The winds rustle your hair as you release the bow.");
}
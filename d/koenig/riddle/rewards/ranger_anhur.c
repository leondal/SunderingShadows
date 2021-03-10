//ranger_anhur.c - Reward for Riddle Quest.  ~Circe~ 5/27/08
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
   set_name("longbow");
   set_id(({"crystalline longbow","storm bow","Storm Bow","longbow","bow"}));
   set_obvious_short("%^BOLD%^%^CYAN%^A crystalline longbow%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Ri%^BLACK%^g%^CYAN%^ht%^YELLOW%^e"+
      "%^CYAN%^ou%^WHITE%^s %^CYAN%^St%^YELLOW%^o%^CYAN%^rm "+
      "B%^BLACK%^o%^CYAN%^w%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Made from a crystalline substance, "+
      "this longbow seems supple to the touch.  When held, "+
      "%^YELLOW%^fl%^WHITE%^a%^YELLOW%^sh%^WHITE%^e%^YELLOW%^s "+
      "of li%^WHITE%^g%^YELLOW%^ht%^WHITE%^n%^YELLOW%^ing %^CYAN%^"+
      "seem to crackle within its depths.  No other material has "+
      "added to it to form a grip - the crystal is simply formed "+
      "into a handle and seems to have been gently scored for "+
      "added security.  Most strangely, the bow seems not to use "+
      "normal strings and instead has a single beam of %^YELLOW%^"+
      "light %^CYAN%^that seems to be almost solid.%^RESET%^");
   set_lore("Rangers of Anhur are a reclusive lot, and many of "+
      "them seem much more comfortable in the desert than in "+
      "the forest surroundings of their northern cousins.  "+
      "This penchant is likely due to their origins in the deep "+
      "parts of the Tsarven empire, where it is said many deserts "+
      "dot the landscape.  The creation of these bows is a "+
      "closely guarded secret, and it is widely believed that the "+
      "bow will cease functioning should the ranger prove himself "+
      "unworthy to Anhur by not defending his family or homeland.");
   set_property("lore difficulty",12);
}
//bard_mystra.c - Bard of Mystra reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERDETECT;

void create(){
    ::create();
//    set_name("mystra instrument");
    set_id(({"crystal and pearl lyre","lyre","instrument"}));
    set_short("%^BOLD%^%^BLUE%^A crytal and %^WHITE%^pearl %^BLUE%^lyre%^RESET%^");
    set_long(
      "%^BOLD%^%^WHITE%^This fantastic lyre is made of a large %^BLUE%^"+
      "blue crystal %^WHITE%^that has been carved into the shape of a "+
      "multi-faceted tortoise shell.  %^YELLOW%^Light %^WHITE%^plays mystically over the "+
      "body of the lyre, which seems to be ever-changing.  Mother%^MAGENTA%^-"+
      "%^WHITE%^of%^MAGENTA%^-%^WHITE%^pe%^MAGENTA%^a%^WHITE%^rl arms "+
      "rise from the shell, ending in a crossbar that supports "+
      "%^RESET%^%^BLUE%^sh%^BOLD%^if%^RESET%^%^CYAN%^ti%^BOLD%^ng "+
      "strings %^WHITE%^made of the essence of %^CYAN%^magic %^WHITE%^itself.  "+
      "A message seems to hover within the mother-of-pearl crossbar, not "+
      "carved, but still a part of the instrument."
    );
    set_read("%^BOLD%^%^CYAN%^May the power of this lute bring acclaim to "+
       "you and to the Lady of Mysteries.  You may use the lyre to "+
       "%^WHITE%^<%^CYAN%^anger%^WHITE%^> %^CYAN%^the foolish into attacking you, or "+
       "%^WHITE%^<%^CYAN%^play%^WHITE%^> %^CYAN%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("The magical generation of these lyres is known to no mortal.  "+
       "Clearly the work of wondrous creators, the process has long been lost "+
       "to men - assuming they ever had it.  The church of Mystra holds that "+
       "the Lady of Mysteries creates the lyres as a reward for those bards who "+
       "have served her well by focusing on their magic rather than simple parlor "+
       "tricks.");
    set_property("lore difficulty",12);
}

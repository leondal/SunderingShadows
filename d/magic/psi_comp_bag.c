#include <std.h>
#include <move.h>
#define PSI_COMP "/d/magic/store_comp"
inherit "/d/magic/comp_bag.c";

#include <spellcomponents.h>

void create() {
   ::create();
   set_name("crystals satchel");
   set_short("a leather satchel for crystals");
   add_id("satchel");
   add_id("leather satchel");
   set_long(
      "%^RESET%^%^ORANGE%^This is a slender satchel made of soft "+
      "leather, lined with %^BOLD%^%^BLACK%^velvet %^RESET%^%^ORANGE%^"+
      "to protect crystals from scratches.  The satchel is decorated "+
      "with faint etchings of crystals in various shapes and features "+
      "a leather thong that serves as a drawstring to close the satchel.\n\n"+
      "%^RESET%^"+
      "     To check what is in the satchel, type <components>.\n\n"+
      "     To put a crystal into the satchel, type:\n"+
      "     <put [component name] into components bag>\n\n"+
      "     To see how many of a particular crystal you have, type:\n"
      "     <rummage for [component name]>\n\n"
      "     To retrieve crystals from the satchel, type:\n"+
      "     <produce [quantity] [component name]>\n"+
	"     <produce [all] [component name]>\n\n"+
      "     To produce all components in the bag at once, type:\n"
      "     <empty bag>\n"
      "     %^BOLD%^%^RED%^NOTE:%^RESET%^ Make sure the satchel you want to empty\n "
      "     is the first in your inventory.\n\n"
      "     This satchel will only hold those crystals needed for \n"+
      "     manifesting psionic powers.\n"
           );
}

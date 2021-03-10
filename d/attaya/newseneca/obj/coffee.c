//coffee.c - Coffee for the mage tower of new Seneca
//~Circe~ 1/3/07
inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("coffee");
   set_id(({"coffee","mug of coffee","steaming coffee","steaming mug of coffee","drink"}));
   set_strength(15);
   set_weight(1);
   set_type("soft drink");
   set_empty_name("mug");
   set_short("%^RESET%^%^ORANGE%^A steaming mug of "+
      "%^BOLD%^%^BLACK%^coffee%^RESET%^");
   set_destroy();
   set_long("%^BOLD%^%^BLACK%^Rich liquid so deeply brown as to "+
      "appear black swirls lightly in a glazed %^RESET%^%^ORANGE%^"+
      "ceramic mug%^BOLD%^%^BLACK%^.  This particular drink is "+
      "highly prized among those who need a bit of a pick-me-up, "+
      "especially while studying.%^RESET%^");
   set_my_mess("The warmth of the steaming liquid spreads through your body as you sip the exquisite coffee.");
   set_your_mess("wraps "+TP->QP+" hands around the warm mug and sips the coffee.");
}

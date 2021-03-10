#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("pants");
   set_id(({"pants","ragged pants"}));
   set_short("%^RESET%^%^ORANGE%^ragged pants%^RESET%^");
   set_long("These pants are old and horribly %^ORANGE%^dirty%^RESET%^. They may have once belonged to a "
"child, judging by their size, but are obviously barely fit to be worn anymore. The left leg has been ripped "
"off at the knee, and a jagged tear runs down the opposite leg. It's impossible to tell what color they "
"originally were, as they are too coated in %^BOLD%^%^BLACK%^dirt %^RESET%^and %^ORANGE%^grime%^RESET%^.\n");
   set_weight(2);
   set_value(2);
   set_limbs(({"left leg","right leg"}));
   set_type("clothing");
   set_size(1);
   set_lore("These would have once belonged to a child, probably one that resided in Kilgore Keep in its days of glory. Chances are the xvarts found these among all the other items they destroyed and stole in their invasion, and took them for their own.\n");
   set_property("lore difficulty",2);
   set_wear("%^ORANGE%^You drag on the pants, nearly tearing one of the old seams.%^RESET%^");
   set_remove("%^ORANGE%^You strip out of the ragged pants.%^RESET%^");
}

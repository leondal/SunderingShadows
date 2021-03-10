#include <std.h>
#include <move.h>
inherit PARMOUR;

void create() {
   ::create();
   set_name("gem pouch");
   set_id(({"gem pouch","pouch","velvet pouch"}));
   set_short("%^BOLD%^%^BLACK%^A velvet pouch%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a sleek black velvet pouch, designed to "
"be worn on a belt. The faint outline of a letter 'K' can be seen still within "
"the fabric, though the stitching has long since been pulled out. Pouches such "
"as this are generally designed for carrying gems, as the velvet helps protect "
"the gems somewhat from scratching and chipping.%^RESET%^\n");
   set_lore("This black velvet pouch is quite fragile and was obviously made "
"for a noble, judging by the expensive material.  You recall that the family "
"name belonging to the keep northeast of Offestry was 'Kilgore' and surmise "
"that the purse probably belonged to a member of that family, given the letter "
"faintly visible upon it.");
   set_property("lore difficulty",4);
   set_weight(5);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_value(10);
   set_max_internal_encumbrance(8);
}

int query_size() {
   if(!userp(ETO)) return 2;
   return ETO->query_size();
}

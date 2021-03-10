#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create() {
   ::create();
   set_name("robe");
   set_id(({"robe","shroud","black robe","shroud of davros","simple robe"}));
   set_short("%^BOLD%^%^BLACK%^Shroud of Davros%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a simple black robe%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This robe is long and of a simple cut, with "
"sleeves down to the wrist and a high neckline.  %^RESET%^Plain black linen "
"%^BOLD%^%^BLACK%^has been used in its creation, with no decoration save for a "
"printed design upon the left sleeve.  It has been formed by some kind of "
"%^RESET%^%^ORANGE%^glittering bronzed %^BOLD%^%^BLACK%^ink or dye, shaping the "
"outline of a coiling dragon.  Its wings are spread, its tail wrapping the "
"garment's wrist and its head coiling up as if peering over the wearer's "
"shoulder.  You think perhaps you could keep some small items in the pockets, "
"if you %^YELLOW%^put item in robe%^BLACK%^.%^RESET%^\n");
   set_lore("From your studies you recall that the master of Keep Kilgore, "
"northeast of Offestry, was a man known as Davros.  He was reputed to be a mage "
"of some minor skill, and spent much of his time researching dragons and rumors "
"of their magical abilities.  Years later in 596, a strange sickness swept "
"through the Kilgore family, leaving no surviving relatives, and allowing the "
"keep to fall into disrepair.  The robe's pockets are used to hold small "
"amounts of components.");
   set_property("lore difficulty",4);
   set_limbs(({"torso"}));
   set_type("clothing");
   set_weight(10);
   set_size(2);
   set_value(10);
   set_max_internal_encumbrance(10);
   set_wear((:TO,"wear_me":));
}

int wear_me() {
  tell_object(ETO,"%^ORANGE%^The dragon's image seems to peer over your shoulder as you don the robe.%^RESET%^");
  tell_room(EETO,"%^ORANGE%^The dragon's image seems to peer over "+ETO->QCN+"'s shoulder as "+ETO->QS+" dons the robe.%^RESET%^",ETO);
  return 1;
}

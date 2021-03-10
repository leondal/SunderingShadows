#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("wolfskin jacket");
   set_short("%^BLACK%^%^BOLD%^wolfskin jacket%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^furred jacket%^RESET%^");
   set_id(({"jacket"}));
   set_long("%^ORANGE%^This garment is only small, sewn to fit a short and rather stocky frame.  Thick "
"%^BLACK%^%^BOLD%^black%^RESET%^%^ORANGE%^ fur covers the jacket's outer surface, and treated leather "
"lines the inside, forming what looks like a very warm garment.  Small hooks, in the shape of a wolf's "
"%^WHITE%^claws%^ORANGE%^, hold the jacket down the front like buttons.%^RESET%^\n");
   set_weight(8);
   set_value(1+random(5)*230);
   set_type("clothing");
   set_ac(0);
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^Story tells that the dwarven warrior Gelthek Battlestorm battled a great "
"dire wolf alone, and killed it with his bare hands - supposedly, this jacket is the result of this "
"meeting.  Other tales tell that he challenged the wolf to a drinking competition, which the dwarf won, "
"and then took the wolf's coat as his prize. Noone really knows the true story behind the "
"jacket.%^RESET%^\n");
   set_property("lore difficulty",18);
   set_property("enchantment",3);
   set_limbs(({"torso"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^You wrap yourself in the %^BLACK%^%^BOLD%^thick-furred%^RESET%^%^ORANGE%^ "
"jacket.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" wraps "+ETO->QO+"self in the "
"%^BLACK%^%^BOLD%^thick-furred%^RESET%^%^ORANGE%^ jacket.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You remove the %^BLACK%^%^BOLD%^thick-furred%^RESET%^%^ORANGE%^ "
"jacket.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" removes the %^BLACK%^%^BOLD%^thick-furred%^RESET%^%^ORANGE%^ "
"jacket.%^RESET%^",ETO);
   return 1;
}

#include <std.h>
inherit "/std/armour";

void create(){
   ::create();
   set_name("%^BOLD%^%^BLACK%^Cloak of the wolves%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Cloak of the wolves%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A dark fur cloak%^RESET%^");
   set_id(({"cloak","wolf cloak","cloak of wolves","Cloak of wolves","Cloak of Wolves","wolves cloak"}));
   set_long("%^BOLD%^%^BLACK%^Soft dark fur glistens against the %^RESET%^light"
" %^BOLD%^%^BLACK%^in this extremely comfortable looking cloak.  The"
" entire length of the cloak is %^RESET%^m%^BOLD%^%^WHITE%^o%^BLACK%^t"
"%^RESET%^t%^BOLD%^%^WHITE%^l%^BLACK%^e%^RESET%^d %^BOLD%^%^BLACK%^in furs of dark"
" %^RESET%^gr%^BOLD%^%^BLACK%^a%^RESET%^y %^BOLD%^%^BLACK%^to midnight black as the"
" furs of many wolves were needed to create such a thick piece of clothing.  With"
" a medium sized human wearing it, this cloak would easily reach the ground and provide"
" ample protection from the elements.  A hood is fashioned from the same type of"
" fur, and when not worn, it rests easily against the rest of the cloak.   A"
" %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^WHITE%^e%^RESET%^r clasp"
" %^BOLD%^%^BLACK%^that displays the image of two canine eyes secures the cloak"
" in place and is etched with %^RESET%^%^MAGENTA%^ancient scripts"
" %^BOLD%^%^BLACK%^of %^RESET%^%^MAGENTA%^blessings.%^RESET%^\n");
   set_lore("%^BOLD%^%^BLACK%^It is said that a great shaman of a hunting tribe fashioned these cloaks before"
" the invasion on the Barionessa Forest.  With the blessings of the Beast Lord, and the protection of the cloaks,"
" many hobgoblins, orcs and other creatures set off into the night in persuit of the ultimate hunt.%^RESET%^");
   set_value(550);
   set_size(2);
   set_weight(12);
   set_limbs(({"neck"}));
   set_type("clothing");
   set_property("enchantment",3);
   set_wear((:this_object(),"wearme":));
}
int wearme(string str){
   if((int)ETO->query_level() < 15) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The cloak refuses to accept you and disentegrates!%^RESET%^");
      TO->remove();
      return 0;
   }
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" clasps the %^RESET%^silver clasp %^BOLD%^%^BLACK%^of the cloak and the canine eyes begin to %^CYAN%^glow.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^As you clasp the %^RESET%^silver clasp %^BOLD%^%^BLACK%^of the cloak in place, the canine eyes begin to %^CYAN%^glow.%^RESET%^");
   return 1;
}

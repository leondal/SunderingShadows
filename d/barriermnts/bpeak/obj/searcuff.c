#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^A sparkling silver earcuff%^RESET%^");
   set_id(({"earcuff","earring","cuff","ring"}));
   set_short("%^BOLD%^%^WHITE%^A sparkling silver earcuff%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This delicate earcuff is made from the purest silver."
"  Two ancient twisting trees are designed to wrap around one another as they climb"
" the length of the wearers earlobe.  Their delicate leaves grasp the lobe to gently"
" hold the cuff in place and add extra sparkle from every angle.%^RESET%^\n");
   set_weight(2);
   set_value(1200);
   set_type("ring");
   set_limbs(({"head"}));
   set_size(random(3)+1);
   set_property("enchantment",0);
   set_ac(0);
   set_wear((:this_object(),"wearme":));
   set_remove((:this_object(),"unwearme":));
}
int wearme(string str){
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^%^The leaves magically wrap around "+ETOQCN+"'s ear as "+ETO->query_subjective()+" slips on the earcuff.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^WHITE%^The leaves magically fold gently around your ear as you wear the earcuff.%^RESET%^");
      return 1;
 }
int unwearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The leaves of the earcuff release their magical hold on "+ETOQCN+" as it is removed.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^The leaves slowly release their grip as you remove the earcuff.%^RESET%^");
   return 1;
}
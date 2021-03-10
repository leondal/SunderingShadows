#include <std.h>
inherit "/d/common/obj/weapon/knife.c";

void create() {
    ::create();
   set_id(({"knife","hunters knife","blade"}));
   set_name("%^RESET%^%^ORANGE%^Hunters knife");
   set_obvious_short("A ragged knife");
   set_short("%^RESET%^%^ORANGE%^Hunters knife%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This knife is obviously one used by a hunter.  A sleek, black handle rises"
" into a thick, %^RESET%^%^RED%^blood-stained blade %^BOLD%^%^BLACK%^that is about four inches long with a"
" slight backwards curve. The lower half of the blade is sharp and fluent, like the edge of a sword,"
" while the upper half is serrated all the way to the pointed tip.%^RESET%^");
   set("value",700);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_wield((:this_object(),"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^The knife feels smooth and supple within your grip.%^RESET%^");     
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 215){
      tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" uses the knife to slashe deeply into "+target->query_cap_name()+"s flesh!%^RESET%^",({target,ETO}));
      tell_object(ETO,"%^RESET%^%^RED%^You slash deeply into "+target->query_cap_name()+"'s flesh with the knife!%^RESET%^",target);
      tell_object(target, "%^RESET%^%^RED%^"+ETO->query_cap_name()+" slashes deeply into your flesh with the knife!%^RESET%^");
      return roll_dice(1,6)+1;
   }
}
  

//ghost dagger
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create() {
    ::create();
   set_id(({"dagger","ghost dagger"}));
   set_name("%^RESET%^%^BOLD%^G%^RESET%^h%^BOLD%^o%^RESET%^s%^BOLD%^t bl%^RESET%^a%^BOLD%^de%^RESET%^");
   set_obvious_short("%^RESET%^A softly %^BOLD%^gl%^RESET%^o%^BOLD%^w%^RESET%^i%^BOLD%^ng %^RESET%^dagger");
   set_short("%^RESET%^%^BOLD%^G%^RESET%^h%^BOLD%^o%^RESET%^s%^BOLD%^t bl%^RESET%^a%^BOLD%^de%^RESET%^");
   set_long("%^RESET%^%^BOLD%^About four inches long, the nearly"
" %^RESET%^tra%^BOLD%^nsl%^RESET%^u%^BOLD%^c%^RESET%^ent %^BOLD%^blade of this dagger has been honed"
" to an extremely fine point.  The handle of the blade is made of the same strange substance, but has been wrapped"
" with leather dyed a crisp white.  Near the base of the blade, strange runes shift in form, and are unlike"
" anything of this plane.%^RESET%^");
   set_lore("%^BOLD%^Little is known about this blade or its type.  It has been rumored however, that it is the result"
" of some strange dark magics that happened in or around the Yntala forest years ago.  Most of the rumors were"
" dismissed though as myth, and nothing has been said of it since.");
   set("value",1000);
   set_cointype("gold");
   set_property("enchantment",2);  
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
      tell_room(environment(ETO),"%^RESET%^%^BOLD%^A strange look crosses "+ETOQCN+"'s face as "+ETO->query_possessive()+" grips the dagger.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^BOLD%^You are over come by a strange sense of calm as you wrap your fingers around the dagger.%^RESET%^");
                return 1;
}
int unwield_func(){
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(500) < 50){
      switch(random(4)){
         case 0..1:
  	      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" quickly spins around and slashes deeply into "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^With amazing quickness and agility, you spin around and slash deeply into  "+target->query_cap_name()+"'s flesh with the dagger!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^WHITE%^With quickness and agility rarely seen, "+ETO->query_cap_name()+" spins around and slashes deeply into your flesh with the dagger!%^RESET%^");
            target->do_damage("torso",random(4)+1);
         break ;
 	   case 2..3:
  	      tell_room(environment(ETO),"%^RESET%^%^BOLD%^The dagger "+ETO->query_cap_name()+" holds %^BOLD%^%^CYAN%^glows brightly %^RESET%^%^BOLD%^as "+ETO->query_subjective()+" plunges it deep into "+target->query_cap_name()+"'s flesh!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^BOLD%^The dagger %^BOLD%^%^CYAN%^glows brightly %^RESET%^%^BOLD%^as you plunge it deeply into "+target->query_cap_name()+"'s flesh!%^RESET%^");
            tell_object(target,"%^RESET%^%^BOLD%^The dagger in "+ETO->query_cap_name()+"'s hand %^BOLD%^%^CYAN%^glows brightly %^RESET%^%^BOLD%^as "+ETO->query_subjective()+" plunges it deeply into your flesh, sending chills down your spine!%^RESET%^");
            target->set_paralyzed(15,"You are still shivering!");
            target->do_damage("torso",random(5)+1);
      }
   }
}

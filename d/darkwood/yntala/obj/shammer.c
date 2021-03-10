//shammer.c
#include <std.h>
inherit "/d/common/obj/weapon/hammer_sm.c";

void create() {
    ::create();
   set_id(({"hammer","small hammer","Delorn's Hammer"}));
   set_name("%^RESET%^%^ORANGE%^Delorn's hammer%^RESET%^");
   set_obvious_short("a polished small hammer");
   set_short("%^RESET%^%^ORANGE%^Delorn's hammer%^RESET%^");
   set_long("%^RESET%^This is a small hammer that could probably be easily wielded by a gnome.  The handle is made"
" from %^ORANGE%^polished mohogany %^RESET%^and wrapped with a soft, supple %^ORANGE%^leather %^RESET%^for better"
" grip.  The head of the hammer has been forged from gleaming adamantium that has been polished to a superb"
" finish.  Small %^CYAN%^runes %^RESET%^have been etched onto the underside of the head, while the sides have the"
" image of a %^ORANGE%^giant eagle %^RESET%^in %^BOLD%^%^WHITE%^flight%^RESET%^, its %^ORANGE%^wings %^RESET%^spread"
" out magestically so that the tips of the %^ORANGE%^wingfeathers %^RESET%^just reach either end of the head.%^RESET%^");
   set_lore("It is rumored that this very hammer belonged to Esylibelibob Delorn, one of the twelve mages that took up residence in the Yntala forest.  Nobody knows exactly what happened to Delorn, but it is rumored that they use to practice dark things deep within the forest.");
   set("value",750);
   set_cointype("gold");
   set_property("enchantment",2);  
   set_item_bonus("dexterity",1);
   set_wield((:this_object(),"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   tell_object(ETO,"%^RESET%^You feel a %^BOLD%^%^WHITE%^surge %^RESET%^of %^CYAN%^power %^RESET%^and %^CYAN%^confidence %^RESET%^as you wrap your fingers around the smooth, %^ORANGE%^supple handle %^RESET%^of the hammer.%^RESET%^");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 50){
  	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" quickly spins around and smashes the  hammer into "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
      tell_object(ETO,"%^BOLD%^%^WHITE%^With amazing quickness and agility, you spin around to smash the hammer into "+target->query_cap_name()+"!%^RESET%^",target);
      tell_object(target,"%^BOLD%^%^WHITE%^With quickness and agility rarely seen, "+ETO->query_cap_name()+" spins around and smashes the hammer into you!%^RESET%^");
      return random(5)+1;
   }
}

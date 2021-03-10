// really big sword for giants
#include <std.h>
inherit "/d/common/obj/weapon/whip_dagger";

void create() {
    ::create();
   set_id(({"whip","chain","spiked chain"}));
   set_name("%^BOLD%^%^WHITE%^Bladed Chain%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A Bladed Chain%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^A Bladed Chain%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This weapon looks similar to a "+
   "whip dagger only it is made of chain.  There is a "+
   "leather handle at one end of the weapon.  "+
   "Unlike a morning star, the end has a %^GREEN%^curved blade%^CYAN%^ "+
   "that is serrated.  It is weighted so that one can "+
   "trip their foes.  The blade is made of a %^BOLD%^%^BLACK%^dark "+
   "metal%^RESET%^ %^CYAN%^and has a %^BOLD%^glowing rune%^RESET%^%^CYAN%^"+
   " etched on it.%^RESET%^");
	set_lore("This weapon was created by a cult of"+
   " underdark hunters.  They use these weapons to "+
   "keep the prey from escaping when facing a beast "+
   "that would flee.");
   set_property("lore difficulty",15);
   set("value",1000);
   set_property("enchantment",2+random(2));  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 10 ) {
      tell_object(ETO,"%^RED%^You cut yourself on the blade.");
	  ETO->cause_typed_damage(ETO,0,roll_dice(5,10),"slashing");
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(EETO,"%^CYAN%^The rune on "
	   +ETOQCN+"'s weapon glows %^RED%^darkly.",ETO);
      tell_object(ETO,"%^CYAN%^The rune on the blade glows %^RED%^darkly.");
      return 1;
}
int unwield_func(){
   tell_room(EETO,"%^CYAN%^The weapon of "+ETOQCN+" stops glowing.",ETO);
   tell_object(ETO,"%^CYAN%^The blade stops glowing unwielded.");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(400) < 100){
     switch(random(5)){
      case 0..3:
        tell_room(EETO,"%^RED%^The chain wraps around "
		  +target->QCN+" cutting them when pulled back.",({target,ETO}));
        tell_object(ETO,"%^RED%^The chain wraps around "+target->QCN+
            ".  You pull back and cut them deeply with the blade. ",target);
        tell_object(target, "%^RED%^"
			  +ETO->query_cap_name()+" chained weapon wraps around "+
			  " you and the blade cuts you deeply when pulled back.");
         return roll_dice(1,8)+2;

         case 4:
            tell_room(EETO,"%^RED%^The chained blade"+
			 " wraps around "+target->QCN+"'s legs pulling"+
			 " them to the ground when pulled back."
			 ,({target,ETO}));
            tell_object(ETO,"%^RED%^"+target->QCN+
			" is pulled to the ground by the chained blade.",target);
            tell_object(target, "%^RED%^"+ETO->QCN+"'s chained blade"+
			  " wraps around your legs and pulls you to the ground.");
            target->set_tripped(1,"%^RED%^You try to get up, but the world is spinning.");
            return roll_dice(1,4)+1;
      }
   }
}

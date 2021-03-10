#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();
   set_id(({"sword","short sword","wounder","esau"}));
   set_name("esau");
   set_obvious_short("%^BOLD%^%^RED%^A b%^RESET%^%^RED%^l%^BOLD%^%^RED%^e%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^RESET%^%^RED%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g %^BOLD%^%^RED%^s%^RESET%^%^RED%^h%^BOLD%^%^RED%^o%^RESET%^%^RED%^r%^BOLD%^%^RED%^t %^RESET%^%^RED%^s%^BOLD%^%^RED%^w%^RESET%^%^RED%^o%^BOLD%^%^RED%^r%^RESET%^%^RED%^d%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^E%^RESET%^%^BLUE%^s%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^u %^BOLD%^%^BLACK%^the %^BOLD%^%^RED%^W%^RESET%^%^RED%^o%^BOLD%^%^RED%^u%^RESET%^%^RED%^n%^BOLD%^%^RED%^d%^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^, %^BOLD%^%^BLACK%^G%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^e %^BOLD%^%^WHITE%^and %^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^n%^RESET%^");
   set_long("%^RESET%^%^RED%^The slightly curved blade on this short sword makes it"+
   " distinctly different from other short swords in design."+
   " However, the differences only begin there. The"+
   " traditional double edge is now a single %^BOLD%^%^WHITE%^keen edge."+
   " %^RESET%^%^RED%^the other side of the blade is brutually serrated and"+
   " %^RESET%^%^BLUE%^barbed %^RESET%^%^RED%^on the inside curve of the blade, perfect for"+
   " ripping %^RESET%^%^ORANGE%^flesh %^RESET%^%^RED%^when pulled back towards the wielder."+
   " The %^BOLD%^%^BLACK%^black leather handle %^RESET%^%^RED%^is nothing fancy and seems to only"+
   " serve its pratical purpose of being a firm grip for the"+
   " blade. Every now and again, you notice a drop of %^BOLD%^%^RED%^blood"+
   " %^RESET%^%^RED%^falling from the tips of the serrated edge%^RESET%^.");
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5); 
   }
   set_heart_beat(1);
   set_weapon_prof("exotic");
   set_value(9000);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
   set_lore(
      "%^RESET%^%^RED%^Esau was thought to be an extremely skilled assassin whom"+
      " never failed to kill his target. However, it was eventually"+
      " revealed that his secret to success was not his physical prowess, intelligence, or agility. It was his stolen swords; seven of them to be exact."+
	 " Each sword possessed a special ability and all Esau had to do"+
	 " was pick the right sword for the job."+
      " No one knows where he had stolen the swords from or who"+
      " originally made them."
   );
}

int wieldit() {
   int myflag, i;
   object *mywielded;
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"%^BOLD%^%^RED%^You are not strong enough to wield this sword.");
     return 0;
   }

   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
      tell_object(ETO,"You find it impossible to lift two such mighty weapons!",ETO);
      return 0;
   }
   tell_object(ETO,"%^RESET%^%^RED%^You grip the %^BOLD%^%^BLACK%^leather handle %^RESET%^%^RED%^of the %^BOLD%^%^RED%^g%^RESET%^%^RED%^r%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^%^RED%^blade."); 
   ETO->add_attack_bonus(3);
   ETO->add_damage_bonus(3);
   ETO->set_property("master weapon",1);
   return 1;
}

int unwieldit(){
   tell_object(ETO,"%^RESET%^%^RED%^You release the %^BOLD%^%^BLACK%^leather handle %^RESET%^%^RED%^of the %^BOLD%^%^RED%^g%^RESET%^%^RED%^r%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^%^RED%^blade.");
   ETO->add_attack_bonus(-3);
   ETO->add_damage_bonus(-3);
   ETO->set_property("master weapon",-1);
   return 1; 
}

int hitit(object targ){
      if(!objectp(TO)) return 1;
      if(!objectp(ETO)) return 1;
      if(!objectp(targ)) return 1;
      if(!targ->query_property("esaucursed")) {
         object ob;
         ob = new("/d/danger/obj/ewound");
         ob->move(targ);
      }else{
      targ->set_property("woundstack",1);
      if(!random(10)) {
      switch(random(4)) {
      case 0:
   tell_object(ETO,"%^BOLD%^%^BLACK%^You jam your sword into "+targ->QCN+"'s shoulder blade and %^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^ts%^RESET%^!");
   tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" jams "+ETO->query_possessive()+" sword into your shoulder blade and %^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^ts%^RESET%^!");
   tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" jams "+ETO->query_possessive()+" sword into "+targ->query_cap_name()+"'s shoulder blade and %^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^ts%^RESET%^!",({ETO,targ}));
   targ->set_paralyzed(7,"%^BOLD%^%^GREEN%^The pain is overwhelming%^RESET%^!");
   return roll_dice(3,10);
   break;
   case 1:
   tell_object(ETO,"%^RESET%^%^CYAN%^You strike out visicously and the %^BOLD%^%^BLACK%^shadows%^RESET%^%^CYAN%^ echo your attack%^RESET%^!");
  tell_object(targ,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+" lashes out at you and the %^BOLD%^%^BLACK%^shadows %^RESET%^%^CYAN%^seem to mimic "+ETO->query_possessive()+" attack%^RESET%^!");
   tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+" lashes out and the %^BOLD%^%^BLACK%^shadows %^RESET%^%^CYAN%^seem to come alive%^RESET%^!",({ETO,targ}));
   ETO->execute_attack();
   break;
   case 2:
   tell_object(ETO,"%^RESET%^%^BLUE%^The serrated blade of your weapon tears into "+targ->query_name()+" and digs deep into the %^BOLD%^%^RED%^flesh%^RESET%^!");
  tell_object(targ,"%^RESET%^%^BLUE%^"+ETO->query_cap_name()+" tears into your flesh with the serrated end of "+targ->query_possessive()+" blade and you feel a bit woozy%^RESET%^!");
   tell_room(environment(query_wielded()),"%^RESET%^%^BLUE%^"+ETO->query_cap_name()+" tears into "+targ->query_name()+" with the serrated end of the blade%^RESET%^!",({ETO,targ}));
    targ->add_poisoning(35);
    return (20+random(20));
   break;
   case 3:
   tell_object(ETO,"%^BOLD%^%^RED%^You cut through "+targ->query_name()+" with ease%^RESET%^!");
  tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" cuts through you with ease%^RESET%^!");
   tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"cuts through "+targ->query_name()+" with ease%^RESET%^!",({ETO,targ}));
   return roll_dice(3,10);
   break;
   return 1;
}
return 1;
}
}
}

void heart_beat(){
   if(!objectp(TO)) return 1;
      if(!random(50) && query_wielded()){
      tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^The serrated sword in the hand of "+query_wielded()->query_cap_name()+" drips blood on the ground%^RESET%^.",query_wielded());
      tell_object(query_wielded(),"%^BOLD%^%^RED%^You hear a drip... drip... drip... as the sword bleeds onto the ground%^RESET%^.");
}
}

	//Essyllis: Feb 2015


#include <std.h>
#include "../lgnoll.h"
inherit "/d/common/obj/weapon/giant_bastard";

void create(){
  ::create();
  set_id(({"giant whip","whip","blueflame","blueflame whip"}));
  set_name("blueflame whip");
  set_obvious_short("%^CYAN%^A giant blue %^BOLD%^chainwhip%^RESET%^");
  set_short("%^BOLD%^%^RED%^%^BOLD%^%^BLUE%^blue%^CYAN%^flame %^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This %^BLUE%^giant w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^BLACK%^consists "+
   "mainly of a %^RESET%^%^CYAN%^massive chain %^BOLD%^%^BLACK%^at least 20 feet long. Each "+
   "%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^nk %^BOLD%^%^BLACK%^in the %^RESET%^%^CYAN%^chain "+
   "%^BOLD%^%^BLACK%^is nearly 3 inches thick and 5 inches long. The %^RESET%^%^CYAN%^chain "+
   "%^BOLD%^%^BLACK%^itself has a %^RESET%^%^CYAN%^bl%^BOLD%^%^BLUE%^u%^CYAN%^i%^RESET%^%^CYAN%^sh "+
   "c%^BOLD%^%^BLUE%^o%^RESET%^%^CYAN%^l%^BOLD%^o%^RESET%^%^CYAN%^r %^BOLD%^%^BLACK%^and is not made of "+
   "any known m%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l. You can "+
   "feel the %^RESET%^%^RED%^h%^CYAN%^e%^RED%^at r%^CYAN%^a%^RED%^di%^CYAN%^a%^RED%^t%^CYAN%^i%^RED%^ng "+
   "%^BOLD%^%^BLACK%^from the metal. The %^RESET%^handle %^BOLD%^%^BLACK%^of the %^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p "+
   "%^BLACK%^is made from the skin of a %^CYAN%^Bl%^BLUE%^u%^CYAN%^e dr%^BLUE%^a%^CYAN%^g%^BLUE%^o%^CYAN%^n "+
   "%^BLACK%^to %^RESET%^%^BLUE%^insulate %^BOLD%^%^BLACK%^the wielder's hands against the "+
   "%^RESET%^%^RED%^heat%^BOLD%^%^BLACK%^. The handle itself is way too big for any human to wield.\n");
  set_lore("This weapon is said to belong to the Wemic hero 'Khamvani'. One of the greatest defenders of the wemic tribes in "+
  "the desert near Shadow, Khamvani was to be chieftain of his tribe when they were attacked by Gnolls. The gnolls are said "+
   "to have killed his female and three of his cubs, driving him near-insane with grief and thirst for revenge. It is said that "+
   "he grew more insane as years went by, and should be avoided at all costs. It is also said that he can always be "+
   "found where there are gnolls to kill. - Sallonir deldor, Bard of Torm  ");
  set_value(3000);
  set_property("enchantment",3);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
}

int extra_hit(object targ) {
  
  if(!living(ETO) || !living(targ)) {return 0;}
  if(random(1000) < 200){
	  switch(random(100)){
		  case 0..9:{
			  tell_object(ETO,"%^RED%^You can feel the heat as your whip starts bu%^BOLD%^i%^RESET%^%^RED%^ld%^BOLD%^i%^RESET%^%^RED%^ng %^BOLD%^u%^RESET%^%^RED%^p %^BOLD%^energy!");
			  tell_object(targ,"%^RED%^You notice %^WHITE%^"+ETO->QCN+"%^RED%^'s whip gl%^BOLD%^o%^RESET%^%^RED%^w%^BOLD%^i%^RESET%^%^RED%^ng br%^BOLD%^i%^RESET%^%^RED%^g%^BOLD%^h%^RESET%^%^RED%^t%^BOLD%^e%^RESET%^%^RED%^r %^BOLD%^a%^ORANGE%^n%^RESET%^%^RED%^d %^BOLD%^br%^ORANGE%^i%^RED%^g%^ORANGE%^h%^RED%^t%^ORANGE%^e%^RED%^r%^RESET%^%^RED%^!");
			  tell_room(EETO,"%^RED%^You see %^WHITE%^"+ETO->QCN+"%^RED%^'s %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p%^RESET%^%^RED%^ gl%^BOLD%^o%^RESET%^%^RED%^w%^BOLD%^i%^RESET%^%^RED%^ng br%^BOLD%^i%^RESET%^%^RED%^g%^BOLD%^h%^RESET%^%^RED%^t%^BOLD%^e%^RESET%^%^RED%^r %^BOLD%^a%^ORANGE%^n%^RESET%^%^RED%^d %^YELLOW%^b%^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^g%^YELLOW%^h%^RESET%^%^RED%^t%^BOLD%^e%^RESET%^%^RED%^r%^YELLOW%^!",ETO);
			  new("/cmds/spells/f/_fireball")->use_spell(ETO,targ,8,8,"mage");
		  return 1;}
		  break;
		  case 10..30:{
			  
				  tell_object(ETO,"%^ORANGE%^With a mighty %^RED%^pull %^ORANGE%^of your %^BLUE%^f%^CYAN%^l%^BOLD%^am%^RESET%^%^CYAN%^in%^BLUE%^g w%^CYAN%^h%^BOLD%^i%^RESET%^%^BLUE%^p%^ORANGE%^, you pull %^WHITE%^"+targ->QCN+" %^ORANGE%^off %^WHITE%^"+targ->QP+" %^ORANGE%^feet and %^BOLD%^%^CYAN%^flying %^RESET%^%^ORANGE%^through the %^BOLD%^%^CYAN%^air!");
				  tell_object(targ,"%^ORANGE%^You are caught by %^WHITE%^"+ETO->QCN+"%^ORANGE%^'s %^BOLD%^%^BLUE%^f%^RESET%^%^CYAN%^la%^BOLD%^mi%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^g w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^RESET%^%^ORANGE%^and sent sailing through the %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^!");
				  tell_room(EETO,"%^ORANGE%^You see %^WHITE%^"+targ->QCN+" %^ORANGE%^get caught by %^WHITE%^"+ETO->QCN+"%^ORANGE%^'s %^BOLD%^%^BLUE%^fl%^RESET%^%^CYAN%^a%^BOLD%^mi%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^g w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^RESET%^%^ORANGE%^and sent %^BOLD%^%^CYAN%^flying %^RESET%^%^ORANGE%^through the %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^!",ETO);
				  targ->do_damage(targ->return_target_limb(),roll_dice(2,4)+3);
				  targ->set_tripped(1,"You had a hard landing, get your breathe back first");
			  return 1;}break;
		  case 31..99:{
			  tell_object(ETO,"%^ORANGE%^As you %^RED%^crack %^ORANGE%^the %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^RESET%^%^ORANGE%^at %^WHITE%^"+targ->QCN+" %^ORANGE%^it %^BOLD%^%^RED%^flares %^BLUE%^v%^CYAN%^io%^BLUE%^l%^CYAN%^en%^BLUE%^t%^CYAN%^ly %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^burns %^RESET%^"+targ->QCN+" %^RED%^badly%^ORANGE%^!");
			  tell_object(targ,""+ETO->QCN+"%^ORANGE%^'s %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^RED%^flares %^BLUE%^v%^CYAN%^i%^BLUE%^o%^CYAN%^l%^BLUE%^e%^CYAN%^n%^BLUE%^t%^CYAN%^y %^RESET%^%^ORANGE%^as "+ETO->QS+" %^RED%^cracks %^ORANGE%^it at you, %^BOLD%^%^RED%^burning %^RESET%^%^ORANGE%^you badly!");
			  tell_room(EETO,""+ETO->QCN+"%^ORANGE%^'s %^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^RED%^flares %^RESET%^%^ORANGE%^up %^BOLD%^%^BLUE%^v%^CYAN%^i%^BLUE%^o%^CYAN%^l%^BLUE%^e%^CYAN%^n%^BLUE%^t%^CYAN%^l%^BLUE%^y %^RESET%^%^ORANGE%^as it is %^RED%^cracked %^ORANGE%^and %^BOLD%^%^RED%^burns %^RESET%^"+targ->QCN+" %^ORANGE%^badly!",ETO);
			  targ->do_damage(targ->return_target_limb(),roll_dice(2,4)+3);
		  return 1;}break;
	  return 1;}
  }
}  
  
int extra_wield(){
  if((int)ETO->query_level()<20) {
   tell_object(ETO,"%^BOLD%^%^RED%^Uou are unable to control the powerful whip and are burned badly!");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"%^BOLD%^%^RED%^ cannot control the powers in the whip and is burned badly!",ETO);
   ETO->do_damage(ETO->return_target_limb(),roll_dice(4,10)+10);
  return 0;}
  tell_object(ETO,"%^BOLD%^The %^BLUE%^blue%^CYAN%^flame %^BLUE%^W%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^WHITE%^springs to life with %^CYAN%^v%^BLUE%^i%^CYAN%^v%^BLUE%^i%^CYAN%^d fl%^BLUE%^a%^CYAN%^m%^BLUE%^e%^CYAN%^s %^WHITE%^as you wield it!");
  tell_room(EETO,"%^BOLD%^The %^BLUE%^blue%^CYAN%^flame %^BLUE%^w%^RESET%^%^CYAN%^h%^BOLD%^i%^BLUE%^p %^WHITE%^springs to life with %^CYAN%^bl%^BLUE%^u%^CYAN%^e fl%^BLUE%^a%^CYAN%^m%^BLUE%^e%^CYAN%^s %^WHITE%^as %^RESET%^"+ETO->QCN+" %^BOLD%^wields it!",ETO);
  return 1;
}


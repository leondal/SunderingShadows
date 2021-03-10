//Updated knife - Desc from Nom - Cythera 8/05
#include <std.h>
inherit "/d/common/obj/weapon/knife.c";

void create(){
	::create();
set_id(({"knife","tanto","dagger","tanto of the lost hope"}));
  	set_name("tanto");
  	set_short("%^RESET%^%^CYAN%^Tanto of the %^MAGENTA%^L%^BLUE%^"+
		"o%^MAGENTA%^s%^BLUE%^t %^CYAN%^H%^BLUE%^o%^CYAN%^p"+
		"%^BLUE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A straight blade knife%^RESET%^");
  	set_long("%^CYAN%^The blade of this exquisite looking knife is about"+
		" nine inch long and is forged from dull, %^BOLD%^%^BLACK%^dark"+
		" gray titanium%^RESET%^%^CYAN%^. The straight blade is %^RESET%^"+
		"%^BOLD%^broad and sharp%^RESET%^%^CYAN%^ looking outer edge that"+
		" ends in a sharp point. Patterns resembling %^GREEN%^sn%^BOLD%^ak"+
		"e%^RESET%^%^GREEN%^s%^RESET%^%^CYAN%^ that %^GREEN%^co%^BOLD%^i"+
		"%^RESET%^%^GREEN%^l%^CYAN%^ and devoure each other cover one "+
		"side of the blade. The engravings are %^BLUE%^tinted dark "+
		"blue%^RESET%^%^CYAN%^, yet still very visible.  %^BLUE%^Dark"+
		" blue%^RESET%^%^CYAN%^ leather is wrapped around the hiltless"+
		" pommel of the knife%^RESET%^");
	set_lore("The Tanto of Lost Hope was once a knife commonly used by a "+
		"guild of assassins known as the Slayers of Hope.  The assassins"+
		" seemed to favor taking jobs that resulted in the death of a "+
		"family member or loved one of their target before they finished"+
		" their job.  Taking the victim before the person they were hired"+
		" to kill, the assassins slowly killed them to torture their target"+
		".  The guild was rumored to have been exposed and each member hunted"+
		" down and killed by a Lord Phenius Larrow, a paladin of Tyr.");
	set_property("lore",15);
    	set_value(1000);
    	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
     	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 16) {
      tell_object(ETO,"%^CYAN%^The knife slips out of your grasp.");
      tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" fumbles when"+
		" trying to wield the knife and drops it.");
	return 0;
}
        tell_object(ETO,"%^CYAN%^You feel as if all hope is lost as you wield"+
		" the knife.");
   	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" gives a long grim sigh"+
		" as "+ETO->QP+" fingers clutch onto the knife.",ETO);
			ETO->set_property("evil item",1);

     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^CYAN%^You feel hope returning to you as you "+
		"release the knife.");
   	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" seems to cheer"+
		" up somewhat as "+ETO->QS+" releases the knife.",ETO);
   			ETO->set_property("evil item",-1);
   	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   	
	if(!random(8)) {
  		tell_object(ETO,"%^BLUE%^A dark blue aura cloaks the "+
			"blade of the knife as you plunge it into"+
			" "+victim->QCN+".");
      	tell_object(victim,"%^BLUE%^You feel hope draining away as"+
			" the dark blue aura on "+ETO->QCN+"'s knife feeds "+
			"off of you.");
      	tell_room(environment(ETO),"%^BLUE%^A dark blue aura "+
			"cloaks the blade of "+ETO->QCN+"'s knife as "+
			""+ETO->QS+"  plunges it into "+victim->QCN+"."+
			"",({ETO,victim}));
       			victim->do_damage("torso",random(5)+3);
		return 1;	
	}
	if(!random(18)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^An inky black film coats "+
			"the blade of your knife as you tear into "+victim->QCN+".");
      	tell_object(victim,"%^BOLD%^%^BLACK%^You feel a sense of loss "+
			"and hopelesses take root in your soul as "+ETO->QCN+" "+
			"tears into you.",);
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^An inky black "+
			"film coats the blade of "+ETO->QCN+"'s knife as "+
			""+ETO->QS+" tears into "+victim->QCN+".",({ETO,victim}));
				victim->do_damage("torso",random(8)+4);
      	return 1;
	}
}

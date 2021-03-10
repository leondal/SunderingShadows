#include <std.h>
inherit "/d/common/obj/weapon/two_hand_scythe.c";

void create()
{
   	::create();
   	set_name("jet scythe");
   	set_short("%^BOLD%^%^BLACK%^Night Reaver%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A scythe made of jet%^RESET%^");
   	set_id(({"scythe","jet scythe","night reaver"}));
   	set_long("%^BOLD%^%^BLACK%^This handle of the scythe is made from"+
		" a long and polished piece of solid jet, it is so black "+
		"it seems almost to absorb the light that shines on it. "+
		"The blade is joined at the top by a %^CYAN%^steel%^BLACK%^"+
		" setting, it is curved and very sharp. A large %^BOLD%^"+
		"%^BLUE%^b%^GREEN%^l%^BLUE%^a%^BLACK%^c%^BLUE%^k %^BLACK%^"+
		"o%^BLUE%^p%^GREEN%^a%^BLACK%^l has been imbedded at "+
		"the bottom of the long handle.%^RESET%^");
	set_lore("The Night Reaper was a fearsome weapon that was once"+
		" used by a half-drow warrior only known as The Hope "+
		"Reaper.  This fearsome figure dressed in long flowing+"+
		" black robes that were tattered and worn.  His white "+
		"hair was always dishelven.  He was said to have worn a"+
		" darksteel mask over his face, that took the shape of a"+
		" skull.  The Hope Reaper preyed upon families and young"+
		" lovers in Heartlands, fertile farmlands that supply food"+
		" for all the cities on the main land.  The Hope Reaper "+
		"with his jet scythe broke into homes, slaying newborn "+
		"babes and newlywed couples.  He struck at random, which"+
		" only made it more difficult to catch him.  On a warm "+
		"spring night in 438, the Hope Reaper met his end at the "+
		"hands of a priestess of Lathander by the name of Vionetta,"+
		" who disguised herself as a simple midwife. Those who saw "+
		"the battle said that the Hope Reaper melted away in a black"+
		" mist under the power of Vionetta's spells, but all anyone"+
		" found were his tattered robes.  Some claim that the Hope "+
		"Reaper is still out there, preying on the newborn and "+
		"newlyweds to spread loss to the world.");
	set_property("lore",10);
	set_value(2000);
      set_property("enchantment",3);
   	set_hit((:TO,"hitme":));
	set_value(2000);
	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
     		tell_object(ETO,"%^BOLD%^%^BLACK%^You feel compelled to "+
			"slay and reap the hope that in the world as you "+
			"wield the jet scythe.");
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A grim and "+
			"sinister fire flickers in "+ETO->QCN+"'s eyes as"+
			" "+ETO->QS+" graps on to the jet scythe.",ETO);
     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^BLACK%^The obsession to slay and reap"+
		" the hope in the world passes as you release the jet scythe.");
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The grim and sinster "+
		"look in "+ETO->QCN+"'s eyes fades as "+ETO->QS+" releases"+
		" the scythe.",ETO);
     	return 1;
}

int hitme(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
   	
	if(!random(8)) {
      	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s jet scythe"+
      		" whistles through the air before it slices you!");
      	tell_object(ETO,"%^BOLD%^%^BLUE%^Your scythe whistles through the air"+
      		" before slicing into "+targ->QCN+"!");
      	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s jet"+
      		" scythe whistles through the air before slicing"+
			" "+targ->QCN+"!",({ETO,targ}));
      			targ->do_damage("torso",random(5)+3);
      return 1;
   	}
   	if(!random(16)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Your jet scythe slices "+
			"through "+targ->QCN+" as though "+targ->QS+" "+
			"were butter.");
      	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s jet scythe"+
      		" slices through your skin so easily it takes a "+
			"moment to register"+
      		" the pain.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
      		" jet scythe slices through "+targ->QCN+" as though"+
      		" "+targ->QS+" were cutting butter.",({ETO,targ}));
      			ETO->execute_attack();
      	return 1;
   	}
	if(!random(24)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Dark flames coat the blade of"+
			" your scythe as you mutilate "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^BLACK%^Dark flames coat the blade"+
			" of "+ETO->QCN+"'s jet scythe, burning your flesh as"+
			" "+ETO->QS+" slices through you.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Dark flames coat"+
			" the blade of "+ETO->QCN+"'s jet scythe as "+ETO->QS+" "+
			"slices open "+targ->QCN+".",({ETO,targ}));
      			targ->do_damage("torso",random(10)+5);
                        targ->set_paralyzed(random(4)+2,"The flames chill you to your soul!");

      	return 1;
   	}

}

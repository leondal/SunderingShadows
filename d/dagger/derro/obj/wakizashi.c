//Updated - Nom's Description - Cythera 8/05
#include <std.h>
inherit "/d/common/obj/weapon/wakizashi.c";

void create(){
  	::create();
  	set_id(({"wakizashi","sword","steel sword","wakizashi of the silent death"}));
  	set_name("wakizashi");
  	set_short("%^BOLD%^%^BLACK%^Wakizashi of the S%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^t%^BOLD%^%^BLACK%^ D%^RED%^e%^BOLD%^%^BLACK%^a%^RED%^t%^BOLD%^%^BLACK%^h%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A short slender blackened wakizashi%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This exquisitely crafted wakizashi sword"+
		" has a twenty inch long blackened %^RESET%^mithril%^BOLD%^%^BLACK%^"+
		" leaf blade of slender curves and %^RED%^hollow-ground edges"+
		"%^BOLD%^%^BLACK%^ and a deep fuller which follows the contours"+
		" of the blade. Strips of %^RESET%^%^RED%^blood red%^BOLD%^%^BLACK%^"+
		" leather intertwine from above the hilt and around the fuller."+
		" The hilt components are made of d%^BOLD%^ar%^BLACK%^ke%^ORANGE%^ne"+
		"%^BLACK%^d b%^ORANGE%^ron%^BLACK%^ze%^RESET%^%^ORANGE%^ - the "+
		"cross-piece has both ends %^RED%^inl%^BOLD%^ai%^RESET%^%^RED%^d"+
		" with small r%^BOLD%^ou%^RESET%^%^RED%^nd-cut rub%^BOLD%^i%^RESET%^"+
		"%^RED%^es %^BOLD%^%^BLACK%^and the grip is of black ebony.%^RESET%^");
	set_lore("The Wakizashi of the Silent Death is rumored to have come from an "+
		"ancient group of assassins that once hailed from the distant land"+
		" known as Danger.  These assassins worked in ways that people had"+
		" never seen before, striking from the darkness with deadly silent"+
		" blows.  The black cloaked assassins were feared even by other "+
		"assassins in the lands for their ability to blend into any enviornment"+
		", no one knew when one would leap out and kill them.  Their short "+
		"blades were able to slice through even the strongest steel, leaving"+
		" a target defenseless to their quick and deadly attacks.");
	set_property("lore",15);
	set_value(1000);
     	set_property("enchantment",(random(2))+2);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));

}

int wield_func(string str) {
     	tell_object(ETO,"%^BOLD%^%^BLACK%^The wakizashi feels balanced and "+
		"light in your hands.%^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" gets a cold"+
		" and deadly look in "+ETO->QP+" eyes.%^RESET%^",ETO);
     	return 1;
}

int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the wakizashi into your "+
		"sheath, waiting for the next time that you can kill again.%^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" slips the"+
		" wazikashi into "+ETO->QP+" sheath with a soft smirk on "+ETO->QP+" "+
		"lips.%^RESET%^",ETO);
     	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   	
	if(!random(8)) {
  		tell_object(ETO,"%^RED%^You sidestep "+victim->QCN+", slicing "+
			"into "+victim->QO+" with a ruthless blow.%^RESET%^");
      	tell_object(victim,"%^RED%^"+ETO->QCN+" sidesteps your attack "+
			"and slices into you with a ruthless blow.%^RESET%^");
      	tell_room(EETO,"%^RED%^"+ETO->QCN+" sidesteps"+
			" "+victim->QCN+"'s attack, slicing into "+victim->QO+" "+
			"with a ruthless blow.%^RESET%^",({ETO,victim}));
       			victim->do_damage("torso",random(4)+2);
		return 1;	
	}
	if(!random(16)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^You spring over "+victim->QCN+"'s"+
			" head with a mightly leap and slash the wakizashi into"+
			" "+victim->QP+" back for a ruthless blow.%^RESET%^");
      	tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" springs over"+
			" your head with a mighty leap and deals a ruthless blow "+
			"to your back!%^RESET%^");
      	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" springs over"+
			" "+victim->QCN+"'s head with a mighty leap and deals"+
			" a ruthless blow to "+victim->QP+" back!%^RESET%^",({ETO,victim}));
				victim->do_damage("torso",random(6)+4);
      	return 1;
	}
	if(!random(36)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^Blood sprays out of "+victim->QCN+" "+
			"as your merciless blow slices open an artery.%^RESET%^");
      	tell_object(victim,"%^BOLD%^%^RED%^Your blood sprays into the air"+
			" as "+ETO->QCN+" slices open an artery with a merciless blow!%^RESET%^");
      	tell_room(EETO,"%^BOLD%^%^RED%^"+victim->QCN+"'s blood "+
			"sprays into the air as "+ETO->QCN+" slices open an artery with"+
			" a merciless blow.%^RESET%^",({ETO,victim}));
				victim->do_damage("torso",random(10)+6);
      	return 1;
	}
}
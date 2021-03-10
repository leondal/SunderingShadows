#include <std.h>
inherit "/d/common/obj/weapon/partisan.c";

void create(){
	::create();
	set_name("serpent pike");
	set_id(({ "polearm", "pike", "serpent pike", "spear" }));
	set_short("%^BLUE%^S%^BOLD%^%^CYAN%^e%^RESET%^%^BLUE%^r"+
		"%^BOLD%^%^CYAN%^p%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^"+
		"n%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^'%^RESET%^%^BLUE%^"+
		"s %^BOLD%^%^WHITE%^Tooth Pike%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^An ivory speared pike%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^A long slender iv%^YELLOW%^o%^WHITE%^ry"+
		" tooth has been set into a steel shaft.  The foot long tooth"+
		" is razor sharp and tapers to a fine point.  The steel shaft"+
		" is textured with silver and has an oval weight at the base,"+
		" for balance.  An image of a large %^CYAN%^serpent%^WHITE%^ "+
		"coiled about the shaft has been created out of silver.  The "+
		"textures scales of the serpent help to create firm hand grips,"+
		" while the serpents tail coils about the weight.  The head of "+
		"the serpent is carved with its mouth open, the iv%^YELLOW%^o"+
		"%^WHITE%^ry tooth set inside its jaws. %^BLUE%^ Sapphire%^WHITE%^"+
		" gems are set into the serpents eyes, giving it a life like "+
		"appearance.");
	set_value(5000);
        set_lore("%^BOLD%^%^CYAN%^The Serpent's Tooth Pike is crafted by "+
		"the highly skilled craftsman Tendamas of Antioch.  It is "+
		"rumored that a tooth taken from the Immortal Serpent, Svrrl"+
		" is used in the construction of this polearm.  No telling "+
		"what powers such a pike would posses if made from a creature"+
		" like Svrrl, the serpent from another plane who finds renewed"+
		" strength each night!");
	set_property("lore",13);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" grips the "+
		"shaft of "+ETO->QP+" pike.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The pike feels cool to the "+
		"touch as your grip it.");
			set_property("magic",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" hesitates "+
		"for a moment before releasing "+ETO->QP+" pike.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You release your grip from the pike"+
		", missing the feel of it in your hands already.");
			set_property("magic",-1);
	return 1;
}
int hit_func(object targ)
{
		if(!objectp(TO)) return 1;
		if(!objectp(ETO)) return 1;
		if(!objectp(targ)) return 1;
		if(random(1000) < 200)
		{
			switch(random(30))
			{
					default:
					tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" snakes out with"+
					" a lighting speed to strike beneath "+targ->QCN+"'s guard with"+
					" "+ETO->QP+" pike.",({ETO,targ}));
					tell_object(ETO,"%^BOLD%^%^CYAN%^The pike snakes out with lighting "+
					"speed to strike beneath "+targ->QCN+"'s guard");
					tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" snakes out with a lighting"+
					" speed to strike beneath your guard, with "+ETO->QP+" pike.");
					targ->do_damage("torso",random(6)+2);
					break;
					case 24..29:
        tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+"'s pike begins to"+
				" glow as "+ETO->QS+" tears into "+targ->QCN+".",({ETO,targ}));
				tell_object(ETO,"%^BOLD%^%^BLUE%^The sapphire eyes of the pike begin to"+
				" glow as you tear into "+targ->QCN+"'s guard");
				tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" snakes out with a lighting"+
				" speed to strike beneath your guard, with "+ETO->QP+" pike.");
				targ->do_damage("torso",random(10)+4);
				break;
			}
    }
		return 1;
	}

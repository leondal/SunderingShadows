//Added lore and inherit rapier - Cythera 4/04\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/light_rapier.c";

void create()
{
	::create();
	set_name("moonstone rapier");
	set_id(({"sword","sprite sword","rapier","moonstone rapier"}));
	set_obvious_short("%^BOLD%^%^CYAN%^A moonstone rapier%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Moonstone Rapier%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This slender blade is fashioned out of "+
		"one solid piece of moonstone, which tapers to a sharp point."+
		"  The white gold pommel of the blade has been carved into a"+
		" lifelike image of a curvasious nymph.  %^RED%^Red %^WHITE%^"+
		"rubies are inlaid for her lips, creating a seductive smirk. "+
		"Sparkling %^GREEN%^emeralds%^WHITE%^ are used for her "+
		"captivating eyes.  Her %^YELLOW%^golden%^WHITE%^ hair shines"+
		" in the light, only then do you realize that its been carved"+
		" out of yellow sapphire.  Such a pommel on this blade only adds"+
		" to the beauty of this tiny rapier.");
	set_lore("The Moonstone Rapier is a favorite weapon of the mischievous"+
		" male sprites.  Of all the faeries the sprites are well known "+
		"for their trickster nature, and their rather bawdy sense of "+
		"humor.  It's ever male sprites' dream one day to be able to "+
		"wield a Moonstone Blade, if alone due to the buxom image of "+
		"the nymph on the pommel.  A sprite typically names his blade "+
		"and keeps it close at all times, much to the dismay of many "+
		"female sprites.  Strangely enough, the elite few male sprites"+
		" that make it into prestigious order of the Moonstone Blade "+
		"are all single.");
	set_property("lore",13);
	//set_size(1);
	//set_type("slashing");
	//set_weight(2);
	//set_wc(1,6);
	//set_large_wc(1,4);
	set_property("enchantment",2);
	//set_prof_type("tiny longsword");
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
	set_value(2500);
	set_cointype("electrum");
}

int wieldme()
{
        if(ETO->query_level() < 10) {
		tell_object(ETO,"You are not skilled enough to use such"+
		" a fine sword.");
		return 0;
	}
	else {
		tell_object(ETO,"%^BOLD%^%^GREEN%^This moonstone"+
		" rapier feels comfortable in your hand.");
		tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
		" slices "+ETO->QP+" rapier"+
		" through the air a few times.",ETO);
		return 1;
	}
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^GREEN%^You return the"+
	" rapier to its scabbard.");
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
	" returns "+ETO->QP+" rapier to"+
	" its scabbard.",ETO);
	return 1;
}

int hitme(object targ)
{
	int align;

	if(!objectp(targ)) return 1;

	align = ETO->query_alignment();

	
	if(!random(10)) {
		tell_object(ETO,"%^BOLD%^You adeptly swing your"+
		" rapier at "+targ->QCN+", scoring"+
		" a solid hit!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
		" swings "+ETO->QP+" rapier skillfully,"+
		" landing a solid blow on "+targ->QCN+".",({ETO,targ}));
		tell_object(targ,"%^BOLD%^"+ETO->QCN+""+
		" swings "+ETO->QP+" rapier in a skillful"+
		" arc, landing a solid blow on you.");
		targ->do_damage("torso",random(6)+1);
		return 1;
	}
	if(!random(20)) {
		tell_object(ETO,"%^BOLD%^%^GREEN%^A verdant green aura "+
			"surrounds the moonstone blade of the rapier, just"+
			" moments before you pierce the blade into "+
			""+targ->QCN+"!");
		tell_room(environment(ETO),"%^BOLD%^%^GREEN%^A verdant green"+
		" aura flares to life around "+ETO->QCN+"'s rapier,"+
		" moments before "+ETO->QCN+" pierces "+targ->QCN+".",({ETO,targ}));
		tell_object(targ,"%^BOLD%^%^GREEN%^A verdant green aura"+
			" surrounds "+ETO->QCN+"'s rapier just moments before"+
			" "+ETO->QS+" pierces into your flesh!");
		targ->do_damage(random(5)+5);
		return 1;
	}
	if(!random(30)) {
		switch(align) {
			case 1: case 4: case 7:
				tell_object(ETO,"%^BOLD%^%^YELLOW%^The nymph shaped pommel seems"+
				" to warm slightly in your hands and a tingle"+
				" spreads throughout your body.");
				tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+"'s"+
				" rapier begins to glow a golden color, the light"+
				" spreads over "+ETO->query_possessive()+" body"+
				" and "+ETO->query_subjective()+" seems refreshed.",ETO);
				ETO->do_damage("torso",-(random(7)+5));
				return 1;
			
			default: 
				return 1;
			
		}
	}
}

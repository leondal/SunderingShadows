#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

void create() 
{
    	::create();
	set_name("midnights edge");
	set_id(({"scimitar", "edge", "midnights edge", 
	"midnights scimitar", "weapon"}));
	
	set_obvious_short("%^BOLD%^%^BLACK%^A gleaming black "+
	"scimitar%^RESET%^");
			
	set_short("%^BOLD%^%^BLACK%^M%^BOLD%^%^WHITE%^i%^BOLD%^"+
	"%^BLACK%^d%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^i%^BOLD%^"+
	"%^WHITE%^g%^BOLD%^%^BLACK%^h%^BOLD%^%^WHITE%^t%^BOLD%^"+
	"%^BLACK%^'%^BOLD%^%^WHITE%^s %^BOLD%^%^BLACK%^E%^BOLD%^"+
	"%^WHITE%^d%^BOLD%^%^BLACK%^g%^BOLD%^%^WHITE%^e%^RESET%^");

	set_long("%^BOLD%^%^WHITE%^This magnificent scimitar "+
	"is forged from a gl%^BOLD%^%^CYAN%^ea%^BOLD%^%^WHITE%^"+
	"ming %^BOLD%^%^BLACK%^black metal%^BOLD%^%^WHITE%^.  The "+
	"%^BOLD%^%^BLACK%^b%^BOLD%^%^WHITE%^"+
	"l%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^d%^BOLD%^"+
	"%^BLACK%^e %^BOLD%^%^WHITE%^has a very pronounced curve.  "+
	"The letters '%^BOLD%^%^YELLOW%^V%^BOLD%^%^WHITE%^"+
	"a%^BOLD%^%^YELLOW%^r%^BOLD%^%^WHITE%^d%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^WHITE%^' have been engraved down its length.  "+
	"The %^BOLD%^%^BLACK%^e%^BOLD%^"+
	"%^WHITE%^d%^BOLD%^%^BLACK%^g%^BOLD%^%^WHITE%^e "+
	"of the blade is %^BOLD%^%^RED%^razor sharp%^BOLD%^"+
	"%^WHITE%^ and %^BOLD%^%^BLACK%^d%^BOLD%^"+
	"%^WHITE%^u%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^"+
	"k%^BOLD%^%^BLACK%^ dark%^BOLD%^%^WHITE%^, much "+
	"darker than the rest of it.  The hilt of it is "+
	"made from what appears to be %^RESET%^%^WHITE%^"+
	"bone%^BOLD%^%^WHITE%^, with a grip at the bottom "+
	"contoured perfectly to fit in the hand.  Resting "+
	"directly beneath the grip is a large fl%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^WHITE%^wl%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^"+
	"ss %^BOLD%^%^RED%^ruby%^BOLD%^%^WHITE%^ serving "+
	"as the pommel.%^RESET%^");

 	set_value(3000);
	set_property("lore difficulty", 40);

	set_lore("%^BOLD%^%^BLUE%^Legends suggest that this "+
	"scimitar was once wielded by an assassin known "+
	"only as '%^BOLD%^%^WHITE%^Midnight%^BOLD%^%^BLUE%^'.  "+
	"It is said that the blade was imbued with the "+
	"power to, on occassion, pierce all magical "+
	"protections and "+
	"that it would sometimes even transfer "+
	"life from the target into the wielder.  "+
	"No one is for sure what happened to the "+
	"infamous assassin, they simply vanished.%^RESET%^");

  	set_property("enchantment",5);

    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
    	set_hit((:TO,"special":));
	set_item_bonus("attack bonus", 2);
	set_item_bonus("damage bonus", 2);
}

int wield_me()
{
	if(ETO->query_highest_level() < 30) 
	{
		tell_object(ETO, "%^BOLD%^%^WHITE%^The "+
		"scimitar will not be controlled by someone "+
		"as weak as you are.%^RESET%^");
		return 1;
	}
	tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a "+
	"power settle over you, increasing your "+
	"accuracy and strength in combat.%^RESET%^");
	return 1;
}

int unwield_me()
{
	tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the "+
	"power granted to you by the scimitar fade away!%^RESET%^");
	return 1;
}

int special(object targ) 
{
	string tlim;
	int dam;
	if(!objectp(ETO)) return 0;
	if(!objectp(EETO)) return 0;
	if(!objectp(targ)) return 0;
	if(random(100) < 75) return 0;
	tlim = targ->return_target_limb();
	switch(random(20)) 
	{
		case 0..15:

			tell_object(ETO, "%^BOLD%^%^CYAN%^The ruby pommel "+
			"of your scimitar fl%^BOLD%^%^RED%^ash%^BOLD%^%^CYAN%^"+
			"es briefly as its blade slashes "+targ->QCN+
			"%^BOLD%^%^CYAN%^'s "+tlim+"!%^RESET%^");
			
			tell_object(targ, "%^BOLD%^%^CYAN%^The ruby pommel "+
			"of "+ETOQCN+"%^BOLD%^%^CYAN%^'s scimitar fl%^BOLD%^"+
			"%^RED%^ash%^BOLD%^%^CYAN%^es briefly as "+
			"its blade slashes your "+tlim+"!%^RESET%^");	
				
			tell_room(EETO, "%^BOLD%^%^CYAN%^The ruby pommel "+
			"of "+ETOQCN+"%^BOLD%^%^CYAN%^'s scimitar fl"+
			"%^BOLD%^%^RED%^ash%^BOLD%^%^CYAN%^es briefly as "+
			"its blade slashes "+targ->QCN+"%^BOLD%^%^CYAN%^'s "+
			tlim+"!%^RESET%^", ({targ, ETO}));

			ETO->set_property("magic", 1);
			targ->cause_typed_damage(targ, tlim, roll_dice(5, 4), "slashing");
			ETO->set_property("magic", -1);
			return 0;
			break;

		case 16..19:

			tell_object(ETO, "%^BOLD%^%^BLACK%^Your scimitar "+
			"%^BOLD%^%^CYAN%^leeches%^BOLD%^%^BLACK%^ "+
			"some of "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
			"lifeforce and strengthens your own!%^RESET%^");
			
			tell_object(targ, "%^BOLD%^%^BLACK%^The scimitar "+
			"wielded by "+ETOQCN+"%^BOLD%^%^BLACK%^ "+
			"%^BOLD%^%^CYAN%^leeches%^BOLD%^%^BLACK%^ away "+
			"part of your lifeforce as it slashes into your "+
			tlim+"!%^RESET%^");

			tell_room(EETO, "%^BOLD%^%^BLACK%^The scimitar "+
			"wielded by "+ETOQCN+"%^BOLD%^%^BLACK%^ "+
			"slashes into "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
			tlim+"!%^RESET%^", ({targ, ETO}));
			ETO->set_property("magic", 1);
			dam = roll_dice(5, 4);
			targ->cause_typed_damage(targ, tlim, dam, "slashing");
			ETO->add_hp(dam);
			ETO->set_property("magic", -1);
			return 0;
			break;
	}		
	return 0;	
}

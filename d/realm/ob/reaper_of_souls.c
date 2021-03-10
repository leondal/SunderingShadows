#include <std.h>
inherit "/d/common/obj/weapon/scythe.c";
int souls, time_to_absorb;

void create() 
{
    	::create();
	set_name("reaper of souls");
	set_id(({"reaper", "scythe", "reaper of souls", 
	"soul scythe"}));
	
	set_obvious_short("%^BOLD%^%^MAGENTA%^A serrated "+
	"scythe%^RESET%^");
			
	set_short("%^BOLD%^%^MAGENTA%^R%^BOLD%^%^BLACK%^"+
	"e%^BOLD%^%^MAGENTA%^a%^BOLD%^%^BLACK%^p%^BOLD%^"+
	"%^MAGENTA%^e%^BOLD%^%^BLACK%^r %^BOLD%^%^MAGENTA%^"+
	"of %^BOLD%^%^BLACK%^S%^BOLD%^%^MAGENTA%^o%^BOLD%^"+
	"%^BLACK%^u%^BOLD%^%^MAGENTA%^l%^BOLD%^%^BLACK%^"+
	"s%^RESET%^");
	souls = 0;
	time_to_absorb = 0;
	set_long((:TO, "mylong":));

 	set_value(3000);
	set_property("lore difficulty", 40);

	set_lore("%^BOLD%^%^MAGENTA%^This scythe was one "+
	"of many created by Ao'rus Devar during his "+
	"earliest stages of unlife.  It is believed that "+
	"because of his fascination with death he imbued "+
	"it with a magic that would absorb energy from "+
	"the deceased and later release it in a perverse "+
	"manner.  Some legends say it was actually "+
	"originally enchanted with the souls of "+
	"many innocents and once 'fed' it will "+
	"use that energy to once again animate and "+
	"torment them.%^RESET%^");

  	set_property("enchantment",5);

    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
    	set_hit((:TO,"special":));
}

void heart_beat()
{
	object cor;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(EETO)) return;
	if(!query_wielded()) return;
	if(souls >= 20)
	{
		souls = 20;
		return;
	}
	if(time_to_absorb > 0)
	{
		time_to_absorb--;
		return;
	}
	if(!objectp(cor = present("corpse", EETO))) return;
	time_to_absorb = 30;
	tell_object(ETO, "%^BOLD%^%^BLACK%^Sensing death, "+
	"the robed figure on your scythe sucks away all "+
	"the remaining energy from the corpse at your "+
	"feet!%^RESET%^");
	tell_room(EETO, "%^BOLD%^%^BLACK%^Sensing death, "+
	"the robed figure on the scythe wielded by "+ETOQCN+
	"%^BOLD%^%^BLACK%^ sucks away all the remaining "+
	"energy from the corpse!%^RESET%^", ETO);
	while(objectp(cor)) 
	{
		cor->decay();
		souls++;
		continue;
	}
	return;
}
	

string mylong()
{
	string desc;
	desc = "%^BOLD%^%^MAGENTA%^The handle of this "+
	"%^BOLD%^%^RED%^vicious%^BOLD%^%^MAGENTA%^ looking scythe "+
	"is more than three feet in length and made "+
	"from an ancient %^BOLD%^%^BLACK%^ashen wood"+
	"%^BOLD%^%^MAGENTA%^ that has been engraved with "+
	"a %^BOLD%^%^BLACK%^dark robed figure%^BOLD%^"+
	"%^MAGENTA%^ with very intense %^BOLD%^%^RED%^"+
	"blood red eyes%^BOLD%^%^MAGENTA%^.  "+
	"There is a %^BOLD%^%^YELLOW%^thick leather"+
	"%^BOLD%^%^MAGENTA%^ grimy wrap near the "+
	"bottom of it, a desperate attempt for a grip.  "+
	"%^BOLD%^%^MAGENTA%^The blade is very %^BOLD%^%^RED%^"+
	"serrated%^BOLD%^%^MAGENTA%^ and ";

	switch(souls)
	{
		case 0:
			desc += "%^BOLD%^%^MAGENTA%^very dull, "+
			"somehow managing to absorb any "+
			"%^BOLD%^%^YELLOW%^light "+
			"%^BOLD%^%^MAGENTA%^directed%^BOLD%^%^MAGENTA%^ "+
			"at it.%^RESET%^";
			break;
		case 1..10:
			desc += "%^BOLD%^%^MAGENTA%^glowing "+
			"with an eerie %^BOLD%^%^RED%^red "+
			"aura%^BOLD%^%^MAGENTA%^, you believe "+
			"you can see phantom faces in it "+
			"briefly, as if screaming for help, before "+
			"they fall back into its depths.%^RESET%^";
			break;
		case 11..15:
			desc += "%^BOLD%^%^MAGENTA%^glowing "+
			"with a %^RESET%^%^RED%^dark red"+
			"aura%^BOLD%^%^MAGENTA%^.  Phantom faces "+
			"appear it in suddenly and scream silently "+
			"for help, before being dragged back into "+
			"its depths by a disembodied %^BOLD%^"+
			"%^WHITE%^skeletal%^BOLD%^%^MAGENTA%^ "+
			"hands.%^RESET%^";
			break;
		case 16..20:
			desc += "%^BOLD%^%^MAGENTA%^glowing "+
			"brightly with an %^BOLD%^%^RED%^evil "+
			"crimson%^BOLD%^%^MAGENTA%^ aura.  "+
			"Phantom faces appear along the length of it "+
			"screaming in silent agony for help!%^RESET%^";
			break;
	}
	return desc;
}


int wield_me()
{
	if(ETO->query_highest_level() < 30) 
	{
		tell_object(ETO, "%^BOLD%^%^BLACK%^The "+
		"scythe will never yield to someone "+
		"as weak as you are.%^RESET%^");
		return 1;
	}
	set_heart_beat(1);
	tell_object(ETO, "%^BOLD%^%^BLACK%^You sense an "+
	"unknown being watching you closely as you take "+
	"hold of the scythe.%^RESET%^");
	return 1;
}

int unwield_me()
{
	tell_object(ETO, "%^BOLD%^%^BLACK%^You sense the "+
	"gaze of the being depart from you as you release "+
	"the scythe.%^RESET%^");
	return 1;
}

int special(object targ) 
{
	string tlim, targname, attname;
	int dam;
	if(!objectp(ETO)) return 0;
	if(!objectp(EETO)) return 0;
	if(!objectp(targ)) return 0;
	if(random(100) < 75) return 0;
	if(souls <= 0) return 0;
	tlim = targ->return_target_limb();
	targname = targ->QCN;
	attname = ETO->QCN;
	if(souls < 20) 
	{
		tell_object(ETO, "%^BOLD%^%^RED%^Screams of "+
		"immeasurable %^BOLD%^%^BLACK%^ANGER%^BOLD%^"+
		"%^RED%^ erupt from the blade of your scythe "+
		"as it sinks into "+ targname +
		"%^BOLD%^%^RED%^!%^RESET%^");
		
		tell_object(targ, "%^BOLD%^%^RED%^Screams of "+
		"immeasurable %^BOLD%^%^BLACK%^ANGER%^BOLD%^"+
		"%^RED%^ are suddenly directed at you from "+
		"the blade of "+ attname +"%^BOLD%^%^RED%^'s "+
		"scythe as it sinks into your flesh!%^RESET%^");

		tell_room(EETO, "%^BOLD%^%^RED%^Screams of "+
		"immeasurable %^BOLD%^%^BLACK%^ANGER%^BOLD%^"+
		"%^RED%^ suddenly erupt from the blade of "+
		attname +"%^BOLD%^%^BED%^'s scythe as it "+
		"sinks into "+ targname +"%^BOLD%^%^RED%^'s "+
		"flesh!%^RESET%^", ({targ, ETO}));
		
		return roll_dice(3, 5);
	}
	if(souls >= 20)
	{
		tell_object(ETO, "%^BOLD%^%^BLACK%^A wave of "+
		"pure energy shoots from the blade of your "+
		"scythe as it sinks into "+ targname +
		"%^BOLD%^%^BLACK%^'s flesh and "+
		"slams into "+targ->QO+"%^BOLD%^"+
		"%^BLACK%^!%^RESET%^");

		tell_object(targ, "%^BOLD%^%^BLACK%^A wave of "+
		"pure energy is released from the blade of "+
		attname +"%^BOLD%^%^BLACK%^'s scythe as it "+
		"sinks into your flesh and slams into you!%^RESET%^");

		tell_room(EETO, "%^BOLD%^%^BLACK%^A wave of "+
		"pure energy is released from the blade of "+
		attname +"%^BOLD%^%^BLACK%^'s scythe as it "+
		"sinks into "+ targname +"%^BOLD%^BLACK%^'s "+
		"flesh and slams into "+targ->QO+"!%^RESET%^", 
		({targ, ETO}));
		souls = 0;
		ETO->set_property("magic", 1);
		targ->cause_typed_damage(targ, tlim, roll_dice(20, 5), "negative energy");
		ETO->set_property("magic", -1);
		return 0;	
	}
}

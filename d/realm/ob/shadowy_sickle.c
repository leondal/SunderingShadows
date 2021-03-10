#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/weapon/sickle.c";

int bolt_pos;
object orb;

void create() 
{
    	::create();
	set_obvious_short("%^BOLD%^%^BLUE%^A %^BOLD%^%^RED%^dark metallic%^BOLD%^%^BLUE%^ "+
	"sickle%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^A%^BOLD%^%^YELLOW%^o'ru%^BOLD%^%^BLACK%^"+
	"s %^BOLD%^%^YELLOW%^De%^BOLD%^%^BLACK%^va%^BOLD%^%^YELLOW%^"+
	"r's %^BOLD%^%^BLACK%^Night Reaper%^RESET%^");
	bolt_pos = 0;		
	set_long((:TO, "mylong":));
	set_property("enchantment",5);
    	set_value(2000);
    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
	set_property("damage bonus", 2);
    	set_hit((:TO,"special":));
	set_lore("%^BOLD%^%^GREEN%^This strange sickle is "+
	"the later in the pair crafted and enchanted by the "+
	"age forgotten sorcerer "+
	"Ao'rus Devar - some legends suggest that this one "+
	"was crafted after his mortal mind began "+
	"collapsing.  Either way - this is the second "+
	"such weapon that he once wielded, before time lost "+
	"most of its meaning to him and he cast aside his "+
	"weapons, eventually crafting a few more of "+
	"these for his servants.%^RESET%^"); 
	set_property("lore difficulty", 40);
}

string mylong()
{
	string desc;
	

	desc = "%^BOLD%^%^RED%^This small weapon has been crafted from a piece "+
	"of %^BOLD%^%^BLACK%^dark metal%^BOLD%^%^RED%^ that is giving "+
	"off a soft, constant %^BOLD%^%^YELLOW%^hum"+
	"%^BOLD%^%^RED%^.  The handle of it is wrapped with a "+
	"%^RESET%^%^YELLOW%^thick leather%^BOLD%^%^RED%^ "+
	"that shows obvious signs of frequent use.  "+
	"The blade is the apparent result of a "+
	"%^BOLD%^%^MAGENTA%^meticulous%^BOLD%^%^RED%^ "+
	"craftsman as it is absolutely "+
	"fl%^RESET%^%^BLUE%^a%^BOLD%^%^RED%^"+
	"wls%^RESET%^%^BLUE%^e%^BOLD%^%^RED%^"+
	"ss in design.  It is slightly wider "+
	"than you would expect and curves dramatically "+
	"back toward the handle.  At the base of "+
	"the blade someone has engraved, in stark "+
	"contract, the image of a %^BOLD%^%^WHITE%^skeletal "+
	"sorcerer%^BOLD%^%^RED%^.";

	if(!objectp(orb) && bolt_pos == -1) bolt_pos = 0;

	if(bolt_pos == 0)
	{
		desc += "%^BOLD%^%^RED%^  A %^BOLD%^%^WHITE%^"+
		"brilliant orb%^BOLD%^%^RED%^ is depicted right "+
		"above the outstretched hands of the "+
		"%^BOLD%^%^WHITE%^skeletal sorcerer"+
		"%^BOLD%^%^RED%^.";
	}
	if(bolt_pos == 1)
	{
		desc += "%^BOLD%^%^RED%^  A %^BOLD%^%^WHITE%^"+
		"brilliant orb%^BOLD%^%^RED%^ is depicted about "+
		"halfway up the blade, moving away from the "+
		"outstretched hands of the "+
		"%^BOLD%^%^WHITE%^skeletal sorcerer"+
		"%^BOLD%^%^RED%^.";
	}
	if(bolt_pos == 2) 
	{
		desc += "%^BOLD%^%^RED%^  A %^BOLD%^%^WHITE%^"+
		"brilliant orb%^BOLD%^%^RED%^ is depicted almost "+
		"at the tip of the blade as if it has been thrown "+
		"by the outstretched hands of the "+
		"%^BOLD%^%^WHITE%^skeletal sorcerer"+
		"%^BOLD%^%^RED%^.";
	}
	if(bolt_pos == 3)
	{
		desc += "%^BOLD%^%^RED%^  A %^BOLD%^%^WHITE%^"+
		"brilliant orb%^BOLD%^%^RED%^ is depicted on "+
		"the very tip of the blade as if thrown with "+
		"force from the outstretched hands of the "+
		"%^BOLD%^%^WHITE%^skeletal sorcerer"+
		"%^BOLD%^%^RED%^.";
	}
	return desc + "%^RESET%^";
}
	 


int wield_me() 
{
    	tell_object(ETO,"%^BOLD%^%^RED%^You take hold of "+
	"the sickle and feel a strange force "+
	"pulsate out from it.%^RESET%^");
    	return 1;
}

int unwield_me() 
{
    	tell_object(ETO, "%^BOLD%^%^RED%^You release the sickle "+
	"and feel the force pulsating from it cease.%^RESET%^");
    	return 1;
}

void set_bolt_pos(int x)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(x < -1 || x > 4)
	{
		bolt_pos = 0;
	}
	bolt_pos = x;
}

int special(object targ) 
{
	string targname, attname, attpos;
    int chance, dam = roll_dice(2, 6);
	if(!objectp(targ)) return 0;
    	chance = random(8);
	if(bolt_pos == -1) return 0;
	targname = targ->QCN;
	attname = ETO->QCN;
	attpos = ETO->QP;
    	if(!chance) 
	{
		switch(bolt_pos)
		{
			case 0: case 1: case 2:
				tell_object(ETO, "%^BOLD%^%^RED%^You sink your "+
				"sickle into "+ targname + "%^BOLD%^%^RED%^'s "+
				"flesh and the %^BOLD%^%^WHITE%^orb%^BOLD%^%^RED%^ "+
				"creeps up the blade, as if propelled forward by "+
				"the engraved %^BOLD%^%^WHITE%^"+
				"skeletal sorcerer%^BOLD%^%^RED%^!.%^RESET%^");
		
				tell_room(EETO, attname + "%^BOLD%^%^RED%^ sinks "+
				attpos +" sickle deep into "+
				targname +"%^BOLD%^%^RED%^'s flesh!%^RESET%^", ({ETO, targ}));
				
				tell_object(targ, attname +"%^BOLD%^%^RED%^ sinks "+
				attpos +" sickle deep into your flesh!");
				bolt_pos++;
				targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "slashing");
				break;
			case 3:
				tell_object(ETO, "%^BOLD%^%^RED%^As you sink your "+
				"sickle into "+ targname +"%^BOLD%^%^RED%^'s "+
				"flesh a %^BOLD%^%^WHITE%^brilliant orb"+
				"%^BOLD%^%^RED%^ shoots out from the tip of "+
				"its blade and settles in midair "+
				"- %^BOLD%^%^WHITE%^PULSATING RAPIDLY"+
				"%^BOLD%^%^RED%^!%^RESET%^");
								
				tell_room(EETO, "%^BOLD%^%^RED%^As "+ attname +
				"%^BOLD%^%^RED%^ sinks "+ attpos +
				" sickle into "+ targname +
				"%^BOLD%^%^RED%^'s flesh a "+
				"%^BOLD%^%^WHITE%^brillian orb "+
				"%^BOLD%^%^RED%^shoots out from "+
				"the tip of its blade and settles "+
				"in midair - %^BOLD%^%^WHITE%^"+
				"PULSATING RAPIDLY%^BOLD%^%^RED%^"+
				"!", ({targ, ETO}));
			
				tell_object(targ, "%^BOLD%^%^RED%^As "+ attname +
				"%^BOLD%^%^RED%^ sinks "+ attpos + " sickle "+
				"into your flesh a %^BOLD%^%^WHITE%^"+
				"brilliant orb%^BOLD%^%^RED%^ shoots out from "+
				"the tip of its blade and settles "+
				"in midair - %^BOLD%^%^WHITE%^PULSATING "+
				"RAPIDLY%^BOLD%^%^RED%^!%^RESET%^");
	
				bolt_pos = -1;	
				orb = new(RA_OB+"sickle_ob");
				orb->set_which_type(2);
				orb->set_wpn(TO);
				orb->set_owned(ETO);
				orb->move(EETO);
				orb->start_spinning();
				targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "slashing");
				break;			
		}
    	}
	return 0;		
}


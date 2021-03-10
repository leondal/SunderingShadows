#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/weapon/sickle.c";

int bolt_pos;
object orb;

void create() 
{
    	::create();
	set_obvious_short("%^BOLD%^%^CYAN%^A glowing sickle%^RESET%^");
	set_short("%^BOLD%^%^CYAN%^A%^BOLD%^%^YELLOW%^o'ru%^BOLD%^%^CYAN%^"+
	"s %^BOLD%^%^YELLOW%^De%^BOLD%^%^CYAN%^va%^BOLD%^%^YELLOW%^"+
	"r's %^BOLD%^%^CYAN%^Ethereal Reaper%^RESET%^");
	bolt_pos = 0;		
	set_long((:TO, "mylong":));
	set_property("enchantment",5);
    	set_value(2000);
    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
	set_property("sight bonus", 1);
    	set_hit((:TO,"special":));
  	set_lore("%^BOLD%^%^GREEN%^This strange sickle was "+
	"crafted and enchanted by the age forgotten sorcerer "+
	"Ao'rus Devar - some legends suggest that it was his "+
	"first such weapon and that he treasured it "+
	"eventually creating another similiar weapon "+
	"- which he wielded in pair with this one.  "+
	"However, as he aged and time lost most of its "+
	"meaning he cast aside his weapons and "+
	"eventually crafted more of these for his "+
	"servants.%^RESET%^");
	set_property("lore difficulty", 40);

}

string mylong()
{
	string desc;
	desc = "%^BOLD%^%^BLUE%^This small weapon has been crafted from a piece "+
	"of metal that is constantly giving off a soft ill%^BOLD%^%^YELLOW%^"+
	"umi%^BOLD%^%^BLUE%^nous %^BOLD%^%^CYAN%^glow%^BOLD%^%^BLUE%^.  The handle "+
	"of it is wrapped with a %^RESET%^%^YELLOW%^thick leather"+
	"%^BOLD%^%^BLUE%^ that shows obvious signs of frequent use.  "+
	"The blade is the apparent result of a "+
	"%^BOLD%^%^MAGENTA%^meticulous%^BOLD%^%^BLUE%^ "+
	"craftsman as it is absolutely fl%^RESET%^%^RED%^"+
	"a%^BOLD%^%^BLUE%^wl%^RESET%^%^RED%^e%^BOLD%^%^BLUE%^"+
	"ss in design.  It curves back toward the "+
	"handle ever so slightly and at its base there is the "+
	"image of a %^BOLD%^%^RED%^sorcerer%^BOLD%^%^BLUE%^ "+
	"engraved.";
	if(!objectp(orb) && bolt_pos == -1) bolt_pos = 0;
	if(bolt_pos == 0)
	{
		desc += "%^BOLD%^%^BLUE%^  An %^BOLD%^%^CYAN%^"+
		"orb%^BOLD%^%^BLUE%^ is depicted right "+
		"above the outstretched hands of the "+
		"%^BOLD%^%^RED%^sorcerer%^BOLD%^%^BLUE%^.";
	}
	if(bolt_pos == 1)
	{
		desc += "%^BOLD%^%^BLUE%^  An %^BOLD%^%^CYAN%^"+
		"orb%^BOLD%^%^BLUE%^ is depicted about halfway "+
		"up the blade, moving away from the "+
		"outstretched hands of the %^BOLD%^%^RED%^"+
		"sorcerer%^BOLD%^%^BLUE%^.";
	}
	if(bolt_pos == 2) 
	{
		desc += "%^BOLD%^%^BLUE%^  An %^BOLD%^%^CYAN%^"+
		"orb%^BOLD%^%^BLUE%^ is depicted almost at the "+
		"tip of the blade as if it has been thrown "+
		"by the outstretched hands of the "+
		"%^BOLD%^%^RED%^sorcerer%^BOLD%^%^BLUE%^.";
	}
	if(bolt_pos == 3)
	{
		desc += "%^BOLD%^%^BLUE%^  An %^BOLD%^%^CYAN%^"+
		"orb%^BOLD%^%^BLUE%^ is depicted on the very "+
		"tip of the blade as if thrown with force "+
		"from the outstretched hands of the "+
		"%^BOLD%^%^RED%^sorcerer%^BOLD%^%^BLUE%^.";
	}
	return desc + "%^RESET%^";
}
	 


int wield_me() 
{
    	tell_object(ETO,"%^BOLD%^%^BLUE%^You take hold of "+
	"the sickle and feel a strange force "+
	"pulsate out from it.%^RESET%^");
    	return 1;
}

int unwield_me() 
{
    	tell_object(ETO, "%^BOLD%^%^BLUE%^You release the sickle "+
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
    int chance, dam = roll_dice(2, 6);
	string targname, attname, attpos;
	if(!objectp(targ)) return 0;
    chance = random(8);
	if(bolt_pos == -1) return 0;	
    if(!chance) 
	{
		targname = targ->QCN;
		attname = ETO->QCN;
		attpos = ETO->QP;
		switch(bolt_pos)
		{
			case 0: case 1: case 2:
				tell_object(ETO, "%^BOLD%^%^BLUE%^You slice into "+
				targname + "%^BOLD%^%^BLUE%^'s flesh with your "+
				"sickle and the %^BOLD%^%^CYAN%^orb%^BOLD%^%^BLUE%^ "+
				"creeps up the blade, as if propelled forward by "+
				"the engraved %^RED%^sorcerer%^BOLD%^%^BLUE%^!.%^RESET%^");
		
				tell_room(EETO, attname + "%^BOLD%^%^BLUE%^ slices deep "+
				"into "+ targname +"%^BOLD%^%^BLUE%^ flesh with "+
				attpos +" sickle!%^RESET%^", ({ETO, targ}));
				
				tell_object(targ, attname +"%^BOLD%^%^BLUE%^ slices deep "+
				"into your flesh with "+ attpos +" sickle!%^RESET%^");
				bolt_pos++;
				targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "slashing");
				break;
			case 3:
				tell_object(ETO, "%^BOLD%^%^BLUE%^As you slice "+
				"into "+ targname +"%^BOLD%^%^BLUE%^'s flesh "+
				"with your sickle a %^BOLD%^%^CYAN%^tiny glowing "+
				"orb%^BOLD%^%^BLUE%^ shoots out from the tip of "+
				"its blade and settles "+
				"in midair - %^BOLD%^%^RED%^SPINNING WILDLY"+
				"%^BOLD%^%^BLUE%^!%^RESET%^");
				
				tell_room(EETO, "%^BOLD%^%^BLUE%^As "+ attname +
				"%^BOLD%^%^BLUE%^ slices into "+ targname +
				"%^BOLD%^%^BLUE%^'s flesh with "+ attpos +
				" sickle a %^BOLD%^%^CYAN%^tiny glowing "+
				"orb%^BOLD%^%^BLUE%^ shoots out from the tip "+
				"of its blade and settles in "+
				"midair - %^BOLD%^%^RED%^SPINNING WILDLY"+
				"%^BOLD%^%^BLUE%^!%^RESET%^", ({targ, ETO}));
			
				tell_object(targ, "%^BOLD%^%^BLUE%^As "+ attname +
				"%^BOLD%^%^BLUE%^ slices into your flesh "+
				"with "+ attpos +" sickle a %^BOLD%^%^CYAN%^"+
				"tiny glowing orb%^BOLD%^%^BLUE%^ shoots out from "+
				"the tip of its blade and settles "+
				"in midair - %^BOLD%^%^RED%^SPINNING WILDLY"+
				"%^BOLD%^%^BLUE%^!%^RESET%^");
				bolt_pos = -1;	
				orb = new(RA_OB+"sickle_ob");
				orb->set_which_type(1);
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


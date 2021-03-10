#include <std.h>
inherit "/d/common/obj/weapon/trident.c";

void create() 
{
    	::create();
	set_name("trident of power");
	set_id(({"weapon", "trident", "trident of power"}));
	
	set_obvious_short("%^RED%^A rusted dark red "+
	"trident%^RESET%^");			

	set_short("%^RED%^Trident of %^BOLD%^%^BLUE%^"+
	"P%^BOLD%^%^WHITE%^o%^BOLD%^%^BLUE%^w%^BOLD%^"+
	"%^WHITE%^e%^BOLD%^%^BLUE%^r%^RESET%^");

	set_long("%^RED%^This %^BOLD%^%^BLACK%^ancient"+
	"%^RESET%^%^RED%^ trident has been crafted from "+
	"a sturdy yet light weight dark %^BOLD%^crimson%^RESET%^"+
	"%^RED%^ steel.  It is terribly tarnished with "+
	"ugly spots of rust up and down the length of it.  "+
	"About half of the shaft has been wrapped with "+
	"a %^RESET%^%^GREEN%^green cloth%^RED%^ that "+
	"apparently serves as a makeshift grip for the "+
	"wielder.  The prongs at the top of it are various "+
	"shades of %^BOLD%^red%^RESET%^%^RED%^ and "+
	"each one of them is %^BOLD%^%^BLACK%^viciously "+
	"barbed%^RESET%^%^RED%^.  A lone %^BOLD%^%^GREEN%^"+
	"emerald%^RESET%^%^RED%^ has been inset into the "+
	"shaft, right beneath the prongs, and a %^BOLD%^"+
	"%^GREEN%^light mist%^RESET%^%^RED%^ swirls around "+
	"inside of it, giving it a hazy appearance.%^RESET%^");

	set_weight(3);
 	set_value(3000);
	set_property("lore difficulty", 40);

	set_lore("%^RED%^Created by using the formula of a "+
	"wizard who was known only as 'Bry' - these "+
	"tridents were once given as a gift to royal guards "+
	"in Ao'rus Devars' keep, before he shed his mortal "+
	"shell.  The emerald in them was believed to "+
	"mimic the effect of a gem of power and therefore "+
	"meant to pass that on to the wielder, however "+
	"its magic has long since faded, leaving only "+
	"a small portion behind.  It is unknown what "+
	"happened to the mage who come up with the "+
	"formula, though some legends suggest he "+
	"later become very close to Ao'rus Devar.%^RESET%^");

  	set_property("enchantment",5);
    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
    	set_hit((:TO,"special":));
	set_property("damage bonus", 4);
}

int wield_me()
{
	if(ETO->query_highest_level() < 30) 
	{
		tell_object(ETO, "%^RED%^The "+
		"trident will never obey someone as "+
		"weak as you.%^RESET%^");
		return 1;
	}
	tell_object(ETO, "%^RED%^You feel power from the "+
	"trident engulf you, granting you extra strength in "+
	"combat.%^RESET%^");
	return 1;
}

int unwield_me()
{
	tell_object(ETO, "%^RED%^You feel the power granted "+
	"to you from the trident recede.%^RESET%^");
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
		case 0..17:
			tell_object(ETO, "%^BOLD%^%^RED%^You sink all "+
			"three prongs of your trident into "+targ->QCN+
			"%^BOLD%^%^RED%^ and violently twist, 
			ripping "+targ->QP+"flesh!%^RESET%^");
			
			tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ sinks all "+
			"three prongs of "+ETO->QP+" trident into you "+
			"and twists violently, ripping your flesh!%^RESET%^");

			tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ sinks all "+
			"three prongs of "+ETO->QP+" trident into "+targ->QCN+
			"%^BOLD%^%^RED%^ and twists violently, "+
			"ripping "+targ->QP+" flesh!%^RESET%^", ({targ, ETO}));

			return roll_dice(2, 10);
		case 18..19:
			tell_object(ETO, "%^BOLD%^%^GREEN%^You bring the shaft "+
			"of your trident around and slam it into "+targ->QCN+
			"%^BOLD%^%^GREEN%^'s head, using the moment to "+
			"launch another attack!%^RESET%^");

			tell_object(targ, ETOQCN+"%^BOLD%^%^GREEN%^ brings "+
			"the shaft of "+ETO->QP+" trident around and slams it "+
			"into your head, using the moment to launch "+
			"another attack!%^RESET%^");
	
			tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ brings the "+
			"shaft of "+ETO->QP+" trident around and slams it "+
			"into "+targ->QCN+"%^BOLD%^%^GREEN%^'s head, using "+
			"the moment to launch another attack!%^RESET%^", 
			({targ, ETO}));
			ETO->execute_attack();
			return roll_dice(1, 10);
	}
	return 0;
}

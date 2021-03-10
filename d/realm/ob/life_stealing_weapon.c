#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPON;

//large battle axe or large hammer - basically going to do the same thing just look somewhat
//different - Axe/Hammer of Lifestealing 

int uses;
int query_lf() { return uses; }
int is_life_stealing_weapon() { return 1; }

void create() 
{
    	::create();
	switch(random(2)) 
	{
		
		case 0:
			//axe
			set_weight(10);
   			set_wc(3,4);
			set_large_wc(3,4);
   			set_type("slashing");
			set_prof_type("axe");
   			set_weapon_speed(8);	
			set_name("battle axe of lifestealing");
			set_id(({"axe", "battle axe", "titans axe", 
			"titan axe"}));
			set_obvious_short("%^BOLD%^%^BLUE%^A deep blue battle axe%^RESET%^");
			
			set_short("%^BOLD%^%^WHITE%^Battle Axe of "+
			"L%^RESET%^%^BLUE%^i%^BOLD%^%^WHITE%^f%^RESET%^%^BLUE%^e"+
			"%^BOLD%^%^WHITE%^s%^RESET%^%^BLUE%^t%^BOLD%^%^WHITE%^e"+
			"%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^l%^RESET%^%^BLUE%^i"+
			"%^BOLD%^%^WHITE%^n%^RESET%^%^BLUE%^g%^RESET%^");

			set_long("%^BOLD%^%^WHITE%^This large battle axe is forged "+
			"from a %^RESET%^%^BLUE%^deep blue%^BOLD%^%^WHITE%^ metal "+
			"of unknown origins.  Strange %^BOLD%^%^CYAN%^symbols"+
			"%^BOLD%^%^WHITE%^ have been "+
			"%^BOLD%^%^RED%^inscribed%^BOLD%^%^WHITE%^ over the entire "+
			"axe.  Its handle spans nearly three feet in length and "+
			"has been wrapped with a %^RESET%^%^YELLOW%^dark cloth"+
			"%^BOLD%^%^WHITE%^ to help the wilder keep a grip on it.  "+
			"At the base of the handle is a %^BOLD%^%^BLACK%^"+
			"bulbous%^BOLD%^%^CYAN%^ orb%^BOLD%^%^WHITE%^, though "+
			"its purpose is unknown.  At the top of the hammer there "+
			"is a doubled sided and %^BOLD%^%^RED%^s%^BOLD%^%^WHITE%^"+
			"e%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^r%^BOLD%^%^RED%^"+
			"a%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^"+
			"d axe head - it looks quite vicious.%^RESET%^");
			break;

   		case 1:
			//hammer
			set_weight(15);
   			set_wc(2,5);
			set_large_wc(2,6);
   			set_type("bludgeoning");
   			set_prof_type("hammer");
   			set_weapon_speed(8);
			set_name("war hammer of lifestealing");
			set_id(({"hammer", "large hammer", "titans hammer", 
			"titan hammer"}));
			set_obvious_short("%^RESET%^%^BLUE%^A deep blue war hammer%^RESET%^");

			set_short("%^BOLD%^%^WHITE%^War Hammer of "+
			"L%^RESET%^%^BLUE%^i%^BOLD%^%^WHITE%^f%^RESET%^%^BLUE%^e"+
			"%^BOLD%^%^WHITE%^s%^RESET%^%^BLUE%^t%^BOLD%^%^WHITE%^e"+
			"%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^l%^RESET%^%^BLUE%^i"+
			"%^BOLD%^%^WHITE%^n%^RESET%^%^BLUE%^g%^RESET%^");

			set_long("%^BOLD%^%^WHITE%^This large war hammer is forged from a "+
			"%^RESET%^%^BLUE%^deep blue%^BOLD%^%^WHITE%^ metal of unknown "+
			"origins.  Strange %^BOLD%^%^CYAN%^symbols%^BOLD%^%^WHITE%^ have been "+
			"%^BOLD%^%^RED%^inscribed%^BOLD%^%^WHITE%^ over the entire "+
			"hammer.  Its handle spans nearly three feet in length and "+
			"has been heavily wrapped with a %^RESET%^%^YELLOW%^dark "+
			"cloth%^BOLD%^%^WHITE%^ to help the wielder keep a grip on it.  "+
			"At the base of the handle is a %^BOLD%^%^BLACK%^bulbous"+
			"%^BOLD%^%^CYAN%^ orb%^BOLD%^%^WHITE%^, though its "+
			"purpose is unknown.  At the top of the hammer is a "+
			"thick %^BOLD%^%^RED%^s%^BOLD%^%^BLACK%^p%^BOLD%^%^RED%^"+
			"i%^BOLD%^%^BLACK%^k%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^d "+
			"%^BOLD%^%^WHITE%^head, that looks like it "+
			"could cause some serious damage.%^RESET%^");		
	
			break;
	}

	uses = 0;
   	set_weapon_prof("martial");
     	set_critical_threat_range(1);
   	set_critical_hit_multiplier(3);
	set_value(15000);
	set_property("lore difficulty", 40);

	set_lore("%^BOLD%^%^BLUE%^This "+query_prof_type()+" is one of the "+
	"weapons created by Ao'rus Devar before he shed his mortal casing and "+
	"tossed his weapons aside.  Legends suggest that he used it against his "+
	"own soldiers ages ago, trapping some of their lifeforce inside.  "+
	"Though the lifeforce inside has no control over the possessor "+
	"it is believed to occassionally lend power to the wielder in the "+
	"midst of combat.  The %^BOLD%^%^CYAN%^orb%^BOLD%^%^BLUE%^ "+
	"on the base of it can be %^BOLD%^%^WHITE%^observed"+
	"%^BOLD%^%^BLUE%^ to see how strong the lifeforce within "+
	"currently is.%^RESET%^");

  	set_property("enchantment",5);

    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
	set_item_bonus("damage bonus", 5);
    	set_hit((:TO,"special":));
}

void init()
{
	::init();
	add_action("observe_orb", "observe");
}

int observe_orb(string arg)
{
	object tar;	
	int x;
	string tmp, wh, wh2;
	if(!arg) return 0;
	//adding this to hopefully prevent interfering with other things that
	//use 'observe' as an action
	if(sscanf(arg, "%s on %s", wh, wh2) == 2) 
	{
		if(lower_case(wh) != "orb") return 0;
		if(!objectp(tar = present(wh2, TP))) return 0;
		if(!tar->is_life_stealing_weapon()) return 0;
		tmp = tar->query_prof_type();
		x = tar->query_lf();
		if(ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) 
		{
			ETO->send_paralyzed_message("info",TP);
			return 1;
		}
		tell_object(ETO, "%^BOLD%^%^WHITE%^You carefully observe "+
		"the bulbous orb on the base of your "+tmp+".%^RESET%^");
		if(!ETO->query_invis()) 
		{
			tell_room(EETO, ETOQCN + "%^BOLD%^%^WHITE%^ seems to be "+
			"focusing intently on the bulbous orb on the base of "+
			ETO->QP+" "+tmp+"%^BOLD%^%^WHITE%^.%^RESET%^", ETO);
		}

		switch(x) 
		{
			case 0..10:
				tell_object(ETO, "%^BOLD%^%^RED%^The lifeforce within the "+	
				tmp +" is quite frail.%^RESET%^");
				break;
			case 11..20:
				tell_object(ETO, "%^BOLD%^%^BLUE%^The lifeforce within the "+
				tmp +" is quite weak.%^RESET%^");
				break;
			case 21..30:
				tell_object(ETO, "%^BOLD%^%^GREEN%^The lifeforce within the "+
				tmp +" is growing in power.%^RESET%^");
				break;
			case 31..40:
				tell_object(ETO, "%^BOLD%^%^BLACK%^The lifeforce within the "+
				tmp +" is quite powerful.%^RESET%^");
				break;
			case 41..50:
				tell_object(ETO, "%^BOLD%^%^YELLOW%^The lifeforce within the "+
				tmp +" is %^BOLD%^%^RED%^SEETHING%^BOLD%^%^YELLOW%^ with "+
				"power!%^RESET%^");
				break;
		}
		return 1;
	}
	return 0;
}

			

int wield_me()
{
	if(ETO->query_highest_level() < 30) 
	{
		tell_object(ETO, "%^BOLD%^%^BLUE%^The "+query_prof_type()+
		" refuses to be controlled by "+
		"someone as weak as you.%^RESET%^");
		return 1;
	}
	tell_object(ETO, "%^BOLD%^%^BLUE%^A deep seated %^BOLD%^%^CYAN%^"+
	"power%^BOLD%^%^BLUE%^ flows out from the "+
	query_prof_type() + " and envelopes you!%^RESET%^");
	return 1;
}

int unwield_me()
{
	tell_object(ETO, "%^BOLD%^%^BLUE%^You feel the %^BOLD%^%^CYAN%^"+
	"power%^BOLD%^%^BLUE%^ granted to you by the "+
	query_prof_type() + " ebb and fade away!%^RESET%^");
	return 1;
}

int special(object targ) 
{
	string tmp, tlim;
	tmp = TO->query_prof_type();
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
	if(!objectp(EETO)) return 0;	
	if(random(1000) > 350) return 0;	

	switch(random(11)) 
	{
		case 0..5:
			tlim = targ->return_target_limb();

			tell_object(ETO, "%^BOLD%^%^MAGENTA%^You land "+
			"a vicious blow on "+targ->QCN+"%^BOLD%^%^MAGENTA%^'s "+
			tlim + " with your "+tmp+"!%^RESET%^");

			tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ lands "+
			"a powerful blow on your "+tlim +" with "+
			ETO->QP+"%^BOLD%^%^RED%^ "+tmp+"!%^RESET%^");
			
			tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ lands "+
			"a vicious blow on "+targ->QCN+"%^BOLD%^%^RED%^'s "+
			tlim+" with "+ETO->QP+" " +tmp+"!%^RESET%^", ({targ, ETO}));
			
			targ->cause_typed_damage(targ, tlim, roll_dice(2, 10), "bludgeoning");
			return 0;
		case 6..9:				
			tell_object(ETO, "%^BOLD%^%^MAGENTA%^As your "+
			tmp+" makes contact with "+targ->QCN+"%^BOLD%^"+
			"%^MAGENTA%^ it steals a portion of "+targ->QP+
			" lifeforce and replenishes its own!%^RESET%^");
			
			tell_object(targ, "%^BOLD%^%^MAGENTA%^You feel a "+
			"portion of your lifeforce stolen as "+ETOQCN+
			"%^BOLD%^%^MAGENTA%^'s "+tmp+" makes contact "+
			"with you!%^RESET%^");

			tell_room(EETO, targ->QCN+"%^BOLD%^%^MAGENTA%^ "+
			"looks weakened as "+ETOQCN+"%^BOLD%^%^MAGENTA%^'s "+
			tmp+" makes contact with "+targ->QO+"!%^RESET%^", ({ETO, targ}));
		
			targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(3,8), "negative energy");

			uses++;
			if(!random(30))
			{
				tell_object(ETO, "%^BOLD%^%^WHITE%^You feel yourself "+
				"moving faster momentarily and manage to get off another "+
				"attack!%^RESET%^");
				ETO->execute_attack();
				tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ seems to be moving "+
				"faster for a sudden moment and manages to get off another "+
				"attack!%^RESET%^", ETO);
				uses++;
			}
			if(uses > 50) uses = 50;
			return 0;
		case 10:
			if(uses < 50) 
			{
				tell_object(ETO, "%^BOLD%^%^MAGENTA%^As your "+
				tmp+" makes contact with "+targ->QCN+"%^BOLD%^"+
				"%^MAGENTA%^ it steals a portion of "+targ->QP+
				" lifeforce and replenishes its own!%^RESET%^");
			
				tell_object(targ, "%^BOLD%^%^MAGENTA%^You feel a "+
				"portion of your lifeforce stolen as "+ETOQCN+
				"%^BOLD%^%^MAGENTA%^'s "+tmp+" makes contact "+
				"with you!%^RESET%^");

				tell_room(EETO, targ->QCN+"%^BOLD%^%^MAGENTA%^ "+
				"looks weakened as "+ETOQCN+"%^BOLD%^%^MAGENTA%^'s "+
				tmp+" makes contact with "+targ->QO+"!%^RESET%^", ({ETO, targ}));
				targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(3,8), "negative energy");
				uses++;
				if(!random(30))
				{
					tell_object(ETO, "%^BOLD%^%^WHITE%^You feel yourself "+
					"moving faster momentarily and manage to get off another "+
					"attack!%^RESET%^");
					ETO->execute_attack();
					tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ seems to be moving "+
					"faster for a sudden moment and manages to get off another "+
					"attack!%^RESET%^", ETO);
					uses++;
				}
				if(uses > 50) uses = 50;
				return 0;
			}
			else
			{
				tell_object(ETO, "%^BOLD%^%^MAGENTA%^As your "+tmp+
				" collides with "+targ->QCN+" an %^BOLD%^%^RED%^e"+
				"%^YELLOW%^x%^RED%^p%^YELLOW%^l%^RED%^o%^YELLOW%^s"+
				"%^RED%^i%^YELLOW%^o%^RED%^n%^BOLD%^%^MAGENTA%^ "+
				"erupts from the head of it!%^RESET%^");
				
				tell_object(targ, "%^BOLD%^%^MAGENTA%^As "+ETOQCN+
				"%^BOLD%^%^MAGENTA%^'s "+tmp+" collides with you an "+
				"%^BOLD%^%^RED%^e"+
				"%^YELLOW%^x%^RED%^p%^YELLOW%^l%^RED%^o%^YELLOW%^s"+
				"%^RED%^i%^YELLOW%^o%^RED%^n%^BOLD%^%^MAGENTA%^ "+
				"erupts from the head of it!%^RESET%^");
				
				tell_room(EETO, "%^BOLD%^%^MAGENTA%^As "+ETOQCN+
				"%^BOLD%^%^MAGENTA%^'s "+tmp+" collides with "+
				targ->QCN+"%^BOLD%^%^MAGENTA%^ an %^BOLD%^%^RED%^e"+
				"%^YELLOW%^x%^RED%^p%^YELLOW%^l%^RED%^o%^YELLOW%^s"+
				"%^RED%^i%^YELLOW%^o%^RED%^n%^BOLD%^%^MAGENTA%^ "+
				"erupts from the head of it!%^RESET%^", ({targ, ETO}));
		
				tell_room(EETO, "%^BOLD%^%^RED%^A disembodied "+
				"voice booms: %^RESET%^ DIE "+targ->QCN+"%^RESET%^"+
				"!  DIE NOW!%^RESET%^");
				
				ETO->set_property("magic", 1);
				TO->set_property("magic", 1);
				targ->cause_typed_damage(targ, targ->return_target_limb(), uses*2, "sonic");
				ETO->set_property("magic", -1);
				TO->set_property("magic", -1);
				uses = 0;
				return 0;
			}				
	}
	return 0;
}

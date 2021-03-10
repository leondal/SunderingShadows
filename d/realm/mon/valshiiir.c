#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
int flag;

void create() 
{
   	::create();
   	set_name("valshiiir the watcher");
    	set_id(({"valshiiir", "watcher", "valshiiir"}));
    	set_gender("neuter");
    	set_race("beholder");
    	set_short("%^BOLD%^%^BLACK%^V%^BOLD%^%^WHITE%^a"+
	"%^BOLD%^%^BLACK%^lsh%^BOLD%^%^WHITE%^iii%^BOLD%^"+
	"%^BLACK%^r - The W%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
	"tch%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^r %^BOLD%^"+
	"%^WHITE%^( %^BOLD%^%^CYAN%^floating"+
	"%^BOLD%^%^WHITE%^ )%^RESET%^");

    	set_long("%^BOLD%^%^BLACK%^The thing before you is "+
	"a beholder - or the very near likeness of one.  "+
	"The central mass that is its body is covered almost "+
	"entirely by a large %^BOLD%^%^RED%^blood red%^BOLD%^"+
	"%^BLACK%^ eye.  A large open mouth rests beneath the "+
	"eye and you can see rows of %^BOLD%^%^WHITE%^razor "+
	"sharp teeth%^BOLD%^%^BLACK%^ within it.  The flesh of "+
	"its body is thick and leathery, almost reptillian in "+
	"texture.  Springing forth from its body are ten eyestalks, "+
	"though six of them appear lame and permenantly closed, "+
	"almost broken in fact.  The remaining four, however, glance "+
	"about constantly and are %^BOLD%^%^YELLOW%^yellowish"+
	"%^BOLD%^%^BLACK%^ in hue.  They never blink and appear "+
	"ever watchful.%^RESET%^"); 
  
    	set_body_type("beholder");
    	set_alignment(9);
    	set_size(4);
	set_class("mage");
	set_guild_level("mage", 55);
	set_mlevel("mage", 55);
    	set_stats("strength",15);
   	set_stats("constitution",12);
    	set_stats("wisdom",20);
    	set_stats("intelligence",25);
    	set_stats("dexterity",18);
    	set_stats("charisma",4);

	add_limb("body", 0, 0, 0, 0);

    	add_limb("central eye","body",0,0,0);
    	add_limb("eye stalk 1","body",0,0,0);
    	add_limb("eye stalk 2","body",0,0,0);
    	add_limb("eye stalk 3","body",0,0,0);
	add_limb("eye stalk 4", "body", 0, 0, 0);
	add_limb("eye stalk 5", "body", 0, 0, 0);
	add_limb("eye stalk 6", "body", 0, 0, 0);
	add_limb("eye stalk 7", "body", 0, 0, 0);
	add_limb("eye stalk 8", "body", 0, 0, 0);
	add_limb("eye stalk 9", "body", 0, 0, 0);
	add_limb("eye stalk 10", "body", 0, 0, 0);

    	set_attack_limbs(({
	"eye stalk 1",
	"eye stalk 2",
	"eye stalk 3",
    	"eye stalk 4",
    	}));

	set_property("magic", 1);
    	set("aggressive","agg_func");
    	set_overall_ac(-30);
    	set_property("weapon resistance",4);
	set_mob_magic_resistance("average");
	set_hp(4000);
    	set_new_exp(35, "very high");
	set_damage(4,8);
    	set_attacks_num(4);
	command("speak wizish");
	command("speech gurgles while somehow pronouncing every syllable");
    	set_base_damage_type("bludgeoning");
    	set_funcs(({"eye_stalk"}));
    	set_func_chance(125);
    
}

void set_paralyzed(int time,string message){return 1;}

void eye_stalk_attack(object targ)
{
	string lim, targname;
	int dam;	
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;

	lim = targ->return_target_limb();
	targname = targ->QCN;
	switch(random(40)) 
	{
		case 0..24:
			new("/cmds/spells/c/_cause_critical_wounds")->use_spell(TO, targ, 45, 45);
			break;
		case 25..30:
			new("/cmds/spells/p/_prismatic_spray")->use_spell(TO, targ, 45, 45);
			break;
		case 31..35:
			tell_object(targ, "%^BOLD%^%^RED%^A ray of fire blasts forth "+
			"from the eyestalk toward you!%^RESET%^");

			tell_room(ETO, "%^BOLD%^%^RED%^A ray of fire blasts forth "+
			"from one of Valshiiir's eyestalks toward "+ targname +
			"%^BOLD%^%^RED%^!%^RESET%^", targ);

			//less damage than a typical spell but not 
			//counting magic resistance or anything - just a save
			dam = roll_dice(30, 6);
			if("/daemon/saving_throw_d"->reflex_save(targ, -35))
			{
				tell_object(targ, "%^BOLD%^%^RED%^You manage to "+
				"avoid the full impact of the ray, but are "+
				"still singed by it!%^RESET%^");

				tell_room(ETO, targname +"%^BOLD%^%^RED%^ manages "+
				"to avoid the full impact of the ray!%^RESET%^", targ);
				targ->cause_typed_damage(targ, lim, dam/2, "fire");
			}
			else 
			{
				tell_object(targ, "%^BOLD%^%^RED%^The full impact of "+
				"the ray SEARS your flesh!%^RESET%^");
				tell_room(ETO, targname +"%^BOLD%^%^RED%^ is "+
				"SEARED by the full impact of the ray!%^RESET%^", targ);
				targ->cause_typed_damage(targ, lim, dam, "fire");
			}
		case 36..38:
			//paralyze for 40 on save fail
			tell_object(targ, "%^BOLD%^%^GREEN%^A sickly green ray "+
			"blasts forth from the eyestalk toward you!%^RESET%^");
			
			tell_room(ETO, "%^BOLD%^%^GREEN%^A sickly green ray "+
			"blasts forth from one of Valshiiir's eyestalks toward "+
			targname +"%^BOLD%^%^GREEN%^!%^RESET%^", targ);
			
			if("/daemon/saving_throw_d"->reflex_save(targ, -35))
			{
				tell_object(targ, "%^BOLD%^%^GREEN%^You manage "+
				"to move out of the way of the ray just in "+
				"time!%^RESET%^");

				tell_room(ETO, targname +"%^BOLD%^%^GREEN%^ "+
				"manages to move out of the way of the ray just in "+
				"time!%^RESET%^", targ);
			}
			else
			{
				tell_object(targ, "%^BOLD%^%^GREEN%^The ray "+
				"slams into you and your body suddenly freezes "+
				"up!%^RESET%^");	
				
				tell_room(ETO, targname + "%^BOLD%^%^GREEN%^ is hit "+
				"by the full impact of the ray and "+targ->QP+
				" body seems to freeze up!%^RESET%^", targ);
			
				targ->set_paralyzed(40, "%^BOLD%^%^GREEN%^You are "+
				"frozen stiff!%^RESET%^");
			}
		case 39:
			//necrotic damage - 50d6 on save fail - avoid
			//all damage on success
			tell_object(targ, "%^BOLD%^%^BLACK%^A dull black "+
			"ray blasts forth from the eyestalk toward you!%^RESET%^");

			tell_room(ETO, "%^BOLD%^%^BLACK%^A dull black "+
			"rays blasts forth from one of Valshiiir's eyestalks "+
			"toward "+ targname +"%^BOLD%^%^BLACK%^!%^RESET%^", targ);

			if("/daemon/saving_throw_d"->fort_save(targ, -35))
			{
				tell_object(targ, "%^BOLD%^%^BLACK%^You are struck by "+
				"the ray but are able to resist its effect!%^RESET%^");

				tell_room(ETO, targname +"%^BOLD%^%^BLACK%^ is struck by "+
				"the ray but seems to resist its effect!%^RESET%^", targ);	
			}
			else
			{
				tell_object(targ, "%^BOLD%^%^BLACK%^Your "+lim+
				" is struck by the ray and begins to %^BOLD%^%^RED%^"+
				"WILT%^BOLD%^%^BLACK%^!%^RESET%^");
				
				tell_room(ETO, targname +"%^BOLD%^%^BLACK%^'s "+lim+
				"is struck by the ray and begins to %^BOLD%^"+
				"%^RED%^WILT%^BOLD%^%^BLACK%^!%^RESET%^", targ);
			
				targ->cause_typed_damage(targ, lim, roll_dice(50, 6), "negative energy");
			}
	}
	return;
}


//uses 2 eye stalks at a time
//either 2 on one target or 1 on 
//2 targets

void eye_stalk(object targ)
{
	object *atts, vic;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	atts = TO->query_attackers();
	if(!sizeof(atts)) vic = targ;
	else vic = atts[random(sizeof(atts))];
	tell_object(targ, "%^BOLD%^%^BLACK%^Valshiiir "+
	"turns one of its eyestalks toward you!%^RESET%^");
	eye_stalk_attack(targ);
	tell_object(vic, "%^BOLD%^%^BLACK%^Valshiir "+
	"turns one of its eyestalks toward you!%^RESET%^");
	eye_stalk_attack(vic);
	return;	
}

void die(object ob)
{
	object RingOb;	
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	tell_room(ETO, "%^BOLD%^%^BLACK%^A scream of utter agony escapes "+
	"Valshiiir, as it sucks in one final intake of air and "+
	"collapses on the floor in a massive heap.%^RESET%^");
	
	if(!random(20)) 
	{
		tell_room(ETO, "%^BOLD%^%^WHITE%^You catch the glimpse of a "+
		"dull ring on the heap.%^RESET%^");
		RingOb = new(RA_OB+"greaterspellring");
		RingOb->SetMyType(1);
		RingOb->move(TO);
	}		
	TO->set_short("%^BOLD%^%^BLACK%^V%^BOLD%^%^WHITE%^a"+
	"%^BOLD%^%^BLACK%^lsh%^BOLD%^%^WHITE%^iii%^BOLD%^"+
	"%^BLACK%^r - The W%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
	"tch%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^r%^RESET%^");
	
	ETO->activate_freedom();
	::die(ob);
}

void agg_func() 
{
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
	if(TP->query_true_invis()) return;
	TO->force_me("emote turns its central gaze upon "+TPQCN);
	TO->force_me("say you should not be here, Ao'rus Devar "+
	"does not look kindly upon intruders, nevertheless, you are "+
	"and as I am what I am, it is my job to rid this place "+
	"of your essence.");
	
	TO->force_me("emote eyes all suddenly face "+TPQCN);
	
	TO->force_me("say some of my kin would take joy in enslaving you, "+
	"I shall show mercy and make your death a fast and easy one.");
	TO->force_me("kill "+TPQN);
	eye_stalk(TP);
}

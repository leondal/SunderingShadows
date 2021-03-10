#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
int time_to_heal, waiting;

void create() 
{
	object wpn1;
   	::create();
	set_name("al'tharion");
   	set_id(({"altharion", "al'tharion", "beast", "rampaging beast"}));

	set_short("%^BOLD%^%^RED%^Al'th%^BOLD%^%^MAGENTA%^a"+
	"%^BOLD%^%^RED%^r%^BOLD%^%^MAGENTA%^io%^BOLD%^%^RED%^"+
	"n, The - %^BOLD%^%^YELLOW%^UNBRIDLED%^BOLD%^%^RED%^ - "+
	"Strength of Ao'Rus Devar%^RESET%^");

	set_long("%^BOLD%^%^RED%^This towering creature "+
	"stands over twelve feet tall.  Its flesh is bulging "+
	"%^BOLD%^%^GREEN%^grotesquely%^BOLD%^%^RED%^ "+
	"throughout with deformed musclar mass.  Its entire "+
	"body seems to constantly shake, as if a deep and "+
	"powerful rage inside is threatening to escape.  Its "+
	"head is massive, easily several feet in diameter "+
	"with %^RESET%^%^RED%^dark crimson%^BOLD%^%^RED%^"+
	" eyes peering out insanely.  It is foaming a thick "+
	"%^BOLD%^%^WHITE%^froth%^BOLD%^%^RED%^ from its "+
	"mouth and you can see rows upon rows of "+
	"%^RESET%^%^WHITE%^jagged teeth%^BOLD%^%^RED%^"+
	" within.  Its torso is stretched and bulging "+
	"- %^BOLD%^%^GREEN%^scars atop of scars "+
	"%^BOLD%^%^RED%^make it appear as if this "+
	"beast has suffered horrendous burns.  "+
	"The appendages that spring forth from its torso "+
	"are also massive and you are able to actually "+
	"seem that some of the %^RESET%^%^RED%^muscle "+
	"tissue%^BOLD%^%^RED%^ from "+
	"beneath has ripped up through the flesh.%^RESET%^");

   	set_race("raging beast");
   	set_body_type("human");
   	set_gender("male");
   	set_size(5);
   	set_alignment(9);
   	set_class("fighter");
   	set_level(55);
   	set_overall_ac(-30);
   	set_guild_level("fighter",55);
	set_mlevel("fighter", 55);
   	set_max_hp(3800);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
	set_property("full attacks", 1);
	wpn1 = new(RA_OB+"life_stealing_weapon");
	wpn1->move(TO);
	if(present("axe", TO)) command("wield axe");
	if(present("hammer", TO)) command("wield hammer");

	wpn1 = new(RA_OB+"life_stealing_weapon");
	wpn1->move(TO);
	wpn1->set_property("monsterweapon", 1);
	if(present("axe", TO)) command("wield axe");
	if(present("hammer", TO)) command("wield hammer");
	set_property("magic", 1);
   	set_stats("strength",25);
   	set_stats("dexterity",10);
   	set_stats("constitution",25);
   	set_stats("wisdom",10);
   	set_stats("intelligence",10);
   	set_stats("charisma",3);
   	set("aggressive","aggression");
   	set_mob_magic_resistance("average");
   	set_new_exp(35, "very high");
      set_funcs(({"maim", "anger", "rage"}));
   	set_func_chance(40);
    	set_monster_feats(({
	    "ambidexterity",
          "two weapon fighting",
          "improved two weapon fighting",
          "greater two weapon fighting",
          "two weapon defense",
          "knockdown",
          "powerattack",
          "shatter",
          "sunder",
          "rush"
   	}));
	set_attack_bonus(10);
	time_to_heal = 0;
}


void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("emote issues an insane growl before %^RED%^ATTACKING%^RESET%^!");
		command("kill "+TPQN);	
		command("rush "+TPQN);
		return;
    	}
}

void die(object ob)
{
	ETO->fight_ends();
	::die(ob);
}

void maim(object targ)
{
	string mn;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	mn = TO->QCN;

	tell_room(ETO, mn + "%^BOLD%^%^RED%^ H%^BOLD%^%^YELLOW%^"+
	"O%^BOLD%^%^RED%^W%^BOLD%^%^RED%^L%^BOLD%^%^YELLOW%^S %^BOLD%^%^RED%^"+
	"loudly, as if in pain, and swings viciously at "+
	targ->QCN+"%^BOLD%^%^RED%^'s head!%^RESET%^", ({targ}));

	tell_object(targ, mn + "%^BOLD%^%^RED%^ H%^BOLD%^%^YELLOW%^"+
	"O%^BOLD%^%^RED%^W%^BOLD%^%^RED%^L%^BOLD%^%^YELLOW%^S %^BOLD%^%^RED%^"+
	"loudly, as if in pain, and swings viciously at your head!%^RESET%^");

	if(!"/daemon/saving_throw_d"->reflex_save(targ, -30)) 
	{
		tell_room(ETO, "%^BOLD%^%^GREEN%^A sickening C%^BOLD%^%^YELLOW%^"+
		"R%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^N%^BOLD%^%^YELLOW%^"+
		"C%^BOLD%^%^GREEN%^H resounds loudly as "+mn+" makes "+
		"contact with "+targ->QCN+"%^BOLD%^%^GREEN%^'s head!%^RESET%^", ({targ}));

		tell_object(TO, "%^BOLD%^%^GREEN%^A sudden ringing fills "+
		"your head as "+mn+"'s blow makes contact - your vision blurs - before "+
		"%^BOLD%^%^RED%^FAILING%^BOLD%^%^GREEN%^ and you are"+
		"temporarily stunned from the tremendous pain!%^RESET%^");
		targ->cause_typed_damage(targ, "head", roll_dice(10, 12), "bludgeoning");
		targ->set_temporary_blinded(1);
		targ->set_paralyzed(20, "%^BOLD%^%^GREEN%^You are still recovering from "+
		mn+"%^BOLD%^%^GREEN%^'s blow to your head!%^RESET%^");
		return;
	}
	tell_room(ETO, "%^BOLD%^%^GREEN%^A sickening C%^BOLD%^%^YELLOW%^"+
	"R%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^N%^BOLD%^%^YELLOW%^"+
	"C%^BOLD%^%^GREEN%^H resounds loudly as "+mn+"'s blow "+
	"connects with "+targ->QCN+"%^BOLD%^%^GREEN%^'s shoulder!%^RESET%^", 
	({targ}));

	tell_object(targ, "%^BOLD%^%^GREEN%^You manage to avoid the blow to your "+
	"head, but a tremendous pain jolts your body as "+mn+"'s blow connects with your "+
	"shoulder!%^RESET%^");
	targ->set_paralyzed(10, "%^BOLD%^%^GREEN%^You are still recovering from "+
	mn+"%^BOLD%^%^GREEN%^'s blow to your shoulder!%^RESET%^");
	targ->cause_typed_damage(targ, "torso", roll_dice(5, 12), "bludgeoning");
	return;
}


void anger(object targ)
{	
	string mn;
	object *vics;
	int x;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	mn = TO->QCN;
	vics = TO->query_attackers();

	if(!sizeof(vics)) return;

	tell_room(ETO, mn+"%^BOLD%^%^RED%^ R%^BOLD%^%^BLACK%^O"+
	"%^BOLD%^%^RED%^A%^BOLD%^%^BLACK%^R%^BOLD%^%^RED%^S "+
	"loudly and begins swinging his weapons viciously "+
	"around him - aiming at anything in his path!%^RESET%^");

	for(x = 0;x < sizeof(vics);x++)
	{
		if("/daemon/saving_throw_d"->reflex_save(vics[x], -20)) continue;
		tell_room(ETO, "%^BOLD%^%^BLACK%^A defeaning "+
		"%^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^R"+
		"%^BOLD%^%^WHITE%^O%^BOLD%^%^BLACK%^W"+
		"%^BOLD%^%^WHITE%^L%^BOLD%^%^WHITE%^"+
		"%^BOLD%^%^BLACK%^ escapes "+mn+" as his weapons "+
		"make contact with "+vics[x]->QCN+
		"%^BOLD%^%^BLACK%^!%^RESET%^", ({vics[x]}));

		tell_object(vics[x], "%^BOLD%^%^BLACK%^A "+
		"defeaning %^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^R"+
		"%^BOLD%^%^WHITE%^O%^BOLD%^%^BLACK%^W"+
		"%^BOLD%^%^WHITE%^L%^BOLD%^%^WHITE%^"+
		"%^BOLD%^%^BLACK%^ escapes "+mn+" as his "+
		"vicious swinging weapons "+
		"make contact with you!%^RESET%^");
		vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(4, 12), "bludgeoning");
		vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(4, 12), "slashing");
		continue;
	}
	tell_room(ETO, mn +" R%^BOLD%^%^BLACK%^O"+
	"%^BOLD%^%^RED%^A%^BOLD%^%^BLACK%^R%^BOLD%^%^RED%^S "+
	"once more and then stops his viciously wild swinging!%^RESET%^");
	return;
}

int not_true_invis(object ob)
{
	if(!objectp(ob)) return 0;
	if(ob->query_true_invis()) return 0;	
	return 1;
}

void the_sky_is_falling()
{
	int chunks;
	object *vics, vic;
	chunks = 2 + random(2);
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	vics = all_living(ETO);
	vics = filter_array(all_living(ETO), "not_true_invis", TO);
	if(!sizeof(vics)) return;
	while(chunks > 0) 
	{
		vic = vics[random(sizeof(vics))];
		if(!"/daemon/saving_throw_d.c"->reflex_save(vic, -15))
		{

			tell_room(ETO, "%^BOLD%^%^WHITE%^A chunk of "+
			"%^BOLD%^%^BLACK%^dull black%^BOLD%^%^WHITE%^ "+
			"stone slams into "+vic->QCN+"%^BOLD%^"+
			"%^WHITE%^, shattering on impact!%^RESET%^", vic);

			tell_object(vic, "%^BOLD%^%^WHITE%^You look up "+
			"just as a chunk of %^BOLD%^%^BLACK%^dull black"+
			"%^BOLD%^%^WHITE%^ stone slams into you, "+
			"shattering on impact!%^RESET%^");
			
			vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(15, 10), "bludgeoning");
		}
		else
		{
			tell_room(ETO, vic->QCN + "%^BOLD%^%^WHITE%^ "+
			"suddenly jumps to the side, avoiding "+
			"a large chunk of falling %^BOLD%^%^BLACK%^"+
			"dull black%^BOLD%^%^WHITE%^ stone, which "+
			"slams into the floor and shatters "+
			"on impact!%^RESET%^", vic);
	
			tell_object(vic, "%^BOLD%^%^WHITE%^You "+
			"look up suddenly and your reflexes "+
			"take hold - you jump to the side, avoiding "+
			"a large chunk of %^BOLD%^%^BLACK%^"+
			"dull black%^BOLD%^%^WHITE%^ stone, "+
			"which slams into the floor and shatters on "+
			"on impact!%^RESET%^");
		}
		chunks--;
	}
	waiting = 0;
}
	
void uh_oh_it_all_falls_down()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(random(4)) 
	{
		waiting = 0;
		tell_room(ETO, "%^BOLD%^%^GREEN%^The whole area around you "+
		"%^BOLD%^%^BLACK%^SHAKES%^BOLD%^%^GREEN%^ "+
		"for a moment, but then settles back down...%^RESET%^");
		return;
	}
	tell_room(ETO, "%^BOLD%^%^GREEN%^A deep rumbling "+
	"echoes here as the whole area "+
	"begins %^BOLD%^%^BLACK%^SHAKING%^BOLD%^%^GREEN%^ "+
	"wildly - you can make out what "+
	"sounds like something tremendously heavy falling "+
	"through the air above you!%^RESET%^");
	call_out("the_sky_is_falling", 5);
	return;
}


void rage(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(waiting) 
	{
		if(!objectp(targ)) return;
		TO->force_me("rush "+targ->query_name());
		return;		
	}
	tell_room(ETO, TO->QCN + " %^BOLD%^%^GREEN%^"+
	"S%^BOLD%^%^YELLOW%^C%^BOLD%^%^GREEN%^R%^BOLD%^"+
	"%^YELLOW%^E%^BOLD%^%^GREEN%^A%^BOLD%^%^YELLOW%^"+
	"M%^BOLD%^%^GREEN%^S loudly and begins "+
	"%^BOLD%^%^RED%^POUNDING%^BOLD%^%^GREEN%^ "+
	"the walls with his %^BOLD%^%^RED%^massive meaty fists"+
	"%^BOLD%^%^GREEN%^!%^RESET%^");
	waiting = 1;
	call_out("uh_oh_it_all_falls_down", 3);
	return;
}

void heart_beat() 
{
	::heart_beat();
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;	
	if(time_to_heal > 0) 
	{
		time_to_heal--;
		return;
	}
	if(random(10)) return;
	if(query_hp() < 400) 
	{
		tell_room(ETO, query_name() + "%^BOLD%^%^RED%^ growls "+
		"loudly, calling upon his inner rage to regain "+
		"some of his strength!%^RESET%^");
		TO->add_hp(150 + random(150));
		time_to_heal = 25;
	}
}



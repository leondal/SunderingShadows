#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;

void create() 
{
	object wpn1;
   	::create();
	set_name("shill'ast");
   	set_id(({"shillast", "shill'ast", "beast"}));

	set_short("%^MAGENTA%^Sh%^BOLD%^i%^RESET%^"+
	"%^MAGENTA%^ll%^BOLD%^'a%^RESET%^%^MAGENTA%^"+
	"st, The - %^BOLD%^%^YELLOW%^UNBRIDLED%^RESET%^"+
	"%^MAGENTA%^ - Quickness of Ao'rus Devar%^RESET%^");

	set_long("%^MAGENTA%^This small creature "+
	"almost appears gnomish in statue, though "+
	"it has been terribly twisted, and its "+
	"body seems to be phasing in and out of existence.  "+
	"It's face is concealed within the recesses "+
	"of a %^BOLD%^deep violet cowl%^RESET%^"+
	"%^MAGENTA%^ - with only two "+
	"%^BOLD%^%^RED%^bright crimson%^RESET%^"+
	"%^MAGENTA%^ eyes visible beneath.  The "+
	"rest of its nude, twisted body "+
	"appears featureless.  Its small twisted "+
	"appendages jut out oddly from its "+
	"torso.%^RESET%^");


   	set_race("twisted beast");
   	set_body_type("human");
   	set_gender("neuter");
   	set_size(1);
   	set_alignment(9);
   	set_class("thief");
   	set_level(55);
   	set_overall_ac(-32);
   	set_guild_level("thief",55);
	set_mlevel("thief", 55);
   	set_max_hp(3800);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
	set_property("full attacks", 1);
	wpn1 = new(RA_OB+"ethereal_sickle");
	wpn1->move(TO);
	if(random(10)) 
	{
		wpn1->set_property("monsterweapon", 1);
	}
	command("wield sickle");
	wpn1 = new(RA_OB+"shadowy_sickle");
	wpn1->move(TO);
	if(random(10)) 
	{
		wpn1->set_property("monsterweapon", 1);
	}
	new(RA_OB+"cowl")->move(TO);
	command("wear cowl");
	command("wield sickle");
	set_stats("strength",19);
   	set_stats("dexterity",30);
   	set_stats("constitution",25);
   	set_stats("wisdom",10);
   	set_stats("intelligence",10);
   	set_stats("charisma",3);
	set_scrambling(1);
   	set_thief_skill("move silently",95);
   	set_thief_skill("hide in shadows",95);
   	add_search_path("/cmds/thief");
   	set("aggressive","aggression");
   	set_new_exp(35, "very high");
	set_funcs(({"swiftattacks", "phantomblade"}));
   	set_func_chance(35);
	command("speak wizish");
   	command("speech %^BOLD%^%^GREEN%^whisper %^RESET%^"+
	"%^MAGENTA%^hoar%^BOLD%^%^GREEN%^sely%^RESET%^");
  	set_monster_feats (({
        	"ambidexterity",
	  	"two weapon fighting",
	  	"improved two weapon fighting",
	  	"greater two weapon fighting",
	  	"two weapon defense",
	  	"dodge",
	  	"evasion",
	  	"mobility",
	  	"scramble",
	  	"spring attack",
	  	"knockdown",
	  	"parry",
	  	"combat reflexes"
   	 }));
	set_attack_bonus(10);
}


void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("say YOU should NOT be HERE!");
		command("emote leans its head back and cackles.");
		command("stab "+TPQN);	
		return;
    	}
}


string text_number(int num)
{
	switch (num)
	{
		case 1: 
			return "first";
		case 2:
			return "second";
		case 3:
			return "third";
		case 4:
			return "forth";
	}
}

void summonphantomblade(object targ, int times)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	tell_room(ETO, "%^BOLD%^%^WHITE%^A wickedly "+
	"%^BOLD%^%^BLUE%^serrated %^BOLD%^%^WHITE%^ph"+
	"%^RESET%^a%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^"+
	"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
	"%^BOLD%^%^WHITE%^c blade appears next "+
	"to "+targ->QCN+"%^BOLD%^%^WHITE%^ "+
	"and slashes quickly at "+targ->QO+
	"!%^RESET%^", ({targ}));

	tell_object(targ, "%^BOLD%^%^WHITE%^A wickedly "+
	"%^BOLD%^%^BLUE%^serrated %^BOLD%^%^WHITE%^ph"+
	"%^RESET%^a%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^"+
	"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
	"%^BOLD%^%^WHITE%^c blade appears "+
	"next to you and slashes quickly at you!%^RESET%^");

	if("/daemon/saving_throw_d.c"->reflex_save(targ, -20)) 
	{
		tell_room(ETO, targ->QCN + "%^BOLD%^%^YELLOW%^ "+
		"manages to move away from the %^BOLD%^%^WHITE%^"+
		"ph%^RESET%^a%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^"+
		"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
		"%^BOLD%^%^WHITE%^c%^BOLD%^%^YELLOW%^"+
		" blade and it only grazes "+
		targ->QO+"!%^RESET%^", ({targ}));

		tell_object(targ, "%^BOLD%^%^YELLOW%^You are "+
		"able to move quickly from the "+
		"of the %^BOLD%^%^WHITE%^ph%^RESET%^a%^BOLD%^"+
		"%^WHITE%^nt%^RESET%^%^WHITE%^"+
		"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
		"%^BOLD%^%^WHITE%^c blade and it only grazes "+
		"you!%^RESET%^");
		TO->set_property("magic", 1);
		targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(6, 8), "slashing");
		TO->set_property("magic", -1);
	}
	else
	{
		tell_object(ETO, targ->QCN +"%^BOLD%^%^RED%^ "+
		"is unable to move quickly enough and the "+
		"%^BOLD%^%^WHITE%^ph%^RESET%^a%^BOLD%^"+
		"%^WHITE%^nt%^RESET%^%^WHITE%^"+
		"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
		"%^BOLD%^%^WHITE%^c%^BOLD%^%^RED%^ blade "+
		"slices deep into "+targ->QP+" flesh!%^RESET%^", ({targ}));

		tell_object(targ, "%^BOLD%^%^RED%^You are "+
		"unable to move quickly enough and the "+
		"%^BOLD%^%^WHITE%^ph%^RESET%^a%^BOLD%^"+
		"%^WHITE%^nt%^RESET%^%^WHITE%^"+
		"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i"+
		"%^BOLD%^%^WHITE%^c%^BOLD%^%^RED%^ blade "+
		"slices deep into your flesh!%^RESET%^");
		TO->set_property("magic", 1);
		targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(12, 8), "slashing");
		TO->set_property("magic", -1);
	}

	tell_room(ETO, "%^MAGENTA%^The %^BOLD%^%^WHITE%^"+
	"ph%^RESET%^a%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^"+
	"a%^BOLD%^%^WHITE%^sm%^RESET%^%^WHITE%^i%^BOLD%^"+
	"%^WHITE%^c%^RESET%^%^MAGENTA%^ blade fades away!%^RESET%^");

	times--;
	if(times > 0)
	{
		call_out("summonphantomblade", 10, targ, times);
	}
	return;

}
void phantomblade(object targ)
{
	string mn;
	int hm;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	mn = TO->QCN;
	tell_room(ETO, mn + " %^BOLD%^%^CYAN%^whispers "+
	"something in a strange language....%^RESET%^");
	hm = 2 + random(2);
	call_out("summonphantomblade", 10, targ, hm);
	return;
}


void swiftattacks(object targ)
{
	string mn;
	object *vics, vic;
	int x, hits, atts;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	vics = TO->query_attackers();
	mn = TO->QCN;
	if(!sizeof(vics)) return;
	hits = 2 + random(3);
	while(hits > 0) 
	{
		atts = 2 + random(3);
		hits--;
		vic = vics[random(sizeof(vics))];
		if(!objectp(vic)) continue;
		tell_room(ETO, mn +"%^MAGENTA%^ suddenly vanishes and "+
		"appears behind "+vic->QCN+"%^RESET%^%^MAGENTA%^"+
		" jabbing at "+vic->QO+"%^MAGENTA%^ with "+
		"%^BOLD%^%^YELLOW%^lightning fast%^RESET%^"+
		"%^MAGENTA%^ movements!%^RESET%^", ({vic}));

		tell_object(vic, mn + "%^MAGENTA%^ suddenly appears "+
		"behind you, jabbing at you with "+
		"%^BOLD%^%^YELLOW%^lightning fast%^RESET%^"+
		"%^MAGENTA%^ movements!%^RESET%^");
		x = 0;
		while(x != atts)
		{
			x++;
			if(!objectp(vic))
			{
				x = atts;
				break;
			}
			if("/daemon/saving_throw_d.c"->reflex_save(vic, -20)) 
			{
				tell_object(vic, "%^BOLD%^%^MAGENTA%^Amazingly, "+
				"you react quickly enough to avoid the "+text_number(x)+ 
				" jab!%^RESET%^");
				continue;
			}
			tell_object(vic, "%^BOLD%^%^RED%^A searing pain "+
			"floods your body as the "+text_number(x)+ 	
			" jab penetrates your flesh!%^RESET%^");
			vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(10, 6), "piercing");
			continue;
		}
	}

}

void die(object ob)
{
	ETO->fight_ends();
	::die(ob);
}



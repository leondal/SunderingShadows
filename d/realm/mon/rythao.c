#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;

void create() 
{
	object wpn1;
   	::create();
	set_name("ryth'ao");
   	set_id(({"rythao", "ryth'ao", "beast"}));

	set_short("%^BOLD%^%^WHITE%^Ry'th%^RESET%^%^WHITE%^"+
	"ao%^BOLD%^%^WHITE%^, The - %^BOLD%^%^YELLOW%^"+
	"CORRUPTED%^BOLD%^%^WHITE%^ - Spirit of Ao'rus Devar%^RESET%^");

	set_long("%^BOLD%^%^WHITE%^This thing looks "+
	"like it was, at one point anyway, human - "+
	"however, aside from the stature - it has shed "+
	"all things that would connect it to "+
	"%^BOLD%^%^RED%^humanity%^BOLD%^%^WHITE%^.  "+
	"Its flesh has bubbled up and what remains "+
	"is horribly %^BOLD%^%^GREEN%^grotesque"+
	"%^BOLD%^%^WHITE%^ and almost makes you "+
	"think this thing was dragged through "+
	"a raging fire.  Deep %^BOLD%^%^BLACK%^"+
	"black%^BOLD%^%^WHITE%^ cracks criss-cross "+
	"across all of its exposed flesh and "+
	"what you see beneath looks rotted and "+
	"dead.  A %^BOLD%^%^MAGENTA%^pentagram "+
	"%^BOLD%^%^WHITE%^ has been etched "+
	"roughly into its forehead and its "+
	"%^BOLD%^%^BLACK%^hollow lifeless eyes"+
	"%^BOLD%^%^WHITE%^ stare out at you, "+
	"almost like they are staring directly "+
	"into your soul.%^RESET%^");
   	set_race("corrupted beast");
   	set_body_type("human");
	new(RA_OB+"auros_shroud")->move(TO);
   	set_gender("neuter");
   	set_size(2);
   	set_alignment(9);
   	set_class("cleric");
   	set_level(55);
   	set_overall_ac(-20);
   	set_guild_level("cleric",55);
	set_mlevel("cleric", 55);
   	set_max_hp(3800);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
	set_property("full attacks", 1);
	set_stats("strength",15);
   	set_stats("dexterity",15);
   	set_stats("constitution",25);
   	set_stats("wisdom",30);
   	set_stats("intelligence",30);
   	set_stats("charisma",3);
   	set("aggressive","aggression");
   	set_new_exp(35, "very high");

	set_funcs(({"possession", "orbs"}));

   	set_func_chance(55);

    	set_spells(({"unholy orb", "flame strike", "frozen breath", "limb attack", 
	"monsoon", "fire storm"}));
	set_spell_chance(50);

	command("speak wizish");
   	command("speech %^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^"+
	"r%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^"+
	"k%^RESET%^s evily");
	set_monster_feats(({
        "spell focus", 
	  "spell penetration", 
	  "perfect caster", 
	  "spellmastery", 
	  "spell power",
	  "improved spell power", 
	  "greater spell power" 
	}));
	set_attack_bonus(10);
	command("wear shroud");
}

void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("say You??? You are here??  What a puny little thing you are...");
		command("emote giggles insanely");
		command("say you do not even UNDERSTAND what you face!!   Perhaps I "+
		"should step back to the time when you were birthing and kill you and your "+
		"mother...??");
		command("emote rolls its eyes into the back of its head and giggles insanely "+
		"again");
		command("say let us dance mortal, for today is the day YOU shall DIE!!!");
		new("/cmds/spells/m/_monsoon")->use_spell(TO, 0, 40, 40);
		command("kill "+TPQN);	
		return;
    	}
}
void heal(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(query_hp() >= query_max_hp()) return;
	tell_room(ETO, "%^GREEN%^A %^BOLD%^%^GREEN%^"+
	"sickly green%^RESET%^%^GREEN%^ aura surrounds "+
	TO->QCN+", strengthening "+TO->QO+"!%^RESET%^");
	TO->add_hp(roll_dice(10, 10));
}



void orbs(object targ)
{
	int x, y;
	object orb;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	x = 2 + random(1);
	tell_room(ETO, TOQCN+"%^BOLD%^%^YELLOW%^ reaches into "+TO->QP+
	" robe and pulls out of a handful of %^BOLD%^%^CYAN%^"+
	"orbs%^BOLD%^%^YELLOW%^ tossing them out across the "+
	"floor of the room!%^RESET%^");
	while(x) 
	{
		if(!objectp(TO)) return;
		orb = new(RA_OB+"sickle_ob");
		orb->set_wpn(TO);
		orb->set_owned(TO);
		y = random(2) + 1;
		switch(y)
		{
			case 1:
				orb->set_which_type(1);
				tell_room(ETO, "%^BOLD%^%^CYAN%^"+
				"An orb bounces across the floor "+
				"then suddenly rises into "+
				"midair and begins %^BOLD%^%^RED%^"+
				"SPINNING WILDLY%^BOLD%^%^CYAN%^!"+
				"%^RESET%^");
				orb->move(ETO);
				orb->start_spinning();
				break;
			case 2:
				orb->set_which_type(2);
				tell_room(ETO, "%^BOLD%^%^RED%^"+
				"An orb bounces across the floor "+
				"then suddenly rises into "+
				"midair and begins %^BOLD%^%^WHITE%^"+
				"PULSATING RAPIDLY%^BOLD%^%^RED%^"+
				"!%^RESET%^");
				orb->move(ETO);
				orb->start_spinning();
				break;
		}
		x--;
	}
	return;	
}

void possession(object targ)
{
	string mn, tn;
	object *vics, *prots;
	int x;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!userp(targ)) 
	vics = filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);
	if(!sizeof(vics)) 
	{
		if(!random(5)) heal(targ);
		return;
	}
	targ = vics[random(sizeof(vics))];
	prots = targ->query_protectors();
	if(!sizeof(prots)) 
	{
		if(!random(5)) heal(targ);
		if(!random(2)) orbs(targ);
		return;
	}
	mn = TO->QCN;
	for(x = 0;x < sizeof(prots);x++)
	{
		if(userp(prots[x])) continue;
		if(prots[x]->id("retainer")) continue;
		if(prots[x]->id("follower")) continue;
		if(!random(3)) continue;
		tn = prots[x]->query_cap_name();
		TO->force_me("emote points a twisted bony finger at "+
		tn + "!");
		TO->force_me("say %^BOLD%^%^RED%^A%^RESET%^%^RED%^I"+
		"%^BOLD%^%^RED%^D%^RESET%^%^RED%^E %^BOLD%^%^RED%^"+
		"me "+tn+"%^BOLD%^%^RED%^!");
		if(!"/daemon/saving_throw_d"->fort_save(prots[x], -15)) 
		{
			tell_room(ETO, tn + "%^BOLD%^%^GREEN%^ obeys "+
			"the command - rushing to the aide of "+mn+
			"%^BOLD%^%^GREEN%^!%^RESET%^");
			if(objectp(prots[x])) 
			{
				targ->remove_protector(prots[x]);
				TO->add_protector(prots[x]);
			}
			continue;
		}
		tell_room(ETO, tn +"%^RESET%^%^WHITE%^ is able "+
		"to %^BOLD%^%^RED%^RESIST%^RESET%^%^WHITE%^ "+
		"the command!%^RESET%^");
		continue;
	}
	return;
}

void die(object ob)
{
	ETO->fight_ends();
	::die(ob);
}



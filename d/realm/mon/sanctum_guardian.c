#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
int MyCollar, NotThisCollar;
string o_short, MyExit;
void AdjustCollar();
void remove_my_collar();
void acid_em();

void create() 
{
   	::create();
	set_name("guardian");
   	set_id(({"guardian", "guardian of the sanctum"}));

	o_short = "%^BOLD%^%^BLACK%^G%^BOLD%^%^WHITE%^ua%^BOLD%^"+
	"%^BLACK%^rd%^BOLD%^%^WHITE%^ia%^BOLD%^%^BLACK%^"+
	"n of The S%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^n"+
	"ct%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^m%^RESET%^";
	
	set_short(o_short);

	set_long("%^BOLD%^%^WHITE%^This monstrous ashen skinned "+
	"creature towers over fifteen feet tall.  He is huge and "+
	"bulges grotesquely with muscles.  His flesh is "+
	"cracked open in places, pus flows freely from the "+
	"wounds.  The hair on this things head is thickly "+
	"matted together, his faced stained with years and years "+
	"of filth.  The eyes that are set into its sockets are "+
	"larger than normal, appearing somewhat intelligent, and "+
	"seething with obvious hatred.  Around its neck is a "+
	"%^BOLD%^%^CYAN%^tattoo%^BOLD%^%^WHITE%^ - though it "+
	"almost resembles a collar - and it seems to be constantly "+
	"shifting forms.  With ever shift he %^BOLD%^%^RED%^"+
	"SCREAMS%^BOLD%^%^WHITE%^ in rage.%^RESET%^");

   	set_race("giant");
   	set_body_type("human");
   	set_gender("male");
   	set_size(4);
   	set_alignment(9);
   	set_overall_ac(-25);
	set_class("mage");
	set_class("fighter");
	set_guild_level("mage", 60);
	set_mlevel("mage", 60);
   	set_guild_level("fighter",60);
	set_mlevel("fighter", 60);
   	set_max_hp(7000);
   	set_hp(query_max_hp());
   	set_property("swarm",1);
	set_property("full attacks", 1);
	set_stats("strength",25);
   	set_stats("dexterity",14);
   	set_stats("constitution",25);
   	set_stats("wisdom",13);
   	set_stats("intelligence",18);
   	set_stats("charisma",3);
   	set("aggressive","aggression");
	set_property("weapon resistance", 3);
	set_mob_magic_resistance("average");
   	set_new_exp(35, "very high");
	set_attack_bonus(15);
	set_property("no_bump",1);
	set_property("no death", 1);
    	set_property("no hold", 1);
    	set_property("no paralyze", 1);
	
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
          "rush", 
 	    "spell focus", 
	    "spell penetration", 
	    "perfect caster", 
	    "spellmastery", 
	    "spell power",
	    "improved spell power", 
	    "greater spell power",
   	}));
	set_spells(({"cone of cold", "meteor swarm", "lightning bolt", 
	"ice storm", "greater dispel magic", "phantasmal killer"}));
	set_spell_chance(0);
	MyCollar = 0;
	NotThisCollar = 0;
	command("speak wizish");
	command("speech growl");
	MyExit = "north";
}

void set_myblock_exit(string str) { MyExit = str; }

void aggression(object targ)
{		
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
	if(TP->query_true_invis()) return;
	command("say you no shud be in here!");
	command("knockdown "+TPQN);
	command("kill "+TPQN);
	if(stringp(MyExit)) command("block "+MyExit);
	return;
}

void remove_my_collar()
{
	string MyAuraColor;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	NotThisCollar = MyCollar;
	switch(MyCollar) 
	{
		case 1:
			MyAuraColor = "%^RESET%^stone%^RESET%^";
			TO->remove_property("weapon resistance");
			TO->set_property("weapon resistance", 3);
			break;
		case 2:
			MyAuraColor = "%^BOLD%^%^BLACK%^black%^RESET%^";
			TO->set_mob_magic_resistance("average");
			break;
		case 3:
			TO->remove_property("damage resistance");
			MyAuraColor = "%^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^"+
			"ls%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^ng%^BOLD%^"+
			"%^RED%^ red%^RESET%^";
			break;
		case 4:
			MyAuraColor = "%^BOLD%^%^MAGENTA%^br%^BOLD%^%^YELLOW%^i"+
			"%^BOLD%^%^MAGENTA%^ll"+
			"%^BOLD%^%^YELLOW%^ia%^BOLD%^%^MAGENTA%^nt %^BOLD%^%^GREEN%^green"+
			"%^RESET%^%^RESET%^";
			break;
		case 5:
			MyAuraColor = "%^BOLD%^%^CYAN%^light blue%^RESET%^";
			break;
		case 6:
			MyAuraColor = "%^RESET%^%^BLUE%^dark blue%^RESET%^";
			TO->set_spell_chance(0);
			break;
		case 7:
			MyAuraColor = "%^RESET%^%^YELLOW%^dull yellow%^RESET%^";
			TO->remove_property("spellturning");
			break;
	}
	MyCollar = 0;
	tell_room(ETO, "%^BOLD%^%^WHITE%^The "+MyAuraColor+"%^BOLD%^%^WHITE%^ aura "+
	"surrounding the "+TOQCN+" fades away!%^RESET%^");
	TO->set_short(o_short);
	return;
}

void AdjustCollar()
{
	int mod = 6, mylen;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers())) return;
	//collar effects removed by call out - this function
	//simply adds a new one - Saide
	
	MyCollar = random(7) + 1;

	if(NotThisCollar != 0)
	{
		while(MyCollar == NotThisCollar)
		{
			MyCollar = random(7) + 1;
		}
	}

	switch(MyCollar)
	{
		case 1:
			//complete weapon resistance - stone colored aura
			TO->set_property("weapon resistance", 100);

			tell_room(ETO, TOQCN+"%^BOLD%^%^WHITE%^ is suddenly surrounded by "+
			"a %^RESET%^stone%^BOLD%^%^WHITE%^ colored aura!%^RESET%^");

			TO->set_short(o_short + "%^BOLD%^%^WHITE%^ ( %^RESET%^%^WHITE%^"+
			"surrounded by a stone colored aura %^BOLD%^%^WHITE%^)");		

			mylen = 3;
			break;
		case 2:
			//complete magic resistance - black aura

			TO->set_mob_magic_resistance("average");
			tell_room(ETO, TOQCN +"%^BOLD%^%^BLUE%^ is suddenly surrounded by "+
			"a %^BOLD%^%^BLACK%^black aura%^BOLD%^%^BLUE%^!%^RESET%^");

			TO->set_short(o_short +"%^BOLD%^%^WHITE%^ ( %^BOLD%^%^BLACK%^"+
			"surrounded by a black aura %^BOLD%^%^WHITE%^)");

			mylen = 3;
			break;
		case 3:
			//complete damage resistance - pulsing red aura

			TO->set_property("damage resistance", 100000);

			tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ is suddenly surrounded by "+
			"a %^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^"+
			"ls%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^ng%^BOLD%^"+
			"%^RED%^ red aura!%^RESET%^");

			TO->set_short(o_short + "%^BOLD%^%^WHITE%^ ( %^BOLD%^%^RED%^surrounded "+
			"by a %^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^"+
			"ls%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^ng%^BOLD%^"+
			"%^RED%^ red aura %^BOLD%^%^WHITE%^)%^RESET%^");

			mylen = 3;
			break;
		case 4:
			//brilliant green aura - have a chance to do acid
			//damage to all attackers on heart beat 

			tell_room(ETO, TOQCN+"%^RESET%^%^GREEN%^ is suddenly surrounded by "+
			"a %^BOLD%^%^MAGENTA%^br%^BOLD%^%^YELLOW%^i%^BOLD%^%^MAGENTA%^ll"+
			"%^BOLD%^%^YELLOW%^ia%^BOLD%^%^MAGENTA%^nt %^BOLD%^%^GREEN%^green "+
			"%^RESET%^%^GREEN%^aura!%^RESET%^");

			TO->set_short(o_short + "%^BOLD%^%^WHITE%^ ( %^RESET%^%^GREEN%^"+
			"surrounded by a %^BOLD%^%^MAGENTA%^br%^BOLD%^%^YELLOW%^"+
			"i%^BOLD%^%^MAGENTA%^ll%^BOLD%^%^YELLOW%^ia%^BOLD%^%^MAGENTA%^"+
			"nt %^BOLD%^%^GREEN%^green%^RESET%^%^GREEN%^ aura %^BOLD%^"+
			"%^WHITE%^ )%^RESET%^");

			mylen = 3;
			break;
		case 5:
			//light blue aura - have a chance to heal roll_dice(10d10) 
			//on heart_beat 
			tell_room(ETO, TOQCN +"%^BOLD%^%^BLUE%^ is suddenly surrounded by "+
			"a %^BOLD%^%^CYAN%^light blue%^BOLD%^%^BLUE%^ aura!%^RESET%^");

			TO->set_short(o_short + "%^BOLD%^%^WHITE%^ ( %^BOLD%^%^BLUE%^"+
			"surrounded by a %^BOLD%^%^CYAN%^light blue%^BOLD%^%^BLUE%^ aura "+
			"%^BOLD%^%^WHITE%^)%^RESET%^");
			
			mylen = 3;
			break;
		case 6:
			//become a spellcaster - dark blue aura
			tell_room(ETO, TOQCN+"%^BOLD%^%^BLUE%^ is suddenly surrounded by "+
			"a %^RESET%^%^BLUE%^dark blue%^BOLD%^%^BLUE%^ aura!%^RESET%^");

			TO->set_short(o_short +"%^BOLD%^%^WHITE%^ ( %^BOLD%^%^BLUE%^"+
			"surrounded by a %^RESET%^%^BLUE%^dark blue%^BOLD%^%^BLUE%^ aura "+
			"%^BOLD%^%^WHITE%^)%^RESET%^");	
			TO->set_spell_chance(125);
			mylen = 3;
			break;
		case 7:
			//reflects spells back at the attacker 
			tell_room(ETO, TOQCN+"%^BOLD%^YELLOW%^ is suddenly surrounded by "+
			"a %^RESET%^%^YELLOW%^dull yellow%^BOLD%^%^YELLOW%^ aura!%^RESET%^");
			TO->set_property("spellturning", 1000);
			mylen = 3;
			break;
	}
	call_out("remove_my_collar", (mylen * mod));
	return;
}
		
void acid_em()
{
	object *MyAttackers, CA;
	int x;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers())) return;
	MyAttackers = TO->query_attackers();
	for(x = 0;x < sizeof(MyAttackers);x++)
	{
		if(!objectp(MyAttackers[x])) continue;
		CA = MyAttackers[x];

		tell_room(ETO, "%^BOLD%^%^GREEN%^A thick acidic mist "+
		"is sprayed over "+CA->QCN+"%^BOLD%^%^GREEN%^ as "+
		CA->QS+"%^BOLD%^%^GREEN%^ gets to close to "+
		"the "+TOQCN+"!%^RESET%^", CA);
		
		tell_object(CA, "%^BOLD%^%^GREEN%^A thick acidic mist "+
		"is sprayed over you as you get to close to "+
		"the "+TOQCN+"!%^RESET%^");

		CA->cause_typed_damage(CA, CA->return_target_limb(), roll_dice(10, 8), "acid");
		continue;
	}
	return;
}

void heart_beat()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers())) return;
	if(MyCollar == 5)
	{
		if(random(2)) return;
		if((int)TO->query_max_hp() > (int)TO->query_hp()) 
		{
			tell_room(ETO, TOQCN+"%^BOLD%^%^BLUE%^ is refreshed by "+
			"the %^BOLD%^%^CYAN%^light blue%^BOLD%^%^BLUE%^ aura!%^RESET%^");
			TO->add_hp(roll_dice(15, 10));
			return;
		}
	}
	if(MyCollar == 4)
	{
		if(random(2)) return;
		acid_em();
		return;
	}
	if(find_call_out("remove_my_collar") != -1) return;
	if(random(2)) return;
	AdjustCollar();
	return;
}

void die(object ob)
{
	if(find_call_out("remove_my_collar") != -1) 
	{
		remove_call_out("remove_my_collar");
		remove_my_collar();
	}
	if(objectp(TO)) TO->set_short(o_short);
	::die(ob);
	return;
}

void set_paralyzed(int time,string message){return 1;}
void set_tripped(int time, string message) { return 1;}

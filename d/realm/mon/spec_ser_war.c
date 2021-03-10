#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object wpn1;

void create() 
{
   	object ob1, ob2;
   	::create();
	set_name("Spectral Humanoid");
   	set_id(({"spectral humanoid", "spectral warrior", "humanoid warrior"+
	"spectral humanoid warrior", "humanoid", "warrior"}));

   	set_short("%^RESET%^%^YELLOW%^An almost tr%^BOLD%^%^WHITE%^ans"+
	"%^RESET%^%^YELLOW%^lucent humanoid%^RESET%^");


   	set_long("%^RESET%^%^YELLOW%^This strange creature appears "+
	"to be almost human.  Its flesh, however, is giving off "+
	"a brilliant gl%^BOLD%^%^YELLOW%^o%^RESET%^%^YELLOW%^w and seems "+
	"to be almost tr%^BOLD%^%^WHITE%^ans%^RESET%^%^YELLOW%^"+
	"lucent.  The texture of its skin appears "+
	"leathery, almost reptillian in fact, and "+
	"is bulging grotesquely, as if the muscles below might "+
	"rip outward in an instant.  The eyes of this thing appear snake-like "+
	"but when you glance into them you realize they "+
	"are %^BOLD%^%^BLACK%^empty lifeless pits%^RESET%^%^YELLOW%^.  "+
	"Its body thick and muscular - so much so that it appears "+
	"almost bloated - its appendages are short and "+
	"twisted.%^RESET%^");

   	set_race("human");
   	set_body_type("human");
   	set_gender("male");
   	set_alignment(9);
     	set_hd(35,10);
	set_class("fighter");
	set_level(35);
	set_guild_level("fighter", 35);
	set_mlevel("fighter", 35);
   	set_overall_ac(-15);
   	set_max_hp(475);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
   	set_property("no_bump",1);
	set_property("full attacks", 1);
   	set_stats("strength",25);
   	set_stats("dexterity",14);
   	set_stats("constitution",25);
   	set_stats("wisdom",7);
   	set_stats("intelligence",7);
   	set_stats("charisma",3);
   	set("aggressive","aggression");
   	set_new_exp(35, "normal");
      set_funcs(({"sacrifice"}));
   	set_func_chance(25);
	switch(random(3))
	{
		case 0:
			wpn1 = new("/d/common/obj/weapon/spear_lg");
			wpn1->move(TO);
			set_size(2);
			wpn1->set_property("enchantment", 4 + random(2));
			command("wield spear");
			break;
		case 1:
			wpn1 = new(RA_OB+"trident_of_power");
			wpn1->move(TO);
			set_size(1);
			command("wield trident");
			break;
		case 2:
			wpn1 = new(RA_OB+"reaper_of_souls");
			wpn1->move(TO);
			set_size(1);
			command("wield scythe");
			break;
	}
	if(random(20)) 
	{
		if(objectp(wpn1)) wpn1->set_property("monsterweapon", 1);
	}
	add_search_path("/cmds/feats");
      command("speak wizish");
   	command("speech %^BOLD%^%^GREEN%^mumble i%^BOLD%^%^BLUE%^ns%^BOLD%^"+
	"%^GREEN%^a%^BOLD%^%^BLUE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^BLUE%^ly");
   	set_monster_feats(({
        "sweepingblow", 
	  "blade block", 
	  "impale", 
	  "light weapon", 
	  "strength of arm", 
	}));
	set_attack_bonus(10);
}

void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("say Aorus'Devar Shall DEVOUR YOUR %^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
		"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^!");
		command("kill "+TPQN);	
		command("sweepingblow");
		return;
    	}
}


void die(object ob)
{
	tell_room(ETO, "%^RESET%^%^MAGENTA%^Spectral Humanoid %^BOLD%^%^GREEN%^mumbles "+
	"i%^BOLD%^%^BLUE%^ns%^BOLD%^%^GREEN%^a%^BOLD%^%^BLUE%^n%^BOLD%^"+
	"%^GREEN%^e%^BOLD%^%^BLUE%^ly%^RESET%^: Your %^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
	"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^ shall be devoured!%^RESET%^");
	::die(ob);
}


void sacrifice(object targ)
{
	object *targs;
	int dam, x;
	if(TO->query_hp() > 125) 
	{
		command("sweepingblow");
		return;
	}
	dam = (int)TO->query_hp() * 2;
	if(dam < 50) dam = 50;

	tell_room(ETO, "%^BOLD%^%^RED%^The spectral humanoid drops down to "+
	"one knee - its %^BOLD%^%^BLACK%^empty lifeless eyes%^BOLD%^%^RED%^ "+
	"suddenly flaring to %^BOLD%^%^YELLOW%^LIFE%^BOLD%^%^RED%^.%^RESET%^");

	tell_room(ETO, "%^RESET%^%^MAGENTA%^Spectral Humanoid %^BOLD%^%^GREEN%^mumbles "+
	"i%^BOLD%^%^BLUE%^ns%^BOLD%^%^GREEN%^a%^BOLD%^%^BLUE%^n%^BOLD%^"+
	"%^GREEN%^e%^BOLD%^%^BLUE%^ly%^RESET%^:  USE MY LIFE TO DESTROY THESE INTRUDERS!!");

	tell_room(ETO, "%^BOLD%^%^CYAN%^A tremendous sonic wave of energy "+
	"radiates outward from the spectral humanoid as its chest "+
	"suddenly %^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^x%^BOLD%^%^RED%^"+
	"p%^BOLD%^%^YELLOW%^l%^BOLD%^%^RED%^o%^BOLD%^%^YELLOW%^d"+
	"%^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^s%^BOLD%^%^CYAN%^!%^RESET%^");

	targs = all_living(ETO);
	for(x = 0;x < sizeof(targs);x++)
	{
		if(targs[x]->query_true_invis()) continue;
		if(targs[x] == TO) continue;
		if(!objectp(targs[x])) continue;
		if(!living(targs[x])) continue;
		if(targs[x]->id("spectral humanoid")) 
		{
			tell_room(ETO, "%^BOLD%^%^CYAN%^The sonic wave "+
			"slams into "+targs[x]->query_short() + 
			"%^BOLD%^%^CYAN%^ - strengthening "+
			"it!%^RESET%^");
			targs[x]->add_hp(dam/5);
			continue;
		}
		if(!"/daemon/saving_throw_d.c"->reflex_save(targs[x], -(dam/7))) 
		{
			tell_room(ETO, "%^BOLD%^%^CYAN%^The sonic wave "+
			"slams full force into "+targs[x]->QCN+
			"%^BOLD%^%^CYAN%^!%^RESET%^", ({targs[x]}));
			tell_object(targs[x], "%^BOLD%^%^CYAN%^The sonic "+
			"wave slams full force into you!%^RESET%^");
			targs[x]->cause_typed_damage(targs[x], "torso", dam, "sonic");
			continue;
		}
		tell_room(ETO, targs[x]->QCN+"%^BOLD%^%^CYAN%^ " +
		"manages to avoid the blunt of the sonic wave!%^RESET%^", ({targs[x]}));
		tell_object(targs[x], "%^BOLD%^%^CYAN%^Miracously "+
		"you manage to avoid the blunt of the sonic wave!%^RESET%^");
		targs[x]->cause_typed_damage(targs[x], "torso", dam/2, "sonic");
		continue;
	}
	TO->die();
	return;
}

void heart_beat() 
{
   ::heart_beat();
}



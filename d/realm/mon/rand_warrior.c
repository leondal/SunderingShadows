#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;

void create() 
{
	int x;
	object wpn1;
   	::create();
	switch(random(2)) 
	{
		case 0:		
			set_name("minotaur warrior");
		   	set_id(({"minotaur", "warrior", "minotaur warrior", 
			"demonic minotaur", "demonic warrior"}));


			set_short("%^BOLD%^%^RED%^A monstrous minotaur%^RESET%^");

			set_long("%^BOLD%^%^BLACK%^This massive creature towers over "+
			"eight feet tall, its body thick and muscular.  Its head "+
			"is huge and bloated, with curved demonic horns potruding "+
			"out from the top of it.  The eyes sit further back into "+
			"their sockets than is normal and they are a %^RESET%^"+
			"%^YELLOW%^dull brown%^BOLD%^%^BLACK%^ hue.  A "+
			"%^BOLD%^%^CYAN%^glowing pentagram%^BOLD%^%^BLACK%^ "+
			"has been emblazoned upon its forehead, which "+
			"constantly pulses.  With each pulse this creature "+
			"snorts loudly from its massive nostrils, releasing "+
			"a thick glob of mucus, and seems to grow angrier.%^RESET%^");
   			set_race("minotaur");

			break;

		case 1:
			set_name("ogre warrior");

			set_id(({"ogre", "warrior", "ogre warrior", "demonic ogre", 
			"demonic warrior"}));

			set_short("%^BOLD%^%^GREEN%^A massive ogre%^RESET%^");
			
			set_long("%^BOLD%^%^GREEN%^This monstrous ogre towers "+
			"several feet taller than most of its kin, with a "+
			"horridly bloated and viciously scarred body.  Its "+
			"head is swollen, as if it has been the victim of "+
			"a wild thrashing and one of its eyes is missing, "+
			"apparently popped or ripped out.  A pair of "+
			"%^BOLD%^%^BLACK%^twisted demonic horns%^RESET%^"+
			"%^BOLD%^%^GREEN%^ jut rudely up from the top of its "+
			"head and a %^BOLD%^%^CYAN%^glowing pentagram "+
			"%^BOLD%^%^GREEN%^has been emblazoned upon its "+
			"forehead, which constantly pulses.  With "+
			"each pulse this creature growls loudly "+
			"in anger.%^RESET%^");			
			set_race("ogre");

			break;
	}		

   	set_body_type("human");
   	set_gender("male");
   	set_size(4);
   	set_alignment(9);
	x = 38 + random(7);
     	set_hd(x, 10);
	set_class("fighter");
	set_level(x);
	set_guild_level("fighter", x);
	set_mlevel("fighter", x);
   	set_overall_ac(-22);
   	set_max_hp(700 + random(350));
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
   	set("aggressive",25);
   	//set_exp(24000);
	set_new_exp(35, "normal");
      set_funcs(({"sunder", "rush", "flash"}));
   	set_func_chance(25);
	switch(random(3))
	{
		case 0:
			wpn1 = new("/d/common/obj/weapon/scythe");
			wpn1->move(TO);
			wpn1->set_property("enchantment", 4 + random(2));
			command("wield scythe");
			break;
		case 1:
			wpn1 = new(RA_OB+"trident_of_power");
			wpn1->move(TO);
			command("wield trident");
			break;
		case 2:
			wpn1 = new(RA_OB+"reaper_of_souls");
			wpn1->move(TO);
			command("wield scythe");
			break;
	}
	if(random(25)) wpn1->set_property("monsterweapon", 1);
	switch(random(3))
	{
		case 0:
			wpn1 = new("/d/common/obj/weapon/scythe");
			wpn1->move(TO);
			wpn1->set_property("enchantment", 4 + random(2));
			command("wield scythe");
			break;
		case 1:
			wpn1 = new(RA_OB+"trident_of_power");
			wpn1->move(TO);
			command("wield trident");
			break;
		case 2:
			wpn1 = new(RA_OB+"reaper_of_souls");
			wpn1->move(TO);
			command("wield scythe");
			break;
	}
	wpn1->set_property("monsterweapon", 1);
	add_search_path("/cmds/feats");
	add_search_path("/cmds/fighter");
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
	set_speed(30);
	set_moving(1);
	set_nogo(MyNoGo);
	if(!random(10)) 
	{
		set_money("gold", 500 + random(500));
	}
	set_property("death effects", "any");
}

void sunder(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(targ)) return;	
	TO->force_me("sunder "+targ->query_name());
}

void rush(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(targ)) return;
	TO->force_me("rush "+targ->query_name());
}

void flash(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(targ)) return;
	TO->force_me("flash "+targ->query_name());
}



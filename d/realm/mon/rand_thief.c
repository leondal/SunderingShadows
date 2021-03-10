#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;

void create() 
{
	object wpn1;
	int x;
   	::create();
	switch(random(2)) 
	{
		case 0:
			
			set_name("orc rogue");
		
			set_id(({"orc", "rogue", "orc rogue", "demonic orc", 
			"demonic rogue"}));
			
			set_short("%^BOLD%^%^YELLOW%^A nervous looking orc%^RESET%^");
		
			set_long("%^BOLD%^%^YELLOW%^This creature has dark gray "+
			"flesh that is covered in a thick and %^BOLD%^%^MAGENTA%^"+
			"nauseating%^BOLD%^%^YELLOW%^ layer of grime.  It stands "+
			"around eight feet tall, larger than what is common for its "+
			"kin.  Its head is massive, almost too large for the rest of its "+
			"body and a pair of %^BOLD%^%^WHITE%^horrendously twisted horns"+
			"%^BOLD%^%^YELLOW%^ jut out rudely from the top of it.  "+
			"It has empty pale eyes that stare around lifelessly and "+
			"emblazoned upon its forehead is a %^BOLD%^%^CYAN%^glowing "+
			"pentagram%^BOLD%^%^YELLOW%^, which pulses constantly.  "+
			"With each pulse this creature howls loudly in pain and "+
			"rage.%^RESET%^");

			set_race("orc");			
		
			break;
			
		case 1:

			set_name("gnoll rogue");
			
			set_id(({"gnoll", "rogue", "gnoll rogue", "demonic rogue", 
			"demonic gnoll"}));
			
			set_short("%^BOLD%^%^RED%^A gruesome looking gnoll%^RESET%^");
			
			set_long("%^BOLD%^%^RED%^This thing appears to be a gnoll, "+
			"though its body is much larger than most of its kin.  "+
			"With a layer of spikes poking up through the skin on its "+
			"forearms.  The rest of its body appears almost melted, "+
			"and most of its hair has been singed down to nearly the flesh.  "+
			"The head of this thing is monstrous, with one eye missing, as if it "+
			"suddenly ripped out and in its place sits an empty %^BOLD%^%^GREEN%^"+
			"infected%^BOLD%^%^RED%^ hollow pit.  Its muzzle is line with "+
			"row upon row of large, pointed %^BOLD%^%^YELLOW%^teeth"+
			"%^BOLD%^%^RED%^ that are black and rotted.  A pair of "+
			"%^BOLD%^%^WHITE%^massive twisted horns%^BOLD%^%^RED%^ "+
			"shoot upward from the top of its head.  A %^BOLD%^%^CYAN%^"+
			"glowing pentagram%^BOLD%^%^RED%^ has been emblazoned "+
			"upon its forehead and it constantly pulses.  With each "+
			"pulse this thing rips bits of its own flesh off, further "+
			"contributing to its gruesome appearance.%^RESET%^");

			set_race("gnoll");
			break;
	}

   	set_body_type("human");
   	set_gender("male");
   	set_size(3);
   	set_alignment(9);
   	set_class("thief");
	x = 38 + random(7);
   	set_level(x);
   	set_overall_ac(-20);
   	set_guild_level("thief",x);
	set_mlevel("thief", x);
   	set_max_hp(500 + random(300));
	set_invis();
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
	set_property("full attacks", 1);
   	set_property("no_bump",1);
	switch(random(3)) 
	{
		case 0:	
			wpn1 = new(RA_OB+"ethereal_sickle");
			wpn1->move(TO);
			command("wield sickle");
			break;
		case 1:
			wpn1 = new(RA_OB+"midnights_edge");
			wpn1->move(TO);
			command("wield scimitar");
			break;
		case 2:
			wpn1 = new(RA_OB+"shadowy_sickle");
			wpn1->move(TO);
			command("wield sickle");
			break;
	}
	if(random(25)) 
	{
		wpn1->set_property("monsterweapon", 1);
	}
	switch(random(3)) 
	{
		case 0:	
			wpn1 = new(RA_OB+"ethereal_sickle");
			wpn1->move(TO);
			command("wield sickle");
			break;
		case 1:
			wpn1 = new(RA_OB+"midnights_edge");
			wpn1->move(TO);
			command("wield scimitar");
			break;
		case 2:
			wpn1 = new(RA_OB+"shadowy_sickle");
			wpn1->move(TO);
			command("wield sickle");
			break;
	}
	wpn1->set_property("monsterweapon", 1);
	command("wield sickle");
   	set_stats("strength",18);
   	set_stats("dexterity",25);
   	set_stats("constitution",17);
   	set_stats("wisdom",7);
   	set_stats("intelligence",7);
   	set_stats("charisma",3);
	set_scrambling(1);
   	set_thief_skill("move silently",95);
   	set_thief_skill("hide in shadows",95);
   	add_search_path("/cmds/thief");
   	set("aggressive","aggression");
   	set_mob_magic_resistance("average");
   	//set_exp(24000);
	set_new_exp(35, "normal");
      set_funcs(({"knockitdown"}));
   	set_func_chance(25);
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
		"expertise",
	  	"knockdown",
	  	"parry",
	  	"combat reflexes"
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


void aggression(object targ)
{		
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("stab "+TPQN);	
		return;
    	}
}

void knockitdown(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(targ)) return;
	TO->force_me("knockdown "+targ->query_name());
}




#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object wpn1, wpn2;

void create() 
{
   	::create();
	set_name("Spectral Humanoid");
   	set_id(({"spectral humanoid", "spectral rogue", "humanoid rogue"+
	"spectral humanoid rogue", "humanoid", "rogue"}));
   	set_short("%^RESET%^%^YELLOW%^An almost tr%^BOLD%^%^WHITE%^ans"+
	"%^RESET%^%^YELLOW%^lucent humanoid%^RESET%^");

	set_long("%^RESET%^%^YELLOW%^This strange creature appears "+
	"to be almost human.  Its flesh, however, is giving off "+
	"a brilliant gl%^BOLD%^%^YELLOW%^o%^RESET%^%^YELLOW%^w and seems "+
	"to be almost tr%^BOLD%^%^WHITE%^ans%^RESET%^%^YELLOW%^"+
	"lucent.  The texture of its skin appears "+
	"leathery, almost reptillian in fact, and "+
	"is sagging, as if it is barely hanging onto the "+
	"skeleton beneath.  The eyes of this thing appear snake-like "+
	"but when you glance into them you realize they "+
	"are %^BOLD%^%^BLACK%^empty lifeless pits%^RESET%^%^YELLOW%^.  "+
	"Its body is thin and wiry, mostly lacking in muscle tone or "+
	"definition, with long and thin appendages.%^RESET%^");

   	set_race("human");
   	set_body_type("human");
   	set_gender("male");
   	set_size(2);
   	set_alignment(9);
   	set_class("thief");
   	set_level(30);
   	set_overall_ac(-12);
   	set_guild_level("thief",30);
   	set_max_hp(375);
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
			wpn1 = new(RA_OB+"shadowy_sickle");
			wpn1->move(TO);
			command("wield sickle");
			break;
		case 2:
			wpn1 = new(RA_OB+"midnights_edge");
			wpn1->move(TO);
			command("wield scimitar");
			break;
	}
	if(random(10)) 
	{
		wpn1->set_property("monsterweapon", 1);
	}
	command("wield sickle");
	wpn2 = new(RA_OB"shadowy_sickle");
	wpn2->move(TO);
	wpn2->set_property("monsterweapon", 1);
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
   	set_new_exp(35, "normal");
      set_funcs(({"maim"}));
   	set_func_chance(25);
      command("speak wizish");
   	command("speech %^BOLD%^%^GREEN%^scream m%^BOLD%^%^BLUE%^a%^BOLD%^"+
	"%^GREEN%^n%^BOLD%^%^BLUE%^i%^BOLD%^%^GREEN%^c%^BOLD%^%^BLUE%^a"+
	"%^BOLD%^%^GREEN%^lly%^RESET%^");
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
      	command("say Aorus'Devar Shall HAVE YOUR %^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
		"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^!");
		command("stab "+TPQN);	
		return;
    	}
}

void die(object ob)
{
	tell_room(ETO, "%^RESET%^%^MAGENTA%^Spectral Humanoid %^BOLD%^%^GREEN%^screams m%^BOLD%^%^BLUE%^a%^BOLD%^"+
	"%^GREEN%^n%^BOLD%^%^BLUE%^i%^BOLD%^%^GREEN%^c%^BOLD%^%^BLUE%^a"+
	"%^BOLD%^%^GREEN%^lly%^RESET%^: Your %^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
	"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^ is forfeit, "+
	"we shall meet again soon!%^RESET%^");
	::die(ob);
}

void maim(object targ)
{
	int hit;
	string wpname1, wpname2;
	if(!objectp(targ)) return;
	
	wpname1 = wpn1->query_short();
	wpname2 = wpn2->query_short();

	tell_room(ETO, "%^BOLD%^%^GREEN%^The spectral humanoid cackles manically "+
	"and its %^BOLD%^%^BLACK%^empty lifeless eyes%^BOLD%^%^GREEN%^"+
	" flare to life momentarily as it jabs its "+
	wpname1 + " at "+targ->QCN+"%^BOLD%^%^GREEN%^ chest!%^RESET%^", ({targ, TO}));

	tell_object(targ, "%^BOLD%^%^GREEN%^The spectral humanoid cackles manically "+
	"and its %^BOLD%^%^BLACK%^empy lifeless eyes%^BOLD%^%^GREEN%^"+
	" flare to life momentarily as it jabs its "+
	wpname1 + " at your chest!%^RESET%^");
	
	if(!hit = "/daemon/saving_throw_d.c"->reflex_save(targ, -20)) 
	{
		tell_room(ETO, "%^BOLD%^%^BLACK%^With a sick hissing sound the "+
		wpname1 + "%^BOLD%^%^BLACK%^ "+
		"sinks into "+targ->QCN+"%^BOLD%^%^BLACK%^'s chest!%^RESET%^", ({targ, TO}));
		
		tell_object(targ, "%^BOLD%^%^BLACK%^You are unable to move away in time and "+
		"with a sick hissing sound "+ wpname1 + "%^BOLD%^%^BLACK%^ "+
		"sinks into your chest!%^RESET%^");

		targ->cause_typed_damage(targ, "torso", roll_dice(1, 50) + 49, wpn1->query_damage_type());
		return;
	}
	tell_room(ETO, "%^BOLD%^%^GREEN%^The spectral humanoid growls insanely as "+
	"its jab misses "+targ->QCN+" - it suddenly "+
	" stabs at "+targ->QP+"%^BOLD%^%^GREEN%^ %^BOLD%^%^WHITE%^face%^BOLD%^%^GREEN%^ "+
	"with its "+ wpname2 +"%^BOLD%^%^GREEN%^!%^RESET%^", ({targ, TO}));

	tell_object(targ, "%^BOLD%^%^GREEN%^The spectral humanoid growls insanely as you "+
	"avoid its jab - then it suddenly "+
	"stabs at your face with its "+ wpname2 +"%^BOLD%^%^GREEN%^!%^RESET%^");
	
	if(!hit = "/daemon/saving_throw_d.c"->reflex_save(targ, -30)) 
	{
		tell_room(ETO, "%^BOLD%^%^BLUE%^With a vicious hiss the "+
		wpname2 + "%^BOLD%^%^BLUE%^ penetrates "+
		targ->QCN+"%^BOLD%^%^BLUE%^'s face!%^RESET%^", ({targ, TO}));

		tell_object(targ, "%^BOLD%^%^BLUE%^A sudden %^BOLD%^%^RED%^"+
		"HISS%^BOLD%^%^BLUE%^ fills your ears as the "+
		wpname2 + "%^BOLD%^%^BLUE%^ penetrates your face!%^RESET%^");
	
		targ->cause_typed_damage(targ, "torso", roll_dice(1, 50) + 99, wpn2->query_damage_type());
		return;
	}
	tell_room(ETO, targ->QCN +"%^BOLD%^%GREEN%^ manages to duck just in time, "+
	"avoiding the vicious stab!%^RESET%^", ({targ, TO}));
	tell_object(targ, "%^BOLD%^%^GREEN%^You manage to duck just in time, "+
	"avoiding the vicious stab!%^RESET%^");
	return;	
}

/*void heart_beat() 
{
   ::heart_beat();
}*/



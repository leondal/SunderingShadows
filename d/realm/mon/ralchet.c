#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
int activated;

void create() 
{
	object wpn1;
   	::create();
	set_name("ralchet");
   	set_id(({"ralchet", "beast", "mind"}));

	set_short("%^BOLD%^%^BLUE%^R%^RESET%^"+
	"%^BLUE%^a%^BOLD%^%^BLUE%^lch%^RESET%^%^BLUE%^"+
	"e%^BOLD%^%^BLUE%^t, The - %^BOLD%^%^YELLOW%^"+
	"DEMENTED%^BOLD%^%^BLUE%^ - Mind of Ao'rus Devar%^RESET%^");

	set_long("%^BOLD%^%^BLUE%^This small creature "+
	"is entirely %^BOLD%^%^BLACK%^shrouded%^BOLD%^%^BLUE%^"+
	" by a thick, dark haze.  You can make out very little of "+
	"what it actually looks like.  You manage to determine "+
	"that it is almost gnomish in appearance, yet somehow "+
	"it appears %^BOLD%^%^RED%^terribly twisted%^BOLD%^"+
	"%^BLUE%^ - %^BOLD%^%^WHITE%^cursed %^BOLD%^%^BLUE%^-"+
	" perhaps.  The only feature you can make out for "+
	"certain are its %^BOLD%^%^CYAN%^cold blue eyes%^BOLD%^"+
	"%^BLUE%^ and they appear insane, as if the mind of "+
	"this thing has become totally, irreversibly "+
	"shattered.%^RESET%^");

   	set_race("demented beast");
   	set_body_type("human");
   	set_gender("male");
   	set_size(1);
   	set_alignment(9);
   	set_class("mage");
   	set_level(55);
   	set_overall_ac(-20);
   	set_guild_level("mage",55);
	set_mlevel("mage", 55);
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

	set_funcs(({"spells", "roomliving"}));

   	set_func_chance(55);

	set_spells(({"magic missile", "cone of cold", "meteor swarm", "lightning bolt", 
	"ice storm", "stoneskin"}));
	set_spell_chance(50);

	activated = 0;

	command("speak wizish");
   	command("speech cackles %^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^ns"+
	"%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^n%^BOLD%^%^BLUE%^e%^RESET%^"+
	"%^BLUE%^ly%^RESET%^");
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
	new(RA_OB+"scintillating_boots")->move(TO);
	command("wear boots");
}

void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("say You PUNY LITTLE THING!!!  HOW DARE YOU "+
		"INTERRUPT MY STUDIES?????");
		command("emote looks are carefully, muttering a few quiet "+
		"words to himself");
		command("emote sighs deeply as he remembers the task at hand");
		command("say let us be DONE with THIS!!!!!!");
		new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, 40, 40);
		command("kill "+TPQN);	
		new("/cmds/spells/f/_fireball")->use_spell(TO, TP, 40, 40);
		return;
    	}
}

void spells(object targ)
{
	int x;
	object vic, *vics;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;	
	x = 2 + random(2);
	tell_room(ETO, TOQCN + " %^BOLD%^%^YELLOW%^S%^RESET%^"+
	"%^YELLOW%^C%^BOLD%^%^YELLOW%^R%^RESET%^%^YELLOW%^E"+
	"%^BOLD%^%^YELLOW%^A%^RESET%^%^YELLOW%^M%^BOLD%^"+
	"%^YELLOW%^S loudly - while waving his hands "+
	"about rapidly - then begins chanting what seems like "+
	"several phrases all at once!%^RESET%^");
	vics = TO->query_attackers();
	while(x > 0)
	{
		x--;
		vic = vics[random(sizeof(vics))];
		if(!objectp(vic)) continue;
		new("/cmds/spells/l/_lightning_bolt")->use_spell(TO, vic, 40, 40);
	}
	return;

}

void wall_attack(string wall_str)
{
	object vic, *vics;
	int mod, d;
	string limb;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers())) 
	{
		activated = 0;
		return;
	}
	vics = TO->query_attackers();
	if(!sizeof(vics)) return;
	vic = vics[random(sizeof(vics))];
	if(!objectp(vic)) return;
	if(!stringp(wall_str)) return;
	switch(wall_str)
	{
		case "north":
			mod = -15;
			d = 6;
			break;
		case "east":
			mod = -18;
			d = 8;
			break;
		case "south":
			mod = -21;
			d = 10;
			break;
		case "west":
			mod = -24;
			d = 12;
			break;
		default:
			mod = -15;
			d = 6;
			break;
	}
	tell_room(ETO, "%^BOLD%^%^GREEN%^A monstrous "+
	"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
	"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
	"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
	"l%^BOLD%^%^RED%^e%^BOLD%^%^GREEN%^ reaches out "+	
	"from the "+wall_str+" wall and lashes at "+
	vic->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", ({vic}));

	tell_object(vic, "%^BOLD%^%^GREEN%^A monstrous "+
	"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
	"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
	"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
	"l%^BOLD%^%^RED%^e%^BOLD%^%^GREEN%^ reaches out "+	
	"from the "+wall_str+" wall and lashes at you!%^RESET%^");
	if("/daemon/saving_throw_d.c"->reflex_save(vic, mod)) 
	{
		tell_object(vic, "%^BOLD%^%^WHITE%^Moving just "+
		"in time, you are able to avoid the "+
		"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
		"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
		"l%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^'s attack!"+
		"%^RESET%^");

		tell_room(ETO, vic->QCN + "%^BOLD%^%^WHITE%^ is "+
		"able to move just in time, avoiding the "+
		"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
		"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
		"l%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^'s attack!"+
		"%^RESET%^", ({vic}));
	}
	else 
	{
		limb = vic->return_target_limb();

		tell_object(vic, "%^BOLD%^%^YELLOW%^The "+
		"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
		"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
		"l%^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^ "+
		"lashes your "+limb+"!%^RESET%^");

		tell_room(ETO, vic->QCN + " %^BOLD%^%^YELLOW%^"+
		"is unable to move in time and the "+
		"%^BOLD%^%^BLACK%^black t%^BOLD%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^BOLD%^"+
		"%^BLACK%^a%^BOLD%^%^RED%^c%^BOLD%^%^BLACK%^"+
		"l%^BOLD%^%^RED%^e%^BOLD%^%^GREEN%^ lashes "+
		vic->QP+" " +limb+"!%^RESET%^", ({vic}));
		
		vic->cause_typed_damage(vic, limb, roll_dice(d, 8), "bludgeoning");
	}

	call_out("wall_attack", 5 + random(4), wall_str);
}

void roomliving(object targ)
{
	string wall_str;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers()))
	{
		 activated = 0;
		 return;
	}
	activated++;
	if(activated > 4) 
	{
		spells(targ);
		return;
	}
	TO->force_me("say let us SEE how you like this!!!");	
	switch(activated)
	{
		case 1:
			wall_str = "north";
			call_out("wall_attack", 5, wall_str);
			break;
		case 2:
			wall_str = "east";
			call_out("wall_attack", 5, wall_str);
			break;
		case 3:
			wall_str = "south";
			call_out("wall_attack", 5, wall_str);
			break;
		case 4:
			wall_str = "west";
			call_out("wall_attack", 5, wall_str);
			break;
	}
	tell_room(ETO, TOQCN + " %^BOLD%^%^CYAN%^chants "+
	"rapidly in a strange language and points at the "+
	wall_str + " wall.  You watch in shock as a giant "+
	"glob of %^BOLD%^%^BLACK%^black ooze%^BOLD%^ "+
	"%^CYAN%^launches out from "+TO->QO+" and sticks "+
	"to it!%^RESET%^");
	return;
}

void die(object ob)
{
	ETO->fight_ends();
	::die(ob);
}



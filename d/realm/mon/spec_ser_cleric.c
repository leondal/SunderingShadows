#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object wpn1;
int warts, sticks;

void create() 
{
   	::create();
	set_name("Spectral Humanoid");
   	set_id(({"spectral humanoid", "spectral priest", "humanoid priest"+
	"spectral humanoid priest", "humanoid", "priest"}));

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
	"Its body is thin and wiry, covered in grotesque "+
	"warts, with long and thin appendages.  A belt "+
	"around its waist holds a few bundles of sticks.%^RESET%^");

	sticks = 2 + random(2);
	warts = 3 + random(2);
   	set_race("human");
   	set_body_type("human");
   	set_gender("male");
   	set_size(2);
   	set_alignment(9);
	set_class("cleric");
	set_level(35);
	set_guild_level("cleric", 35);
	set_mlevel("cleric", 35);
   	set_overall_ac(-10);
   	set_max_hp(425);
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
   	set_property("no_bump",1);
	set_property("full attacks", 1);
   	set_stats("strength",15);
   	set_stats("dexterity",22);
   	set_stats("constitution",25);
   	set_stats("wisdom",30);
   	set_stats("intelligence",25);
   	set_stats("charisma",20);
   	set("aggressive","aggression");
   	set_new_exp(35, "normal");
	switch(random(5)) 
	{
		case 0..3:
			new("/d/common/obj/weapon/quarter_staff")->move(TO);
			set_funcs(({"minions", "warts"}));
			break;
		case 4:
			wpn1 = new(RA_OB+"staff_of_destruction");
			if(random(20)) wpn1->set_property("monsterweapon", 1);
			wpn1->move(TO);
			set_funcs(({"minions", "warts", "destroy"}));		
			break;
	}
	command("wield staff");
   	set_func_chance(25);     
    	set_spells(({"unholy orb", "flame strike", "frozen breath", "limb attack"}));
	set_spell_chance(50);
      command("speak wizish");
   	command("speech %^BOLD%^%^GREEN%^cackle l%^BOLD%^%^BLUE%^ou%^BOLD%^"+
	"%^GREEN%^dly%^RESET%^");
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
}

void aggression(object targ)
{		
	if(!objectp(TP)) return;
    	if(!TP->query_true_invis()) 
	{
      	command("say Aorus'Devar Shall CONTROL YOUR %^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
		"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^!");
		command("kill "+TPQN);	
		new("/cmds/spells/a/_animate_object")->use_spell(TO, TP, 40, 40);
		return;
    	}
}
void fix_sticks()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	ETO->set_property("no sticks", 1);
}

void die(object ob)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!ETO->query_property("no sticks")) ETO->set_property("no sticks", 1);
	tell_room(ETO, "%^RESET%^%^MAGENTA%^Spectral Humanoid %^BOLD%^%^GREEN%^cackles "+
	"l%^BOLD%^%^BLUE%^ou%^BOLD%^%^GREEN%^dly%^RESET%^: Your "+
	"%^BOLD%^%^WHITE%^S%^BOLD%^%^RED%^O"+
	"%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^L%^RESET%^ will be his!%^RESET%^");
	::die(ob);
}

void destroy(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	TO->force_me("destroy "+targ->query_name());
	return;
}

void warts(object targ)
{
	int x;
	object *targs;
	if(!objectp(targ)) return;
	if(!objectp(TO)) return;
	if(warts < 1) return;
	
	warts--;
	tell_room(ETO, "%^BOLD%^%^BLUE%^The spectral humanoid "+
	"%^BOLD%^%^RED%^SCREAMS%^BOLD%^%^BLUE%^ loudly as "+
	"it pops one of the %^BOLD%^%^GREEN%^"+
	"grotesque warts%^BOLD%^%^BLUE%^ on "+
	"its arm - releasing a sickly "+
	"green vapor in the air!%^RESET%^");
	
	targs = all_living(ETO);
	for(x = 0;x < sizeof(targs);x++)
	{
		if(targs[x]->query_true_invis()) continue;
		if(targs[x] == TO) continue;
		if(member_array(targs[x], TO->query_protectors()) != -1) continue;
		if(!objectp(targs[x])) continue;
		if(!living(targs[x])) continue;
		if(targs[x]->id("spectral humanoid")) 
		{
			tell_room(ETO, "%^BOLD%^%^GREEN%^The sickly vapor "+
			"settles over "+targs[x]->query_short() + 
			"%^BOLD%^%^CYAN%^ - strengthening "+
			"it!%^RESET%^");
			targs[x]->add_hp(35);
			continue;
		}
		if(!"/daemon/saving_throw_d.c"->fort_save(targs[x], -20))
		{
			tell_room(ETO, "%^BOLD%^%^GREEN%^The sickly "+
			"vapor settles on "+targs[x]->QCN+"%^BOLD%^%^GREEN%^"+
			" causing "+targs[x]->QO+"%^BOLD%^%^GREEN%^ "+
			"to start violently coughing and gagging!%^RESET%^", ({targs[x]}));

			tell_object(targs[x], "%^BOLD%^%^GREEN%^The sickely "+
			"vapor settles over you - causing you to start "+
			"violently coughing and gagging!%^RESET%^");
			
			targs[x]->set_paralyzed(20, "%^BOLD%^%^GREEN%^You "+
			"are coughing and gagging violently!%^RESET%^");
			continue;
		}
		tell_room(ETO, "%^BOLD%^%^GREEN%^The sickly "+
		"vapor settles on "+targs[x]->QCN+"%^BOLD%^%^GREEN%^"+
		", but seems to have no effect.%^RESET%^", ({targs[x]}));

		tell_object(targs[x], "%^BOLD%^%^GREEN%^The sickly "+
		"vapor settles on you - but you are able to resist "+
		"its effect!%^RESET%^");
		continue;
	}
	return;
}

void minions(object targ)
{
	object cor;
	if(!objectp(cor = present("corpse", ETO))) 
	{
		if(!sticks)
		{
			if(!warts) 
			{
				return;
			}
			warts(targ);
			return;
		}
		tell_room(ETO, "%^BOLD%^%^BLUE%^The spectral humanoid "+
		"tosses one of the bundles of sticks around its waist "+
		"casually to the floor....%^RESET%^");
		ETO->remove_property("no sticks");		
		new("/cmds/spells/s/_sticks_into_snakes")->use_spell(TO, 0, 40, 40);
		sticks--;
		call_out("fix_sticks", 20);
		//ETO->set_property("no sticks", 1);
		return;
	}
	tell_room(ETO, "%^BOLD%^%^BLUE%^The spectral humanoid "+
	"glances around at the floor and spotting a "+
	"corpse, grins insanely!%^RESET%^");
	new("/cmds/spells/a/_animate_dead")->use_spell(TO, 0, 40, 40);
	return;
}

void heart_beat() 
{
   ::heart_beat();
}



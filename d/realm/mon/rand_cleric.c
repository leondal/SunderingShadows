#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object wpn1;

void create() 
{
	int x;
   	::create();
	switch(random(2)) 
	{
		case 0:
			
			set_name("troll priest");
		
			set_id(({"troll", "priest", "troll priest", "demonic troll", 
			"demonic priest"}));
			
			set_short("%^BOLD%^%^MAGENTA%^A hazy troll%^RESET%^");
		
			set_long("%^BOLD%^%^MAGENTA%^This monstrous being "+
			"resembles a standard troll but stands several feet taller "+
			"and is shrouded by a %^BOLD%^%^BLACK%^thick haze%^BOLD%^"+
			"%^MAGENTA%^.  The head of this thing is particularly "+
			"gruesome as it is bruised and swollen, as if it were "+
			"the victim of a severe beating.  Monsterous %^BOLD%^"+
			"%^WHITE%^twisted ivory horns%^BOLD%^%^MAGENTA%^ "+
			"portrude out of the top of its head, one of them "+
			"cracked and almost broken.  Its eyes are pale and almost "+
			"pure %^BOLD%^%^WHITE%^white%^BOLD%^%^MAGENTA%^ surrounded "+
			"by thick dark circles.  A large %^BOLD%^%^CYAN%^"+
			"glowing pentagram has been emblazoned upon its forehead, "+
			"which constantly pulses.  With each pulse this creature "+
			"cackles loudly, a deep throaty and evil sound%^RESET%^");

			set_race("troll");			
		
			break;
			
		case 1:

			set_name("hobgoblin priest");
			
			set_id(({"hobgoblin", "priest", "hobgoblin priest", "demonic priest", 
			"demonic hobgoblin"}));
			
			set_short("%^BOLD%^%^BLUE%^An ethereal hobgoblin%^RESET%^");
			
			set_long("%^BOLD%^%^BLUE%^This ugly creature has dark reddish-brown "+
			"skin that is dried, cracked open, and apparently "+
			"%^BOLD%^%^GREEN%^infected%^BOLD%^%^BLUE%^ as a thick "+
			"pungent ooze flows freely from the wounds.  It appears %^BOLD%^%^CYAN%^"+
			"translucent%^BOLD%^%^BLUE%^ and the outline of its body wobbles "+
			"occassionally, as if it is about to simply cease to be.  It stands "+
			"nearly nine feet tall, much larger than most of its kin, and "+
			"its head is massive, much larger than what it should be.  Its eyes are "+
			"a %^BOLD%^%^YELLOW%^deep yellow%^BOLD%^%^BLUE%^ and covered with "+
			"a thick layer of mucus.  A pair of %^BOLD%^%^BLACK%^monstrous "+
			"ebony horns%^BOLD%^%^BLUE%^ jab up rudely from the top of its "+
			"head.  A %^BOLD%^%^CYAN%^glowing pentagram%^BOLD%^%^BLUE%^ has "+
			"been emblazoned upon its forehead, which pulses constantly.  "+
			"With each pulse this creature laughs manically, as if it has "+
			"lost what was once its mind.%^RESET%^");

			set_race("hobgoblin");
			break;
	}

   	set_body_type("human");
   	set_gender("male");
   	set_size(3);
   	set_alignment(9);
   	set_class("cleric");
	x = 38 + random(7);
   	set_level(x);
   	set_overall_ac(-20);
   	set_guild_level("cleric",x);
	set_mlevel("cleric", x);
   	set_max_hp(666 + random(300));
   	set_hp(query_max_hp());
   	set_wielding_limbs(({"right hand","left hand"}));
   	set_property("swarm",1);
	set_property("full attacks", 1);
   	set_property("no_bump",1);
   	set_stats("strength",18);
   	set_stats("dexterity",15);
   	set_stats("constitution",17);
   	set_stats("wisdom",25);
   	set_stats("intelligence",25);
   	set_stats("charisma",3);
  	set("aggressive",25);
   	set_mob_magic_resistance("average");
   	set_new_exp(35, "normal");
	wpn1 = new(RA_OB+"staff_of_destruction");
	if(random(25)) wpn1->set_property("monsterweapon", 1);
	wpn1->move(TO);
	command("wield staff");
      set_funcs(({"pent_pulse", "destroy"}));
   	set_func_chance(10);
	set_spells(({"unholy orb", "flame strike", "frozen breath", "limb attack", 
	"divine precision"}));
	set_spell_chance(85);
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
	set_speed(30);
	set_moving(1);
	set_nogo(MyNoGo);
	if(!random(10)) 
	{
		set_money("gold", 500 + random(500));
	}
	set_property("death effects", "any");
}

void pent_pulse(object targ)
{
	object *vics;
	string msg;
	int dam, leech = 0, x;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	vics = TO->query_attackers();
	if(!sizeof(vics)) return;
	tell_room(ETO, "%^BOLD%^%^CYAN%^The pentagram on the forehead of "+
	"the "+TOQCN+"%^BOLD%^%^CYAN%^ pulses rapidly and the room "+
	"is bathed in blue light!%^RESET%^");
	for(x = 0;x < sizeof(vics);x++)
	{
		tell_object(vics[x], "%^BOLD%^%^BLUE%^The blue light "+
		"settles upon your skin and you feel something "+
		"tugging at your lifeforce!%^RESET%^");
		
		if("/daemon/saving_throw_d.c"->fort_save(vics[x], -20)) 
		{
			tell_object(vics[x], "%^BOLD%^%^BLUE%^You manage "+
			"to resist the force tugging at you!%^RESET%^");
			continue;
		}
		tell_object(vics[x], "%^BOLD%^%^RED%^A tremendous pain "+
		"floods your body as the force pulls away part of your "+
		"lifeforce!%^RESET%^");

		dam = roll_dice(5, 10);
		leech += dam;
		vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "negative energy");
		continue;
	}
	msg = "%^BOLD%^%^MAGENTA%^The "+TOQCN+ 
	"%^BOLD%^%^MAGENTA%^ cackles demonically as the "+
	"light is sucked from the room back into the pentagram.%^RESET%^";
	if(leech) 
	{
		msg += "  %^BOLD%^%^MAGENTA%^Some of his wounds suddenly "+
		"heal themselves!%^RESET%^";
		TO->add_hp(leech);
	}
	tell_room(ETO, msg);
	return;
}

void destroy(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(targ)) return;
	TO->force_me("destroy "+targ->query_name());
	return;
}





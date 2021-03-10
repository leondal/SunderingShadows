#include <std.h>
#include "../theater.h"

inherit "std/monster";
      void create(){
      object obj;
      ::create();
	set_name("giant marionette");
	set_id(({"giant marionette", "marionette","giant","theater_mon"}));
	set_short("A giant marionette");
	set_long("%^GREEN%^Towering into the air, this giant"+
		" sized marionette stands over 10 feet tall.  A variety"+
		" of %^WHITE%^w%^BOLD%^o%^YELLOW%^o%^RESET%^%^ORANGE%^d%^RED%^s"+
		"%^GREEN%^ blend together to create this creature, the effect "+
		"proving to be a chaotic eyesore.  Seven eyes, each a different"+
		" %^BLUE%^c%^RESET%^o%^BOLD%^%^BLUE%^l%^GREEN%^o%^RESET%^%^ORANGE%^r"+
		"%^GREEN%^ peer out from the wooden face of this creature.  With"+
		" its seven nostrils, the creature's nose looks as if it was made"+
		" up of seven smaller noses.  Seven small mouths cover the lower "+
		"portion of its wooden face, each speaking in a different voice and"+
		" separately.  Its thick massive body is left uncovered, its joints"+
		" exposed.  The four armed creature holds a couple of weapons in two "+
		"of its hands, while the other two are left unarmed.  Supported by two"+
		" feet with what looks to be seven smaller feet on each foot where the "+
		"toes should be, this monstrosity doesn't seem to friendly.%^RESET%^");
	set_race("construct");
	set_gender("neuter");
	set_body_type("human");
	set_overall_ac(-5);
	set_hd(20,0);
	set_class("fighter");
	set_class("mage");
	set_class("cleric");
	set_mlevel("fighter",20);
	set_mlevel("mage",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_guild_level("mage",20);
	set_guild_level("fighter",20);
	set_guild_level("cleric",20);
	set_size(4);
	set_max_level(15);
	set_stats("strength",20);
	set_stats("intelligence",13);
	set_stats("dexterity",17);
	set_stats("charisma",10);
	set_stats("constitution",18);
	set_stats("wisdom",12);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	add_search_path("/cmds/mage");
	add_search_path("/cmds/cleric");
      add_limb("right arm2","torso",0,0,0);
      add_limb("left arm2","torso",0,0,0);
	obj=new(OBJ"shadowspear");
		if(random(2))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/special/sp_randwpn.c");
		obj->remove_property("enchantment");
		obj->set_property("enchantment",2);
		if(random(3)){
			obj->set_property("monsterweapon",1);
		}
		obj->move(TO);
	force_me("wield weapon");
	force_me("wield spear");
	force_me("wearall");
	add_money("electrum",random(1000)+900);
	set_wielding_limbs( ({ "right hand","right hand2","left hand2" "left hand" }) );
	set_max_hp(random(50)+500);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
	set_diety("loviatar");
	add_attack_bonus(4);
	set_property("add kits",5);
	set_property("no dominate",1);
	set_property("no trip",1);
	set_property("no paralyze",1);
	set_funcs(({"rushit","flashit","flashit","whirlit"}));
	set_func_chance(50);
	set_spells(({"dispel magic","vampiric touch","shout","shout","vampiric touch","flame strike","wave of pain"}));
	set_spell_chance(55);
	set_exp(random(2000)+4000);
	set_max_level(15);
	set_languages( ({ "common" }) );
	set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
}
void rushit(object targ) {
  	TO->force_me("rush" +targ->query_name());
}

void flashit(object targ) {
  	TO->force_me("flash" +targ->query_name());
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}

void die(object obj) {
	obj=new("/d/azha/obj/rift_key")->move(TO);
		tell_room(ETO,"%^ORANGE%^As the giant marionette falls to the "+
			"floor with a thunderous crash, something falls out of "+
			"one of the mouths.\n\n"+
			"\n\n"+
			"%^YELLOW%^The wall of stone, rubble, and timber "+
			"shuffles during the"+
			" fall, revealing a small hole. Perhaps you can move the stones "+
			"around before the opening collapses.");
    	::die(obj);
}

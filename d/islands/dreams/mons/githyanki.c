#include <std.h>
#include "../defs.h"
inherit "std/monster";

      void create(){
      object obj; 
      ::create();
	set_name("githyanki");
	set_id(({"githyanki","dream_mon"}));
	set_short("%^YELLOW%^A yellow skinned githyanki%^RESET%^");
	set_long("%^GREEN%^Possessing a humanoid appearance, these"+
		" %^YELLOW%^yellow%^RESET%^%^GREEN%^ skinned creatures"+
		" look gaunt.  This githyanki's flesh is stretched taunt"+
		" over its thin bones and wiry muscles.  The predominate"+
		" cheekbones of his face almost seems to draw attention to"+
		" the fact he is without a nose.  Instead two nasal slits "+
		"are cut into the center of his face.  Large %^BOLD%^%^BLACK%^"+
		"inky black%^RESET%^%^GREEN%^ pupilless eyes seem to leap off"+
		" his%^YELLOW%^ yellow%^RESET%^%^GREEN%^ skinned face.  Small"+
		" greasy looking stringy %^BOLD%^%^BLACK%^black braids%^RESET%^"+
		"%^GREEN%^ hang from his scalp.  The ends of each braid are "+
		"capped off with a embossed %^BOLD%^%^WHITE%^m%^YELLOW%^e"+
		"%^CYAN%^t%^RESET%^%^ORANGE%^a%^BLUE%^l%^GREEN%^ bead.  A pair"+
		" of elf-like ears push through his hair.  Unlike an elf's ear "+
		"though, these pointed ears are serrated along the back edges.  "+
		"The long limbed githyanki is dressed in a colorful patterned pair"+
		" of pants.  Githyanki take pride in their colorful garments with "+
		"strange and almost alien looking patterns.\n");
	set_race("githyanki");
	set_body_type("human");
	set_hd(30,10);
	set_stats("strength",16);
	set_stats("intelligence",15);
	set_stats("dexterity",15);
	set_stats("charisma",12);
	set_stats("constitution",16);
	set_stats("wisdom",15);
	set_overall_ac(-10);
	set_property("full attacks",1);
	set_size(2);
      set_property("add kits",11);
	set_alignment(6);
	set_mob_magic_resistance("average");
		switch(random(6)){
case 0:
	set_class("fighter");
     	set_mlevel("fighter",27);
     	set_guild_level("fighter",27);
	add_search_path("/cmds/fighter");
      set_stats("strength",18);
	set_parrying(1);
	obj=new(OBJ"maxe");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield axe");
	force_me("wearall");
break;
case 1:
     	set_class("thief");
	set_mlevel("thief",29);
	set_guild_level("thief",29);
	add_search_path("/cmds/thief");
	set_thief_skill("hide in shadows",95);
     	set_thief_skill("move silently",95);
	set_stats("dexterity",18);
     	set_stats("constitution",17);
	set_scrambling(1);
	obj=new(OBJ"qspear");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield spear");
break;
case 2:
     	set_class("cleric");
     	set_mlevel("cleric",27);
     	set_guild_level("cleric",27);
     	add_search_path("/cmds/cleric");
     	set_stats("wisdom",18);
	set_diety("cyric");
	set_spell_chance(40);
	set_spells( ({ "disintegrate","flame strike","confusion","dispel magic"}) );
	obj=new(OBJ"twhip");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield whip");
	force_me("wearall");
break;
case 3:
     	set_class("psion");
     	set_mlevel("psion",28);
    	set_guild_level("psion",28);
     	set_stats("intelligence",18);
     	set_stats("wisdom",16);
	set_spell_chance(95);
	set_spells(({
                "mind thrust",
                "swarm of crystals",
                "energy cone",
                "breath of the black dragon",
                "swarm of crystals",
                "ultrablast",
                "tornado blast",
                "ultrablast"}));
	obj=new("/d/common/obj/rand/randrobe.c");
		if(random(3))
		{
			obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wearall");
break;
case 4:
     	set_class("ranger");
     	set_mlevel("ranger",27);
     	set_guild_level("ranger",27);
     	add_search_path("/cmds/ranger");
     	set_stats("strength",17);
     	set_stats("dexterity",18);
	obj=new(OBJ"redtrident");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"redtrident");
		if(random(3))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield trident");
	command("wield trident 2");
break;
default:
     	set_class("antipaladin");
     	set_mlevel("antipaladin",27);
     	set_guild_level("antipaladin",27);
     	set_stats("strength",18);
     	set_stats("wisdom",16);
	set_parrying(1);
	set_diety("shar");
	set_spell_chance(30);
	set_spells( ({ "darkbolt","dispel magic","hold monster"}) );
	obj=new(OBJ"tigersword");
		if(random(3))
		{
		obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wield sword");
	command("wearall");
break;
}
	set_gender("male");
	set_size(2);   
	add_money("gold",random(400));
	add_money("silver",random(200));
	add_money("platinum",random(20));
	add_money("electrum",random(300));
	set_max_level(37);
	set_hp(random(50)+250);
      set_property("swarm",1);
      set("aggressive",25);
	//set_speed(30);
	set_nogo(({ ROOMDIR"pedestal",
			ROOMDIR"dream"}));
	set_exp(random(500)+6000);
	set_languages( ({ "common" }) );
	set_emotes(10,({
		"%^YELLOW%^The githyanki looks around with a cold gaze.",
		"%^BOLD%^%^GREEN%^The githyanki snarls in disgust."
    	}),1);
    if(!random(15)) {
      obj = new("/d/common/obj/brewing/herb_special_inherit");
      obj->set_herb_name("dream fragment");
      obj->move(TO);
    }
}

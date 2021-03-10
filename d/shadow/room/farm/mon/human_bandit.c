#include <std.h>
#include "../farm.h"

inherit MONSTER;

#define COLORS ({"%^RED%^red%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^", \
"%^BOLD%^%^BLACK%^black%^RESET%^", \
"%^RESET%^gray%^RESET%^",\
"%^YELLOW%^blonde%^RESET%^",\
"%^BOLD%^%^WHITE%^silver%^RESET%^"})

void create(){
     	int j;
	string str, COLOR;
	object obj; 
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("human bandit");
	set_id(({"human","bandit","dwarf bandit","farm_mon"}));
	set_short("%^RESET%^A lithe "+COLOR+" haired human");
	set_long("%^CYAN%^With a lithe and slender form, this"+
		" human looks swift and agile.  His long "+COLOR+""+
		"%^CYAN%^ hair is tied back with a leather cord.  "+
		"His tanned flesh hints at a life outdoors.  "+
		"Dressed in a simple homespun shirt and breeches,"+
		" his clothing shows that he's had a hard life.  "+
		"Smudges of dirt and dried mud give the appearance"+
		" as if this human's not had a bath in quite a few "+
		"days.\n");
	set_race("human");
	set_body_type("human");
	set_hd(12,5);
	set_stats("strength",16);
	set_stats("intelligence",15);
	set_stats("dexterity",18);
	set_stats("charisma",12);
	set_stats("constitution",16);
	set_stats("wisdom",15);
	set_overall_ac(8);
	set_property("full attacks",1);
	set_alignment(6);
	switch(random(2)){
case 0:
	obj=new(OBJ"hide");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
break;
case 1:
	obj=new(OBJ"leatherbp");
	if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
break;
	}	set_mob_magic_resistance("average"); //updated MR - was 30, Circe
		switch(random(5)){
case 0:
	set_class("fighter");
     	set_mlevel("fighter",12);
     	set_guild_level("fighter",12);
	add_search_path("/cmds/fighter");
      set_stats("strength",18);
	set_parrying(1);
	obj=new("/d/common/obj/weapon/battle_axe.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield axe");
	force_me("wearall");
break;
case 1:
     	set_class("thief");
	set_mlevel("thief",12);
	set_guild_level("thief",12);
	add_search_path("/cmds/thief");
	set_thief_skill("hide in shadows",95);
     	set_thief_skill("move silently",95);
	set_stats("dexterity",18);
     	set_stats("constitution",17);
	set_scrambling(1);
	obj=new("/d/common/obj/weapon/shortsword.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/weapon/dagger.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield sword");
	command("wield dagger");
	command("wearall");
break;
case 2:
     	set_class("cleric");
     	set_mlevel("cleric",12);
     	set_guild_level("cleric",12);
     	add_search_path("/cmds/cleric");
     	set_stats("wisdom",18);
	set_diety("mask");
	set_spell_chance(40);
	set_spells( ({ "limb attack","dispel magic"}) );
	obj=new("/d/common/obj/weapon/warhammer.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield hammer");
	force_me("wearall");
break;
case 3:
     	set_class("fighter");
	set_class("thief");
     	set_mlevel("fighter",11);
	set_mlevel("thief",12);
    	set_guild_level("fighter",11);
	set_guild_level("thief",12);
    	add_search_path("/cmds/fighter");
	add_search_path("/cmds/thief");
     	set_stats("dexterity",18);
     	set_stats("constitution",16);
	obj=new("/d/common/obj/weapon/broad.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/weapon/dagger.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
   	command("wield sword");
	command("wield dagger");
	command("wearall");
break;
default:
     	set_class("ranger");
	set_mlevel("ranger",12);
     	set_guild_level("ranger",12);
     	add_search_path("/cmds/ranger");
	set_stats("strength",17);
     	set_stats("dexterity",18);
	obj=new("/d/common/obj/weapon/broad.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/weapon/mclub.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	set_diety("mask");
	set_spell_chance(20);
	set_spells( ({ "limb attack","hold person","cause light wounds"}) );
	set_parrying(1);
	command("wield club");
	command("wield sword");
	command("wearall");
break;
}
	set_property("add kits",2);
	set_gender("male");
	set_size(2);   
	add_money("gold",random(20));
	add_money("silver",random(40));
	add_money("platinum",random(2));
	add_money("electrum",random(20));
	set_max_level(15);
	set_hp(random(20)+75);
      set_property("swarm",1);
      set("aggressive",25);
	//set_speed(30);
	set_nogo(({ ROOMDIR"farm6",
			ROOMDIR"gnomehome",}));
	set_exp(random(200)+1000);
	set_languages( ({ "common" }) );
	
}

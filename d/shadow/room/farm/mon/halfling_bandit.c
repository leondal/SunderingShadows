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
	set_name("halfling bandit");
	set_id(({"halfling","bandit","halfling bandit","farm_mon"}));
	set_short("%^RESET%^A mischievous "+COLOR+"-haired halfling");
	set_long("This mischievous halfling seems to have fallen in "+
          "with the wrong crowd and become just as devious as his "+
          "companions.  His long "+COLOR+" hair is pulled back "+
          "into a silver band at the base of his neck, and several "+
          "tiny earrings dot his ears.  A tattoo peeks here and "+
          "there from beneath the relatively well-repaired clothes "+
          "he wears.  Despite his impish grin, it looks as though "+
          "he would be a capable foe.");
	set_race("halfling");
	set_body_type("halfling");
        set_size(1);
        set_hd(12,5);
	set_stats("strength",16);
	set_stats("intelligence",15);
	set_stats("dexterity",18);
	set_stats("charisma",12);
	set_stats("constitution",16);
	set_stats("wisdom",15);
	set_overall_ac(8);
	set_property("full attacks",1);
	set_size(1);
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
	}
	set_mob_magic_resistance("average");//adjusted MR - was 30, Circe
		switch(random(5)){
case 0:
	set_class("fighter");
     	set_mlevel("fighter",12);
     	set_guild_level("fighter",12);
	add_search_path("/cmds/fighter");
      set_stats("strength",18);
	set_parrying(1);
	obj=new("/d/common/obj/weapon/longsword");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield sword");
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
	obj=new("/d/common/obj/weapon/dagger.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new("/d/common/obj/weapon/dagger.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield dagger");
	command("wield dagger 2");
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
      force_me("wield hammer");
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
	obj=new("/d/common/obj/weapon/shortsword.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
   	command("wield sword");
	command("wearall");
break;
default:
     	set_class("fighter");
	set_class("cleric");
     	set_mlevel("cleric",12);
	set_mlevel("fighter",12);
     	set_guild_level("cleric",12);
	set_guild_level("fighter",12);
     	add_search_path("/cmds/cleric");
	add_search_path("/cmds/fighter");
     	set_stats("strength",17);
     	set_stats("dexterity",18);
	obj=new("/d/common/obj/weapon/warhammer.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	set_diety("mask");
	set_spell_chance(20);
	set_spells( ({ "limb attack","dispel magic"}) );
	set_parrying(1);
	command("wield hammer");
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
	set_hp(random(25)+75);
      set_property("swarm",1);
      set("aggressive",25);
	//set_speed(30);
	set_nogo(({ ROOMDIR"farm6",
			ROOMDIR"gnomehome",}));
	set_exp(random(200)+1000);
	set_languages( ({ "common" }) );
	set_emotes(10,({
		"%^YELLOW%^The halfling chuckles to himself.",
		"%^BOLD%^%^GREEN%^The halfling shakes his head, brushing back his hair."
    	}),1);

}

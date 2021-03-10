// level 2 mage trooper for the Fist

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

int skins = 9;

void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	 set_class("mage");
  	set_alignment(5);
	set_name("Enchantress");
	set_id(({"trooper","mage","enchantress","Enchantress"}));
	set_short("Enchantress");
  	races = ({"elf","half-elf","human","ogre-mage","voadkyn"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(10)+30,8);
  	set_max_hp(random(100)+140);
  	set_hp(query_max_hp());
  	set_exp(1000 * query_hd());
  	set_body_type(query_race());
  	set_gender("female");
  	set_long(
@DESC
This is a mercenary who is willing to use her knowledge 
and combat skills in order to defend the Iron Fist -- 
for a fee, of course. She has sworn to fight with the Iron 
Fist members and defend them until the day she dies.
DESC
	);
  	set_guild_level("mage",query_hd());
  	set_spells(({"magic missile", "lightning bolt", "cone of cold", "fireball", "vampiric touch"}));
  	set_spell_chance(98);
  	set_overall_ac(0);

	ob = new("/d/tharis/obj/black_robes");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear robes");

	ob = new("/realms/bane/closed/bracers8");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear bracers");

	ob = new("/d/deku/armours/ring_p");
    ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",2);
	ob->move(TO);
	command("wear ring");

  	ob = new("/realms/tristan/healing");
  	ob->move(TO);
  	ob->set_uses(50);

  	set_money("gold",random(100));
  	set_mob_magic_resistance("average");
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(!present(query_name()+" summoned",ETO)){
    	new("/cmds/wizard/_monster_summoning_vii")->use_spell(TO,0,query_level());
  	}
  	
  	if(present("snake",ETO)){
  		new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  	}
  	
  	if(!query_stoneSkinned() && skins){
    	new("/cmds/wizard/_stoneskin")->use_spell(TO,TO,query_level());
    	skins--;
  	}
  	
  	if(query_hp()< 80 && present("vial",TO)){
    	command("open vial");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial"); 
    	command("offer bottle");
    	command("quaff vial");    
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
	}
}

void init(){
	object *stuff;
	
	::init();
	stuff = BAT_D->query_other_side(TO->query_guild());
	if(!wizardp(TP) && member_array(TP,stuff) != -1)
		call_out("attack",1);	
}

void attack(object ob){
	command("say You will never hold off the Iron Fist!!!");
    new("/cmds/wizard/_finger_of_death")->use_spell(TO,ob->query_name(),query_level());
	command("kill "+ob->query_name());
	new("/cmds/wizard/_wall_of_fire")->use_spell(TO,0,query_level());
}

string *query_guild(){
	return "Iron Fist";
}

void die(object ob){
	GUILD_D->remove_trooper(TO->query_guild(),base_name(TO));
	::die(ob);
}

int query_cost(){
	return 160000;
}

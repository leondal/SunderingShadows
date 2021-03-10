// level 3 bard trooper for the Fist

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

int skins = 5;

void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
	set_class("bard");
  	set_alignment(5);
	set_name("Traveling entertainer");
	set_id(({"trooper","bard", "entertainer", "traveling entertainer","Traveling entertainer"}));
	set_short("Traveling entertainer");
  	races = ({"half-elf","human","wemic"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(10)+40,8);
  	set_max_hp(random(100)+160);
  	set_hp(query_max_hp());
  	set_exp(1000 * query_hd());
  	set_body_type(query_race());
  	set_gender("female");
  	set_long(
@DESC
This is a mercenary who is willing to use her knowledge 
and combat skills for the advancement of the Iron Fist -- 
for a fee, of course. She has sworn to aid the Iron Fist 
members in their conquests until the day she dies.
DESC
	);
  	set_guild_level("mage",query_hd()-1);
  	set_spells(({"magic missile", "lightning bolt", "cone of cold", "fireball"}));
  	set_spell_chance(60);
	ob = new("/d/tharis/obj/black_robes");
	ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear robes");

  	ob = new("/d/tharis/barrow/obj/slayer");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield slayer");

	set_overall_ac(-4);
	ob = new("/d/dagger/westroad/items/armor/Mchain+1.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear chainmail");

	ob = new("/realms/bane/closed/bracers5");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear bracers");

	ob = new("/d/deku/armours/ring_p");
    ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",1);
	ob->move(TO);
	command("wear ring");

  	ob = new("/realms/tristan/healing");
  	ob->move(TO);
  	ob->set_uses(50);

  	ob = new("/d/azha/obj/gmr_ring");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear ring");

  	set_money("gold",random(100));
  	set_mob_magic_resistance("average");
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(!query_stoneSkinned() && skins){
    	new("/cmds/wizard/_stoneskin")->use_spell(TO,TO,query_level());
    	skins--;
  	}

  	if(present("snake",ETO)){
  		new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  	}
  	
  	if(!present(query_name()+" summoned",ETO)){
    	new("/cmds/wizard/_monster_summoning_iv")->use_spell(TO,0,query_level());
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
	return 180000;
}

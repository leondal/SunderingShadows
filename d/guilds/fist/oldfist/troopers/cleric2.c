// level 2 cleric trooper for the Fist

#include <std.h>
#include <daemons.h>
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

int healings = 5;

void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	
  	::create();
 	set_class("cleric");
  	set_alignment(5);
	set_name("Priestess");
	set_id(({"trooper","cleric","priestess","Priestess"}));
	set_short("Priestess");
  	races = RACE_D->query_races();
 	races = races - SHIT;
 	races = races - ({"beastman","firbolg","ogre","ogre-mage","voadkyn","wemic"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(10)+30,8);
  	set_hp(random(200)+150);
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
  	set_guild_level("cleric",query_hd());
  	set_spells(({"call lightning", "limb attack"}));
  	set_spell_chance(90);

  	ob = new("/d/dagger/marsh/tower/obj/sorrow");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield staff");

  	set_overall_ac(-5);
  	random(100);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/realms/tristan/healing");
  	ob->move(TO);
  	ob->set_uses(50);

  	set_money("gold",random(100));
}


void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	if(query_hp() < 100 && healings){
    	new("/cmds/priest/_heal")->use_spell(TO,query_name(),200);
    	healings--;
  	}
  	if(!present("snake",ETO) && !ETO->query_property("used sticks"))
    	new("/cmds/priest/_sticks_into_snakes")->use_spell(TO,0,query_level());
  	if(query_hp()< 50 && present("vial",TO)){
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
	if(!wizardp(TP) && !TP->query_invis() && member_array(TP,stuff) != -1)
		call_out("attack",1);	
}

void attack(object ob){
	command("say You will never hold off the Iron Fist!!!");
	command("kill "+ob->query_name());
	new("/cmds/priest/_animate_object")->use_spell(TO,ob->query_name(),query_level());
}

string *query_guild(){
	return "Iron Fist";
}

void die(object ob){
	GUILD_D->remove_trooper(TO->query_guild(),base_name(TO));
	::die(ob);
}

int query_cost(){
	return 175000;
}

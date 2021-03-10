// level 1 fighter trooper for the Fist

#include <std.h>
#include <daemons.h>
inherit MONSTER;
#define BAT_D "/realms/tristan/bat_d"
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

int healings = 5;
void makeMe();


void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	set_class("fighter");
  	set_alignment(5);
	set_name("Warrior");
	set_id(({"trooper","fighter","warrior","Warrior"}));
	set_short("Warrior");
  	races = RACE_D->query_races();
 	races = races - SHIT;
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(10)+20,8);
  	set_hp(random(300)+50);
  	set_exp(1050 * query_hd());
  	set_body_type(query_race());
  	set_gender("male");
  	set_long(
@DESC
This is a mercenary who is willing to use his knowledge 
and combat skills for the advancement of the Iron Fist -- 
for a fee, of course. He has sworn to aid the Iron Fist 
members in their conquests until the day he dies.
DESC
	);
  	ob = new("/d/tharis/barrow/obj/tyrelk");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield tyrelk");

  	ob=new("/d/tharis/barrow/obj/slayer");
    ob->set_property("monsterweapon",1);
  	ob->set_size(query_size());
  	ob->move(TO);
  	command("wield slayer");
  	set_overall_ac(-7);

  	ob = new("/d/attaya/seneca/armor/c_armor.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/d/deku/armours/ring_p");
    ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",1);
  	ob->move(TO);
  	command("wear ring");

  	ob = new("/realms/tristan/healing");
  	ob->move(TO);
  	ob->set_uses(75);

  	set_money("gold",random(100));
  	set_property("full attacks",1);
  	add_search_path("/cmds/fighter");
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	if(query_hp()< 75 && present("vial",TO)){
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
	command("rush "+ob->query_name());
	command("parry");
}

string *query_guild(){
	return "Iron Fist";
}

void die(object ob){
	GUILD_D->remove_trooper(TO->query_guild(),base_name(TO));
	::die(ob);
}

int query_cost(){
	return 150000;
}

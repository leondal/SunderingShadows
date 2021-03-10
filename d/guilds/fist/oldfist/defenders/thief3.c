// level 3 thief trooper for the Fist

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})
inherit MONSTER;

void create(){
	object ob, ob2;
	string name = ({}), *races;
	int i,j,k,num;
	
	::create();
	set_class("thief");
	set_alignment(5);
	set_name("Deadly assassin");
	set_id(({"trooper","assassin", "deadly assassin","Deadly assassin"}));
	set_short("Deadly assassin");
	races = RACE_D->query_races();
	races = races -  SHIT;
	races = races - ({"firbolg","half-ogre","ogre","wemic"});
	set_race(races[random(sizeof(races))]);
	set_hd(random(7)+34,8);
	set_max_hp(random(150)+150);
	set_hp(query_max_hp());
	set_exp(1000 * query_hd());
	set_body_type(query_race());
	set_gender("male");
  	set_long(
@DESC
This is a mercenary who is willing to use his knowledge 
and combat skills in order to defend the Iron Fist -- 
for a fee, of course. He has sworn to fight with the Iron 
Fist members and defend them until the day he dies.
DESC
	);
	set_guild_level("thief",query_level());
  	set_overall_ac(-5);

  	ob = new("/d/attaya/obj/screamer");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield dagger");
  	
  	ob = new("/d/deku/armours/hide");
    ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear hide");

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
  	
  	ob = new("/d/tharis/obj/bpowder");
    ob->set_property("monsterweapon",1);
	ob->move(TO);

	ob = new("/d/tharis/obj/wrist_sheath");
    ob->set_property("monsterweapon",1);
    ob2 = new("/d/attaya/obj/screamer");
    ob2->set_property("monsterweapon",1);
    ob2->set_size(1);
    ob2->move(ob);
    ob->move(TO);
    command("wear sheath");
  	set_money("gold",random(100));
  	set_mob_magic_resistance("average");
  	set_thief_skill("hide in shadows",95);
  	set_thief_skill("move silently",95);
  	add_search_path("/cmds/thief");
  	set_invis();
  	set_scrambling(1);
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
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

int do_damage(string limb, int damage){
  	int hold;
  	
  	hold = ::do_damage(limb,damage);
  	if(living(PO)) command("throw powder at "+PO->query_name());
  	if(PO->is_spell() && objectp(PO->query_caster()))
  		command("throw powder at "+PO->query_caster()->query_name());
  	return hold;
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
	command("stab "+ob->query_name());
	if(query_invis()) set_invis();
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

//Coded by Bane - based on glory fighters//
#include <std.h>
#include <daemons.h>
inherit MONSTER;
#define CONSTS ({"b","c","d","f","g","h","j","k","l",\
  "m","n","p","q","r","s","t","v","w","x","z","th","ch","sh"})
#define VOWELS ({"a","e","i","o","u","y","ou"})
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

void makeMe();
void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	 set_class("fighter");
  	j = random(8)+3;
 	name = CONSTS[random(sizeof(CONSTS))];
  	for (i= 2;i<=j;i++){
    	if(i%2)
      	name += CONSTS[random(sizeof(CONSTS))] ;
    	else 
      	name += VOWELS[random(sizeof(VOWELS))];
  	}
  	set_name(name);
  	set_alignment((random(3)*3)+1);
	set_id(({"npc","wanderer",name}));
	set_short(capitalize(name)+" the wandering fighter");
  	races = RACE_D->query_races();
 	races = races - SHIT;
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(30)+20,8);
  	set_hp(random(300)+150);
	set_exp(500 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
	set_long(
	    "This is just a simple wandering warrior.  "+capitalize(query_subjective())+
	    " walks the realms like any other searching for adventure and wonderous "+
	    "treasures."
    );
  	ob = new("/d/tharis/barrow/obj/tyrelk");
    num = random(20);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield tyrelk");

  	ob=new("/d/tharis/barrow/obj/slayer");
    num = random(20);
    if(num) ob->set_property("monsterweapon",1);
  	ob->set_size(query_size());
  	ob->move(TO);
  	command("wield slayer");
  	set_overall_ac(-7);

  	ob = new("/d/attaya/seneca/armor/c_armor.c");
    num = random(20);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/d/deku/armours/ring_p");
    num = random(20);
    if(num) ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",1);
  	ob->move(TO);
  	command("wear ring");

  	ob = new("/realms/tristan/healing");
  	ob->move(TO);
  	ob->set_uses(75);

  	set_money("gold",random(6000));
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
int kill_ob(object victim, int which){
  	int hold;
  	int i,j;
  	hold = ::kill_ob(victim, which);
	if(hold){
	command("rush "+victim->query_name());
  	return hold;
}

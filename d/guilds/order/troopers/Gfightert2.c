// test ranger monster

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

int healings = 5;
object *parties;
void makeMe();


void create(){
  	object ob;
  	int i,j,k,num;
  	::create();
 	 set_class("fighter");
        set_name("pikeman");
        set_alignment(1);
        set_id(({"fighter","warrior","pikeman"}));
        set_short("Advanced Pikeman");
        set_race("ogre");
        set_hd(random(9)+31,8);
        set_hp(10 * query_hd());
        set_level(query_hd());;
  	set_exp(1050 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("strength",20);
        set_stats("dexterity",10);
        set_stats("wisdom",9);
        set_long(
@VOID
%^BOLD%^%^RED%^These vicious looking ogre's carry giant polearms
some so big even these giants must use two hands to wield them 
efficiently. You can hear a low grunting sound echoing throughout
the pikemen's ranks.
VOID
);
        ob = new("/d/undead/town/obj/halberd.c");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
        command("wield halberd");

  	set_overall_ac(-7);

        ob = new("/d/shadow/obj/armor/fullplate.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/d/deku/armours/ring_p");
        ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",1);
  	ob->move(TO);
  	command("wear ring");

  	ob = new("/realms/tristan/healing");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(75);

  	set_property("full attacks",1);
  	add_search_path("/cmds/fighter");
  	parties = ({});
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
    j = sizeof(parties);
  	if(hold){
    	command("rush "+victim->query_name());
    	for(i =0;i<j;i++){
			if(!objectp(parties[i])) continue;
			if(pointerp(parties[i]->query_attackers())){
				if(member_array(victim, parties[i]->query_attackers()) == -1){
					parties[i]->attack(victim);
				}
			} else {
				parties[i]->attack(victim);
			}
		}
  	}
  	return hold;
}


string query_type(){return "trooper";}
string query_guild(){return "Order of Metallic Dragon";}
object *query_party(){return parties;}
int query_cost() {return 75000; }

void init(){
  object *stuff;
	::init();
	
  stuff = BAT_D->query_other_side(TO->query_guild());
  if(!wizardp(TP) && !TP->query_invis() && member_array(TP,stuff) != -1)
        TO->kill_ob(TP,1);
}

void attack(object ob){

       command("grunt");
	command("kill "+ob->query_name());
	command("parry");
}
void die(object ob){
  string type = TO->query_type();
  switch(type){
  case "trooper":
GUILD_D->remove_trooper(TO->query_guild(),base_name(TO));
  break;
  case "guard":
GUILD_D->remove_guardian(TO->query_guild(),base_name(TO));
  break;
  case "defender":
GUILD_D->remove_defender(TO->query_guild(),base_name(TO));
  break;
  ::die(ob);
}
}

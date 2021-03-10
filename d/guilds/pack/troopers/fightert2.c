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
       set_name("cherbus");
       set_alignment(9);
       set_id(({"cherbus"}));
       set_short("%^RED%^Ferocious Cherbus%^RESET%^");
       set_race("cherbus");
       set_hd(random(9)+31,8);
        set_hp(10 * query_hd());
  	set_exp(1050 * query_hd());
       set_level(query_hd());
       set_body_type("quadruped");
  	set_gender(random(2)?"male":"female");
       set_stats("dexterity",16);
        set_long(
@SEETH
%^BOLD%^%^RED%^The cherbus looks much like a wolf except it has three heads and is as large as a horse. It looks very hungry and ready to kill an intruder as it growls.
SEETH
);
	
       set_overall_ac(-16);
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
       command("open kit");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
    	command("offer bottle");
       command("quaff kit");
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
string query_guild(){return "Shades of Death";}
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

       command("growl");
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

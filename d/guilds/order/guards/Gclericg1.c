// test cleric monster

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
 	 set_class("cleric");
        set_alignment(1);
        set_name("monk");
        set_id(({"monk","cleric","monk of the order","order"}));
        set_short("Monk of the Order");
        set_race("human");
        set_hd(random(12)+18,8);
        set_hp(8 * query_hd());
        set_level(query_hd());
  	set_exp(1000 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("dexterity",18);
        set_stats("strength",18);
        set_long(
@VOID
%^BOLD%^One of the religeous leaders of the Order of the Metallic
Dragons, the Priest is well versed in worldly knowledge. Which
he will use against anyone who dares to oppose the Order.
VOID
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
  	ob = new("/d/attaya/obj/azure");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/realms/tristan/healing");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(50);

  	parties = ({});
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

int kill_ob(object victim, int which){
  	int hold;
  	int i,j;

  	hold = ::kill_ob(victim, which);
    j = sizeof(parties);
  	if(hold){
  new("/cmds/priest/_sticks_into_snakes")->use_spell(TO,victim->query_name(),query_level());
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


string query_type(){return "guardian";}
string query_guild(){return "Order of Metallic Dragon";}
object *query_party(){return parties;}
int query_cost() {return 50000;}

void init(){
  object *stuff;
	::init();
	
  stuff = BAT_D->query_other_side(TO->query_guild());
  if(!wizardp(TP) && !TP->query_invis() && member_array(TP,stuff) != -1)
        TO->kill_ob(TP,1);
}
void attack(object ob){

	command("say Ahh the glory that you shall bring to me is indeed great, "+capitalize(ob->query_name())+"!");
	command("kill "+ob->query_name());
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
}
  ::die(ob);
}

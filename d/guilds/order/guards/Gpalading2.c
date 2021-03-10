// test paladin monster

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

object *parties;
int healings = 5;
void makeMe();

void create(){
  	object ob;
  	int i,j,k,num;
  	::create();
 	 set_class("paladin");
    set_name("knight");
    set_id(({"knight","soldier","paladin","human"}));
    set_short("Warlord of the Order");
    set_alignment(1);
  	set_race("human");
        set_hd(random(9)+31,8);
        set_hp(10 * query_hd());
        set_level(query_hd());
  	set_exp(1050 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("dexterity",18);
        set_stats("strength",18);
    set_long(
@VOID
%^CYAN%^This brave young warrior sits atop an elegant white steed.
With sword in one hand and shield in the other she stands ready
to protect the Order of the Metallic Dragons to the death, no 
intruder shall enter the sacred haven of the Order without having
to pass through this brave Knight first. 
VOID
);
  	set_guild_level("cleric",query_hd()-9);
        set_spells(({"limb attack","call lightning"}));
  	set_spell_chance(20);

        ob = new("/d/undead/town/guild/paladin/hhlance.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment",4);
  	ob->move(TO);
  	ob->set_size(query_size());
        command("wield lance");

  	set_overall_ac(-3);

  	ob = new("/d/dagger/marsh/tower/obj/plate.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/d/dagger/marsh/tower/obj/shield.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear shield");

  	ob = new("/d/dagger/marsh/tower/obj/coif.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear coif");

  	ob = new("/d/deku/armours/ring_p");
        ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",1);
  	ob->move(TO);
  	command("wear ring");

  	ob = new("/realms/tristan/healing");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(50);

  	ob = new("/d/azha/obj/mr_ring");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear ring");

  	set_property("full attacks",1);
  	set_mob_magic_resistance("average");
  	call_out("horsey",1);
        parties = ({});
}


void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp() < 100 && healings){
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	healings--;
  	}
  
  	if(!present("snake",ETO) && !ETO->query_property("used sticks"))
    	new("/cmds/priest/_sticks_into_snakes")->use_spell(TO,0,query_level());
   
  	if(query_hp()< 70 && present("vial",TO)){
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
    	new("/cmds/priest/_hold_person")->use_spell(TO,victim->query_name(),query_level());
    	command("sic "+victim->query_name());
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


void init(){
  object *stuff;
	::init();
	
  stuff = BAT_D->query_other_side(TO->query_guild());
  if(!wizardp(TP) && !TP->query_invis() && member_array(TP,stuff) != -1)
            TO->call_out("horsey",1);
              TO->kill_ob(TP,1);
}

void attack(object ob){

        command("say You may take my life, but you shall never take this guild!");
	command("kill "+ob->query_name());
	
}

void horsey(){
	new("/d/shadow/room/city/cguild/paladin/war_horse")->move(ETO);
	command("mount horse");
}


string query_type() {return "guardian";}
string query_guild(){return "Order of Metallic Dragon";}
object *query_party(){return parties;}
int query_cost() {return 75000;}
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

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
 	 set_class("ranger");
        set_name("protector");
        set_id(({"protector","ranger","human","soldier"}));
        set_short("Protector of the Righteous");
        set_alignment(1);
        set_race("voadkyn");
        set_hd(random(12)+18,8);
        set_hp(10 * query_hd());
        set_level(query_hd());
  	set_exp(1050 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("strength",18);
        set_stats("dexterity",20);
        set_long(
@VOID
%^BOLD%^%^BLUE%^These are the noble Protectors of the Order of the
Metallic Dragons. The Protectors help to make up the front lines of
any army, for they are a truly awesome foe in close quarters combat.
A Protector should not only be feared, but respected.
VOID
);
  	set_guild_level("cleric",query_hd()-8);
  	set_spells(({"call lightning", "limb attack"}));
  	set_spell_chance(20);

  	ob = new("/d/tharis/barrow/obj/tyrelk");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
        ob->set_size(1);
  	command("wield tyrelk");

  	ob=new("/d/shadow/obj/weapon/longsword");
        ob->set_property("monsterweapon",1);
  	ob->set_size(query_size());
  	ob->move(TO);
  	command("wield long sword");

  	set_overall_ac(-5);
  	ob = new("/d/attaya/obj/azure");
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
  	ob->set_uses(50);
  	set_property("full attacks",1);
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
    	new("/cmds/priest/_hold_person")->use_spell(TO,victim->query_name(),query_level());
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


string query_guild(){return "Order of Metallic Dragon";}
string query_type(){return "guardian";}
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

        command("say For the greater glory of the Order of the Metallic Dragons!");
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
  ::die(ob);
}
}

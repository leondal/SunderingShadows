// test mage monster

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;


object *parties;
int skins = 7;

void makeMe();
void create(){
  	object ob;
  	int i,j,k,num;
  	::create();
 	 set_class("mage");
        set_alignment(5);
        set_name("archmagi");
        set_id(({"mage","magi","archmagi","order","soldier"}));
        set_short("Archmagi of the Order");
        set_race("elf");
        set_hd(random(14)+41,8);
        set_hp(4 * query_hd());
        set_level(query_hd());
  	set_exp(1000 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("strength",16);
        set_stats("intelligence",18);
        set_stats("dexterity",17);
        set_long(
@VOID
%^MAGENTA%^These are the wise seers of the Order of the Metallic
Dragons. Advisors to the High Lords themselves. But do not underestimate
them based on their age. They are still very formadible in battle
VOID
);
  	set_guild_level("mage",query_hd());
        set_spells(({"magic missile","lightning bolt","cone of cold","fireball","monster summoning iii"}));
  	set_spell_chance(98);

        ob = new("/d/tharis/obj/white_robes");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear robes");

  	ob = new("/d/tharis/barrow/obj/staff");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield staff");
  	set_overall_ac(0);

	ob = new("/realms/bane/closed/bracers8");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear bracers");

	ob = new("/d/deku/armours/ring_p");
        ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",2);
	ob->move(TO);
	command("wear ring");

  	ob = new("/realms/tristan/healing");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(50);

  	set_mob_magic_resistance("average");
  	parties = ({});
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(!present(query_name()+" summoned",ETO)){
    	new("/cmds/wizard/_monster_summoning_vii")->use_spell(TO,0,query_level());
  	}
  	
  	
  	if(!query_stoneSkinned() && skins){
    	new("/cmds/wizard/_stoneskin")->use_spell(TO,TO,query_level());
    	skins--;
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

int kill_ob(object victim, int which){
  	int hold;
  	int i,j;


  	hold = ::kill_ob(victim, which);
  	j = sizeof(parties);
  	if(hold) {
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
        TO->kill_ob(TP,1);
}

void attack(object ob){
        command("say I have seen the outcome of today's battle, and it ends with your death!");
    new("/cmds/wizard/_finger_of_death")->use_spell(TO,ob->query_name(),query_level());
	command("kill "+ob->query_name());
	new("/cmds/wizard/_wall_of_fire")->use_spell(TO,0,query_level());
}


string query_guild(){return "Order of Metallic Dragon";}
string query_type(){return "guardian";}
object *query_party(){return parties;}
int query_cost(){return 100000;}
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
GUILD_D->remvoe_defender(TO->query_guild(),base_name(TO));
  break;
  ::die(ob);
}
}

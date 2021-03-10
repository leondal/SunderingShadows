// test bard monster

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

int skins = 5;
object *parties;

void makeMe();
void create(){
  	object ob;
  	int i,j,k,num;
  	::create();
 	 set_class("bard");
        set_alignment(5);
        set_name("gallant");
        set_id(({"gallant","bard","soldier"}));
          set_short("Gallant of the Order");
        set_race("half-elf");
        set_hd(random(12)+18,8);
        set_hp(6 * query_hd());
        set_level(query_hd());;
  	set_exp(1000 * query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("strength",18);
        set_stats("dexterity",18);
        set_long(
@VOID
%^CYAN%^Normally peacefull in nature, the Gallant enjoys playing
his lute, and performing for the royal court, but when angered his
rage can be horrid. Few live to tell the tale of when they crossed
a noble Gallant of the Order of the Metallic Dragons.
VOID
);
  	set_guild_level("mage",query_hd()-1);
  	set_spells(({"magic missile", "lightning bolt", "cone of cold", "fireball"}));
  	set_spell_chance(50);

        ob = new("/d/tharis/obj/white_robes");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear robes");

  	ob = new("/d/tharis/barrow/obj/slayer");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield slayer");

	set_overall_ac(0);
	ob = new("/d/dagger/westroad/items/armor/Mchain+1.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear chainmail");

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
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(50);

  	ob = new("/d/azha/obj/gmr_ring");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear ring");

  	set_mob_magic_resistance("average");
  	parties = ({});
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(!query_stoneSkinned() && skins){
    	new("/cmds/wizard/_stoneskin")->use_spell(TO,TO,query_level());
    	skins--;
  	}

  	if(present("snake",ETO)){
  		new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  	}
  	
  	if(!present(query_name()+" summoned",ETO)){
    	new("/cmds/wizard/_monster_summoning_iv")->use_spell(TO,0,query_level());
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


string query_type(){return "defender";}
string query_guild(){return "Order of Metallic Dragon";}
object *query_party(){return parties;}
int query_cost() { return 50000; }

void init(){
  object *stuff;
	::init();
	
  stuff = BAT_D->query_other_side(TO->query_guild());
  if(!wizardp(TP) && !TP->query_invis() && member_array(TP,stuff) != -1)
        TO->kill_ob(TP,1);
}

void attack(object ob){
        command("say I shall make the tale of your death a great one!");
	command("kill "+ob->query_name());
	new("/cmds/wizard/_wall_of_fire")->use_spell(TO,0,query_level());
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
GUILD_D->remove_defender(TO->query_guild(),base_name(TO));;
  break;
  ::die(ob);
}
}

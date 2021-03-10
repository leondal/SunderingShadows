// test thief monster

#include <std.h>
#include <daemons.h>
#define BAT_D "/realms/tristan/bat_d"
inherit MONSTER;

#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

string *races;
object *parties;

void makeMe();
void create(){
  object ob, ob2;
  	int i,j,k,num;
  	::create();
 	 set_class("thief");
  
        set_alignment(5);
       set_name("ninja");
       set_id(({"ninja"}));
       set_short("%^BLACK%^Silent Ninja%^RESET%^");
  	races = RACE_D->query_races();
 	races = races -  SHIT;
 	races = races - ({"firbolg","half-ogre","ogre","wemic"});
  	set_race(races[random(sizeof(races))]);
        set_hd(random(12)+18,8);
        set_hp(4 * query_hd());
  	set_exp(1000 * query_hd());
       set_level(query_hd());
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
        set_stats("strength",18);
        set_stats("dexterity",18);
        set_long(
@SEETH
%^BLACK%^The shadow figure before you is Lord Soth's personal assassins. If you can read this your lucky for now.
SEETH
);
	set_guild_level("thief",query_level());

        ob = new("/d/undead/tomb/obj/sickle3.c");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
        command("wield sickle");

  	set_overall_ac(0);
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
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_uses(50);
  	new("/d/tharis/obj/bpowder")->move(TO);

	ob = new("/d/tharis/obj/wrist_sheath");
        ob->set_property("monsterweapon",1);

        ob2 = new("/d/undead/tomb/obj/sickle3.c");
        ob->set_property("monsterweapon",1);
  ob2->set_size(1);
  ob2->move(ob);
  ob->move(TO);
  command("wear sheath");

  	set_mob_magic_resistance("average");
  	set_thief_skill("hide in shadows",95);
  	set_thief_skill("move silently",95);
  	add_search_path("/cmds/thief");
  	set_invis();
  	parties = ({});
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp()< 80 && present("vial",TO)){
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
        TO->kill_ob(TP,1);
}

void attack(object ob){
	command("stab "+ob->query_name());
	set_invis();
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
}

string query_guild(){return "Shades of Death";}
string query_type(){return "trooper";}
object *query_party(){return parties;}
int query_cost() {return 50000; }
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

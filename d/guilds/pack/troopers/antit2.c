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
       set_class("antipaladin");
       set_name("skeletal warrior");
       set_id(({"skeleton","skeletal warrior","warrior","Skeletal warrior","Skeletal Warrior","Skeleton","skeletal"}));
       set_short("%^BLUE%^Ominous Skeletal Warrior%^RESET%^");
       set_alignment(9);
  	set_race("human");
       set_hd(random(9)+31,8);
        set_hp(10 * query_hd());
       set_level(query_hd());
  	set_exp(1050 * query_hd());
  	set_body_type(query_race());
       set_gender("male");
        set_stats("strength",18);
        set_stats("dexterity",18);
    set_long(
@SEETH
%^BLUE%^Before you is one of Lord Soth's loyal skeletal warriors. He will kill any intruder upon his lord's lands.
SEETH
);
  	set_guild_level("cleric",query_hd()-9);
        set_spells(({"limb attack","call lightning"}));
  	set_spell_chance(20);

        ob = new("/d/tharis/barrow/obj/slayer");
        ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
        command("wield sword");

  	set_overall_ac(-3);

        ob = new("/d/dagger/marsh/tower/obj/unplate.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

        ob = new("/d/dagger/marsh/tower/obj/unshield.c");
        ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear shield");

        ob = new("/d/dagger/marsh/tower/obj/uncoif.c");
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
       if(present("corpse",ETO)){
       new("/cmds/priest/_animate_dead")->use_spell(TO,0,query_level());
       }
       if(present("snake",ETO)){
       new("/cmds/priest/_dispel_magic")->use_spell(TO,0,query_level());
       }
  	
  	if(query_hp() < 100 && healings){
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	healings--;
  	}
  
   
  	if(query_hp()< 70 && present("vial",TO)){
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
              TO->kill_ob(TP,1);
}

void attack(object ob){

        command("say You may take my life, but you shall never take this guild!");
	command("kill "+ob->query_name());
	
}

void horsey(){
       new("/d/guilds/pack/troopers/nightmare")->move(ETO);
	command("mount horse");
}
string query_guild(){return "Shades of Death";}
string query_type(){return "trooper";}
object *query_party(){return parties;}
int query_cost() {return 75000; }
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



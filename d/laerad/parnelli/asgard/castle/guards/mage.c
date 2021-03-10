//Coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit MONSTER;
object ob, him;
int stoned, done;
void create(){
    ::create();
    set_id(({"mage","royal mage","royal"}));
    set_name("royal mage");
    set_short("A royal mage");
    set_long(
	"This is the kings personal advisor.  He is a master of "+
	"the arcane arts and a very wise man.  He wears long "+
	"flowing robes and a black cap.  He looks rather young "+
	"for a mighty wizard."
    );
    set_body_type("human");
    set_race("elf");
    set_gender("male");
    set_size(2);
    set_class("mage");
    set_hd(35,5);
    set_hp(320);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_overall_ac(0);
    set_exp(17000);
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_guild_level("mage",35);
    set_alignment(1);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_spells( ({
	"magic missile",
	"lightning bolt",
	"fireball",
	"cone of cold",
	"prismatic spray",
	"powerword stun",
	"powerword kill",
	"vampiric touch",
	"meteor swarm",
    }) );
    set_wielding_limbs(({"right hand","left hand"}));
    ob = new("/realms/bane/closed/bracers8");
    ob->move(TO);
    if(random(10)) ob->set_property("monsterweapon",1);
    command("wear bracers");
    ob = new("/d/laerad/obj/tl_staff");
    ob->move(TO);
    if(random(10)) ob->set_property("monsterweapon",1);
    command("wield staff in right hand and left hand");
    stoned = 0;
    set_spell_chance(80);
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
        if((string)TP->query_race() == "human" || (string)TP->query_race() == "elf"
|| (string)TP->query_race() == "half-elf" || (string)TP->query_race() ==
"dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() ==
"halfling" || (string)TP->query_race() == "horse"){
	    return 1;
	}
   force_me("kill "+TPQN);
	return 1;
}
int kill_ob(object victim, int which){
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold){
	if(!query_stoneSkinned() && stoned < 5){
	    if(done) return 1;
	    new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,35,100,"mage");
	    stoned += 1;
	    done = 1;
	    call_out("remove_done",5);
	}
    }
}
void heart_beat(){
        ::heart_beat();
    if(!query_stoneSkinned() && stoned < 5){
	if(done) return 1;
	new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,35,100,"mage");
	stoned += 1;
	done = 1;
	call_out("remove_done",5);
    }
    if((object *)TO->query_attackers() == ({}) && query_hp() < query_max_hp()){
	TO->add_hp(1);
    }
    if((object *)TO->query_attackers() != ({})){
	him = TO->query_current_attacker();
	if(!random(10)){
	    switch(random(3)){
		case 0:
		    force_me("thunderclap "+(string)him->query_name());
		    break;
		case 1:
		    force_me("bolt "+(string)him->query_name());
		    break;
		case 2:
		    force_me("storm "+(string)him->query_name());
		    break;
	    }
	}
    }
    if(!present("wall of fire")){
	if((string *)TO->query_attackers() == ({})) return 1;
	if(done) return 1;
	new("/cmds/spells/w/_wall_of_fire")->use_spell(TO,0,35,100,"mage");
	done = 1;
	call_out("remove_done",5);
    }
    if((string *)TO->query_attackers() != ({})){
	if(OVER->query_alarm() == 0) OVER->sound_alarm(ETO);
    }
}
void reset(){
    ::reset();
    stoned = 0;
}
void remove_done(){
    done = 0;
}

//Coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/d/laerad/parnelli/systyquah/citadel/daemon/bane2.h"
inherit WEAPONLESS;
object ob, him;
int stoned, done;
void create(){
    ::create();
    set_id(({"wizard","troll","troll wizard","mage"}));
    set_name("troll wizard");
    set_short("A Troll Wizard");
    set_long(
	"This is a massive troll wizard. He stands tall draped in "+
	"flowing black robes. He is the personal advisor of the King "+
	"of Systyquah. An aura of power surrounds him, he is mighty indeed."
    );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(3);
    set_class("mage");
    set_hd(32,19);
    set_hp(275);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_overall_ac(-8);
    set_exp(0);
    set_stats("strength",19);
    set_stats("constitution",24);
    set_stats("dexterity",17);
    set_stats("charisma",5);
    set_guild_level("mage",32);
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
	"energy drain",
    }) );
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand"}));
    set_num_attacks(3);
    set_damage(1,4);
    ob = new("/d/laerad/obj/beads_f");
    ob->move(TO);
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
	    force_me("say ARGH!! DIE SCUM!");
      force_me("kill "+TPQN);
	    return 1;
	}
}
int kill_ob(object victim, int which){
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold){
	if(!query_stoneSkinned() && stoned < 5){
	    if(done) return 1;
	    new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,32,100,"mage");
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
	new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,32,100,"mage");
	stoned += 1;
	done = 1;
	call_out("remove_done",5);
    }
    if((object *)TO->query_attackers() != ({})){
	him = TO->query_current_attacker();
	if(!random(10)){
	    force_me("throw bead at "+(string)him->query_name());
	}
    }
    if(!present("wall of fire")){
	if((string *)TO->query_attackers() == ({})) return 1;
	if(done) return 1;
	new("/cmds/spells/w/_wall_of_fire")->use_spell(TO,TO,32,100,"mage");
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

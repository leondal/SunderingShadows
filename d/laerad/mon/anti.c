//updated by Circe to ignore true invis 5/21/04
//Coded by Bane//
// adding id of laeradmon & getting rid of the wander inherit to use normal wandering *Styx* 12/20/03, last change 8/7/02 (riding level?)

#include <std.h>
#include <daemons.h>
// object *attackers;  don't see this used so it's gone too *Styx*
// inherit "/d/laerad/mon/wander/wander4.c";
inherit MONSTER;

void create(){
    ::create();
    set_id(({"antipaladin","arganon", "laeradmon"}));
    set_name("arganon");
    set_short("Arganon the Antipaladin");
    set_long(
        "Arganon is the fabled Antipaladin Warlord of Laerad.  He wanders "+
        "the land vanquishing the good, bringing a tide of darkness with him "+
       "everywhere he goes.  Garbed in solid black armor and wielding a "+
       "sword of tremendous power he strikes terror into every adventurer "+
        "that crosses his path."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_no_moving();
    set_class("paladin");
    set_nwp("riding",20);
    set_diety("bane");
    set_mlevel("paladin",22);
    set_guild_level("cleric",22);
    set_hd(22,0);
    set_spell_chance(20);
    set_spells(({
        "limb attack",
        "call lightning",
        "cause serious wounds"
    }));
    set_mob_magic_resistance("average");
    set_property("alignment adjustment",9);
    set_overall_ac(0);
    set_property("no rush",1);
    set_property("no dominate",1);
    set_exp(15000);
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_guild_level("paladin",22);
    add_search_path("/cmds/paladin");
    set_alignment(3);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/laerad/obj/pallyplate")->move(TO);
    //if(random(10)) present("plate",TO)->set_property("monsterweapon",1);
    command("wear armor");
    new("/d/common/obj/armour/helm")->move(TO);
    command("wear helm");
    new("/d/laerad/obj/lstealer")->move(TO);
    command("wield sword");
     new("/d/laerad/obj/dlance")->move(TO);
      command("wield lance");
    new("/d/laerad/obj/javelin")->move(TO);
    new("/d/laerad/obj/javelin")->move(TO);
    set_funcs(({"insects","bolt"}));
    set_func_chance(25);
    set_property("full attacks",1);
    call_out("do_horse",1);
    set_moving(1);
    set_speed(30);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void init(){
    ::init();
    if(interactive(TP) && !TP->query_true_invis()){
    	if((string)TP->query_level() > 18 && (string)TP->query_level() < 500){
        	force_me("say AH! A real warrior to test my power!");
      force_me("kill "+TPQN);
    	}
    }
}
void heart_beat(){
    object atk;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(present("javelin")){
        if(random(20) < 1){
            if((atk = query_current_attacker())){
                command("throw javelin at "+atk->query_name());
                command("get javelin");
            }
        }
    }
    if(present("javelin")){
        force_me("get javelin");
    }

    if(present("corpse of silvim")){
        force_me("get corpse");
        force_me("offer corpse");
        force_me("offer star");
        force_me("say Evil will always triumph over good...");
        return 1;
    }
    if(present("star")){
        force_me("get star");
        force_me("offer star");
        force_me("say No weapon of good shall exist while I live...");
        return 1;
    }
}
void insects(){
    "cmds/spells/i/_insect_plague"->use_spell(TO,0,22,100,"cleric");
}
void bolt(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"spells")){
        tell_room(ETO,"Arganon holds his hands out in front of him.");
        tell_room(ETO,"A crackling black energy starts to form into a ball between his hands.");
        targ->set_paralyzed(15,"You are frozen in awe at Arganons display of power.");
        call_out("blast",10,targ);
        return 1;
    }
    tell_room(ETO,"Arganon tries vainly to summon an unearthly power.");
    return 1;
}
int blast(object targ){
     if(!objectp(targ)) return random(10);
    tell_object(targ,"A blast of raw black energy explodes from Arganon's hands enveloping you!");
    tell_room(ETO,"A blast of raw black energy explodes from Arganon's hands enveloping "+targ->query_cap_name()+"!",targ);
set_property("magic",1);
    targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
remove_property("magic");
    return 1;
}


void do_horse(){
	object horse;

	if(!objectp(ETO)) return;

	horse = new("/d/tharis/monsters/sksteed");
	horse->set_owner(TO);
	horse->move(ETO);
	command("mount horse");
}

int kill_ob(object victim, int which){
	int hold;

	hold = ::kill_ob(victim, which);
	if(!victim->query_true_invis()){
   	   if(hold){
	 	   command("sic "+victim->query_true_name());
	   }
      }
	return hold;
}

// int should_I_not_move() { return sizeof(TO->query_attackers()); }

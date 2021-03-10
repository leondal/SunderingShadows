//Coded by Bane//
//This isn't the current one and it looks like a mistake to be in this dir - Styx

#include <std.h>
#include <daemons.h>
inherit "/d/laerad/mon/wander/wander4.c";

object *attackers;

void create(){
    ::create();
    set_id(({"silvim","paladin"}));
    set_name("silvim");
    set_short("Sir Silvim the Paladin");
    set_long(
        "Silvim is a paladin on a very important quest.  It is his life "+
        "goal to vanquish evil from this land, and a most vile entity has been "
+
        "plaguing these lands, Arganon the Antipaladin!  Silvim is dressed in "+
        "silver fullplate armor and is wielding his trusty morning star.  "+
        "Beware to all evil, Silvim will not rest until you are destroyed!"
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(22,0);
    set_hp(220);
    set_guild_level("cleric",22);
    set_spell_chance(20);
    set_spells(({
        "limb attack",
        "call lightning",
        "flame strike"
    }));
    set_mob_magic_resistance("average");
    set_overall_ac(0);
    set_property("no rush",1);
    set_property("no dominate",1);
    set_exp(22000);
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_class("paladin");
    set_guild_level("paladin",22);
    add_search_path("/cmds/paladin");
    set_alignment(1);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/common/obj/armour/fullplate")->move(TO);
    command("wear armor");
    new("/d/common/obj/armour/helm")->move(TO);
    command("wear helm");
    new("/d/laerad/obj/sun_star")->move(TO);
    command("wield star");
    new("/d/laerad/obj/javelin")->move(TO);
    new("/d/laerad/obj/javelin")->move(TO);
    set_funcs(({"snakes","flare"}));
    set_func_chance(25);
    set_property("full attacks",1);
    call_out("do_horse",1);
}
void init(){
    ::init();
    if(interactive(TP) && !wizardp(TP) || (string)TP->query_name() =="arganon"){
    if((string)TP->query_alignment() == 9 || (string)TP->query_alignment() == 6 || (string)TP->query_alignment() == 3){
    if((string)TP->query_level() > 18){
        force_me("say Evil scum!  Taste my wrath!");
        force_me("kill "+TPQN);
    }
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
    if(present("corpse of arganon")){
        force_me("get corpse");
        force_me("offer corpse");
        force_me("offer stealer");
        force_me("say The world is rid of another evil...");
        return 1;
    }
    if(present("stealer")){
        force_me("get stealer");
        force_me("offer sword");
        force_me("say Be gone vile weapon!");
        return 1;
    }
}
void snakes(){
    "cmds/spells/s/_sticks_into_snakes"->use_spell(TO,0,22,100,"cleric");
}
void flare(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"spells")){
        tell_room(ETO,"Silvim holds his hands out in front of him.");
        tell_room(ETO,"A brilliant white energy starts to form into a ball between his hands.");
        targ->set_paralyzed(15,"You are frozen in awe at Silvim's display of power.");
        call_out("blast",10,targ);
        return 1;
    }
    tell_room(ETO,"Silvim tries vainly to summon a heavenly power.");
    return 1;
}
int blast(object targ){
    tell_object(targ,"A blast of pure white energy explodes from Silvim's hands enveloping you!");
    tell_room(ETO,"A blast of pure white energy explodes from Silvim's hands enveloping "+targ->query_cap_name()+"!",targ);
    targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
    return 1;
}

void do_horse(){
	object horse;
	
	if(!objectp(ETO)) return;
	
	horse = new("/d/tharis/monsters/wwhorse");
	horse->set_owner(TO);
	horse->move(ETO);
	command("mount horse");
}

int kill_ob(object victim, int which){
	int hold;
	
	hold = ::kill_ob(victim, which);
	
	if(hold){
		command("sic "+victim->query_true_name());
	} 
	return hold;
}

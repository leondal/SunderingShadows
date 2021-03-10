#include <std.h>
#include <daemons.h>

inherit NPC;
string *killers;

void create(){
    ::create();
    killers = ({});
    set_name("nixie");
    set_id(({"nixie","Nixie",}));
    set("short","Nixie, the thieves' receptionist");
    set_long(
@OLI
Of stunning beauty, this drow waits for you to do business. You need to 
have her register <register> you here in order to do business and partake of the 
benefits of the guild.
OLI
    );
    set_race("drow");
    set_gender("female");
    set_class("thief");
     set_nwp("concealment",15);
    set_hd(19,1);
    set_hp(200);
    set_exp(5000);
    set_body_type("human");
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/deku/weapons/dagger2")->move(TO);
    command("wield dagger in right hand");
    new("/d/deku/weapons/dagger2")->move(TO);
    command("wield dagger in left hand");
}

void init(){
    ::init();
    add_action("register","register");
}

int register(){
    killers = SAVE_D->query_array("tharis_killers");
    if(member_array(TPQN,killers) != -1) return notify_fail("Your crimes here have made you unwelcome!\n");

    if(TP->query_money("gold") < 10000) return notify_fail("I'm sorry You need 10000 gold to enter.\n");

    if(environment(TO)->add_member(TPQN)){
	TP->add_money("gold",-10000);
	write("%^BOLD%^%^RED%^Welcome to the guild. You will find many useful items in the shop.");
	return 1;
    }else
	notify_fail("You have no need to register. You already a member silly\n");
}

int kill_ob(object victim, int which){
    int hold;
    killers = SAVE_D->query_array("tharis_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(TPQN, killers) != -1) return hold;
    SAVE_D->set_value("tharis_killers", TPQN);
    environment(TO)->remove_member(TPQN);
    return hold;
}


void remove_name(string name){
    SAVE_D->remove_name_from_array("tharis_killers", name);
}

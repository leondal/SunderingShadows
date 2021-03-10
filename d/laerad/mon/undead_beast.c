//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit "/d/laerad/mon/wander/swwander2.c";
void cage(object targ, int num);
void create(){
    ::create();
    set_id(({"beast","Undead Beast"}));
    set_name("Undead Beast");
    set_short("An Undead Beast");
    set_long(
	"The size of a small dragon, the beasts bones protrude "+
	"from rotting flesh. It has a great horned head, and its "+
	"ribs are bare and barbed, forming a nasty cage. It walks "+
	"on all fours, but can rear up on its hind legs, balancing "+
	"with its stubby tail. Its forearms end in massive claws "+
	"capable of rending to pieces most living creatures."
    );
    set_body_type("quadruped");
    set_race("undead beast");
    set_gender("male");
    set_alignment(9);
    set_size(3);
    set_hd(12,34);
    set_hp(130);
    set_mob_magic_resistance("average");
    set_property("alignment adjustment",4);
    set_property("swarm",1);
    set_stats("strength",14);
    set_stats("dexterity",14);
    set_exp(3000);
    set_overall_ac(5);
    set_property("undead", 1);
    set("aggressive",19);
    set_attack_bonus(1);
    set_wielding_limbs(({"right forepaw","left forepaw","head"}));
    new("/d/laerad/mon/obj/ubclaw")->move(this_object());
    command("wield claw in right forepaw");
    new("/d/laerad/mon/obj/ubclaw")->move(this_object());
    command("wield claw in left forepaw");
    new("/d/laerad/mon/obj/ubhorns")->move(this_object());
    command("wield horn in head");
    set_funcs(({"trample"}));
    set_func_chance(30);
}
void trample(object targ){
    int roll, ac;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 10-ac){
	tell_object(targ,"%^BOLD%^RED%^The Undead Beast charges towards you and tramples you underneath it!");
	tell_room(ETO,"%^BOLD%^RED%^The Undead Beast charges towards "+targ->query_cap_name()+" and tramples "+targ->query_objective()+" underneath it!",targ);
	if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	    targ->do_damage("torso",roll_dice(3,8));
	    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
		tell_object(targ,"%^BOLD%^RED%^You are ensnared in the Beasts rib cage!");
		tell_room(ETO,"%^BOLD%^RED%^"+targ->query_cap_name()+" is ensnared in the Beasts rib cage!",targ);
		set_func_chance(0);
		cage(targ,0);
	    }
	    return 1;
	}
	targ->do_damage("torso",roll_dice(1,8));
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Undead Beast charges at you and runs right past!");
    tell_room(ETO,"%^BOLD%^RED%^The Undead Beast charges at "+targ->query_cap_name()+" and runs right past!",targ);
    return 1;
}
void cage(object targ, int num){
    switch( num ){
	case(0):
	tell_object(targ,"The Undead Beasts ribs tear into you!");
	tell_room(ETO,""+targ->query_cap_name()+" struggles inside the Undead Beasts rib cage!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
	break;
	case(1):
	tell_object(targ,"The Undead Beasts ribs tear into you!");
	tell_room(ETO,""+targ->query_cap_name()+" struggles inside the Undead Beasts rib cage!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
	break;
	case(2):
	tell_object(targ,"The Undead Beasts ribs tear into you!");
	tell_room(ETO,""+targ->query_cap_name()+" struggles inside the Undead Beasts rib cage!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
	break;
	case(3):
	tell_object(targ,"The Undead Beasts ribs tear into you!");
	tell_room(ETO,""+targ->query_cap_name()+" struggles inside the Undead Beasts rib cage!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
	break;
	case(4):
	tell_object(targ,"The Undead Beasts ribs tear into you!");
	tell_room(ETO,""+targ->query_cap_name()+" struggles inside the Undead Beasts rib cage!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
	tell_object(targ,"You fall from the Beast's ribs.");
	tell_room(ETO,""+targ->query_cap_name()+" falls from the Beast's ribs.",targ);
    	set_func_chance(30);
	return;
    }
    num++;
    call_out("cage",8,targ,num);
    return;
}

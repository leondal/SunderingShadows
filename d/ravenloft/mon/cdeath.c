//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
int num=0;
void telekinetic(object targ);
void create(){
    ::create();
    set_id(({"death","Crimson Death","Death"}));
    set_name("Crimson Death");
    set_short("A Crimson Death");
    set_long(
	"The Crimson Death is a vaporous humanoid shaped creature "+
	"of pale color. Its body swirls in a hypnotic dance of "+
	"horror. A wicked grin decorates the face of the beast. "+
	"Its fingers elongate into claws and he hovers towards you."
    );
    set_body_type("undead");
    set_race("crimson death");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(15,40);
    set_property("magic",1);
    set_property("swarm",1);
    set_hp(160);
    set_stats("strength",12);
    set_stats("dexterity",12);
    set_exp(6500);
    set_overall_ac(-1);
    set("aggressive",19);
    set_attack_limbs(({"right hand"}));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(3,10);
    set_attack_bonus(5);
    set_funcs(({"lift"}));
    set_func_chance(30);
}
void lift(object targ){
    int roll, ac;
    roll=random(20);
    ac=targ->query_ac();
    if(roll > 10-ac){
	tell_object(targ,"%^BOLD%^RED%^The Crimson Death starts to lift you off of the ground!");
	tell_room(ETO,"%^BOLD%^RED%^The Crimson Death starts to lift "+targ->query_cap_name()+" off of the ground!",targ);
	targ->set_paralyzed(300,"You are being held stiff.");
	telekinetic(targ);
	set_func_chance(0);
	return 1;
    }
}
void telekinetic(object targ){
    int roll, ac;
    num++;
    roll=random(20);
    ac=targ->query_ac();
    if(find_call_out("do_damages") != -1) return 1;
    if(find_call_out("telekinetic") != -1) return 1;
    switch( num ){
   	case(1):
	if(roll < 10-ac){
	    call_out("do_damages",9,targ,1);
	    return;
	    break;
	}
	tell_object(targ,"%^BOLD%^RED%^The Crimson Death raises you higher into the air!");
	tell_room(ETO,"%^BOLD%^RED%^The Crimson Death raises "+targ->query_cap_name()+" higher into the air!",targ);
	call_out("telekinetic",9,targ);
	return;
	case(2):
	if(roll < 10-ac){
	    call_out("do_damages",9,targ,2);
	    return;
	    break;
	}
	tell_object(targ,"%^BOLD%^RED%^The Crimson Death lifts you dangerously higher!");
	tell_room(ETO,"%^BOLD%^RED%^The Crimson Death lifts "+targ->query_cap_name()+" dangerously higher!",targ);
	call_out("telekinetic",9,targ);
	return;
	case(3):
	if(roll < 10-ac){
	    call_out("do_damages",9,targ,3);
	    return;
	    break;
	}
	tell_object(targ,"%^BOLD%^RED%^The Crimson Death lifts you way up into the air!");
	tell_room(ETO,"%^BOLD%^RED%^The Crimson Death lifts "+targ->query_cap_name()+" way up into the air!",targ);
	call_out("telekinetic",9,targ);
	break;
	default:
	call_out("do_damages",9,targ,4);
	return;
    }
}
void do_damages(object targ){
    if(num > 4) num=4;
	tell_object(targ,"%^BOLD%^RED%^The Crimson Death drops you to the ground!");
	tell_room(ETO,"%^BOLD%^RED%^The Crimson Death drops "+targ->query_cap_name()+" to the ground!",targ);
	targ->cause_typed_damage(targ, "torso", roll_dice(num, 6), "bludgeoning");
	targ->remove_paralyzed();
	set_func_chance(20);
    num=0;
}

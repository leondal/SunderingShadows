//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"stinger"}));
    set_name("Cildabrin's stinger");
    set_short("Cildabrin's stinger");
    set_long("A nasty scorpion stinger from a Cildabrin.");
    set_weight(10);
    set_size(2);
    set_value(0);
    set_wc(1,6);
    set_large_wc(1,6);
    set_type("piercing");
    set_property("monsterweapon",1);
    set_hit( (:TO,"poison":) );
}
int poison(object targ){
    if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"You are poisoned badly.");
	targ->do_damage("torso",roll_dice(1,10));
	targ->add_poisoning(10);
	return 1;
    }
    return 1;
}

//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"claw"}));
    set_name("Undead Beast's claw");
    set_short("Undead Beast's claw");
    set_long("A wicked claw from an Undead Beast.");
    set_weight(10);
    set_size(2);
    set("value",1);
    set_wc(3,3);
    set_large_wc(3,3);
    set_type("slashing");
    set_property("monsterweapon",1);
    set_hit( (:TO,"fling":) );
}
void fling(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^RED%^You are flung backwards by the strength of the Undead Beast!");
	tell_room(environment(targ),"%^BOLD%^RED%^"+targ->query_cap_name()+" is flung backwards by the strength of the Undead Beast!",targ);
	targ->do_damage("torso",roll_dice(1,20));
	return 1;
    }
    return 0;
}

//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"teeth"}));
    set_name("Thri-Kreen's teeth");
    set_short("Thri-Kreen's teeth");
    set_long("The teeth from a noble Thri-Kreen.");
    set_weight(5);
    set_size(2);
    set("value",1);
    set_wc(1,4)+1;
    set_large_wc(1,4)+1;
    set_type("piercing");
    set_property("monsterweapon",1);
    set_hit( (:TO,"poison":) );
}
void poison(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Thri-kreen's poison paralyzes you!");
	tell_room(ETO,"%^BOLD%^BLUE%^The Thri-kreen's bite paralyzes "+targ->query_cap_name()+"!",targ);
	targ->set_paralyzed(50,"The poison holds you tight.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^BLUE%^The Thri-Kreen's poison burns through your veins!");
    tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" winces at the Thri-Kreen's bite!",targ);
    return 1;
}

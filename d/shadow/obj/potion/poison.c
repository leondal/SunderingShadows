#include <std.h>
#define SAVE_D "/daemon/saving_d.c"
inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a brown potion") ;
    set_long("The brown potion swirls in the crystal vial.\n") ;
    set ("color", "brown") ;
    set ("effect_time", 0) ;
}

int do_effect() {
    	tell_object(drinker,"Suddenly, you begin to feel strange.\n") ;
	if(!(SAVE_D->saving_throw(TP,"paralyzation_poison_death"))){
	    	tell_object(drinker,"Suddenly, you begin to feel strange.\n") ;
    		tell_object(drinker,"You have been poisoned!.\n") ;
	    	drinker->add_poisoning(random(20));
    	} else
	    	tell_object(drinker,"You resisted the potion!\n") ;
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

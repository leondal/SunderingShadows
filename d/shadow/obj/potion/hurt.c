#include <std.h>
#define SAVE_D "/daemon/saving_d.c"
inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a cyan potion") ;
    set_long("The cyan potion swirls in the crystal vial.\n") ;
    set ("color", "cyan") ;
    set ("effect_time", 0) ;
}

int do_effect() {
  int healing;
	if(!(SAVE_D->saving_throw(drinker,"paralyzation_poison_death"))){
    	healing = random(4) + random(4) + 2;
    	tell_object(drinker,"Suddenly, you begin to feel worse.\n") ;
    	tell_object(drinker,"You have lost "+healing+" hit points.\n") ;
    	drinker->add_hp(-healing);
    } else {
    	tell_object(drinker,"You feel no different then before.\n") ;
    }
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

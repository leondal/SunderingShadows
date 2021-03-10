#include <std.h>
#define SAVE_D "/daemon/saving_d.c"

inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a purple potion") ;
    set_long("The purple potion swirls in the crystal vial.\n") ;
    set ("color", "purple") ;
    set ("effect_time", 0) ;
}

int do_effect() {
    int length;
	if(!SAVE_D->saving_throw(TP,"paralyzation_poison_death")){
		length = (random(6)+random(6))*60;
	    	tell_object(drinker,"Suddenly, you begin to feel strange.\n") ;
	    	tell_object(drinker,"You have been paralyzed!.\n") ;
    		drinker->set_paralyzed(length,"Nothing seems to work for you, except your mind!");
    	} else
	    	tell_object(drinker,"You resisted the potion!\n") ;
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

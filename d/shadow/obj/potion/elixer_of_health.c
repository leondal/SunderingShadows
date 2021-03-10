#include <std.h>
inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a dull white potion") ;
    set_long("The dull white potion swirls in the crystal vial.\n") ;
    set ("color", "dull white") ;
    set ("effect_time", 0) ;
}

int do_effect() {
  int temp;
	temp = drinker->query_poisoning();
	if(temp > 0){
		drinker->add_poisoning(-temp);
		tell_object(drinker,"You are no longer poisoned.\n") ;
	}
	else
		tell_object(drinker,"Nothing happens!\n") ;
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

//retiring these versions to avoid problems with them being out of date
//DO NOT USE!!!  Use potions from /d/common/obj/potion/...  *Styx*  2/24/02

#include <std.h>

inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a blue potion") ;
    set_long("The blue potion swirls in the crystal vial.\n") ;
    set ("color", "blue") ;
    set_value(1000);
}

int do_effect() {
    	set ("effect_time", (random(4) * 60)) ;
	drinker->set_invis();
    	return 1 ;
}

int do_wear_off() {
	drinker->set_invis();
    return 1 ;
}

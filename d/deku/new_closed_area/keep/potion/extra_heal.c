//retiring these versions to avoid problems with them being out of date
//DO NOT USE!!!  Use potions from /d/common/obj/potion/...  *Styx*  2/24/02


#include <std.h>
inherit POTION;

void create() {
    ::create() ;
    set_name("extra_heal");
    set_short("A vial containing a bright white potion") ;
    set_long("The white potion swirls in the crystal vial.\n") ;
    set ("color", "bright white") ;
    set ("effect_time", 0) ;
    set_value(150);
}

int do_effect() {
  int healing;
    if(drinker->query_hp() < drinker->query_max_hp()){
	healing = random(8) + random(8) + random(8) + 3;
        tell_object(drinker,"Suddenly, you begin to feel better.\n") ;
        tell_object(drinker,"You have gained back "+healing+" hit points.\n") ;
        drinker->add_hp(healing);
    } else {
        tell_object(drinker,"You feel no different then before.\n") ;
    }
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

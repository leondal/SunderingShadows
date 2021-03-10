//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
// added an effect time so the destruct would kick in *Styx* 1/3/06

#include <std.h>
#define SAVE_D "/daemon/saving_d.c"
inherit POTION;

void create() {
    ::create();
    add_id("poison");
    add_id("vial of poison");
    add_id("brown potion");
    add_id("brown");
    set_obvious_short("%^ORANGE%^A vial containing a brown "+
       "potion%^RESET%^");
    set_short("%^ORANGE%^A vial of poison%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^RESET%^%^ORANGE%^brown potion %^CYAN%^"+
       "that swirls inside.") ;
    set_lore("Not a potion, exactly, the substance in this vial is "+
       "instead an intense toxin distilled from one of many animals "+
       "in the land.  Often used by assassins, tools such as this "+
       "sometimes fall into the wrong hands and accidental deaths "+
       "have been known to occur by those drinking what they thought "+
       "was a harmless tea.");
    set_property("lore difficulty",12);
    set ("color", "brown") ;
    set ("effect_time", 3) ;
    set_value(50);
    set_weight(1);
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

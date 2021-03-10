#include <std.h>
#define SAVE_D "/daemon/saving_d.c"

inherit POTION;

int st,in,wi,de,co,ch;
int resist;

void create() {
    ::create() ;
    set_short("A vial containing a dull red potion") ;
    set_long("The dull red potion swirls in the crystal vial.\n") ;
    set ("color", "dull red") ;
}

int do_effect() {
	if(!(SAVE_D->saving_throw(drinker,"paralyzation_poison_death"))){
	    	tell_object(drinker,"Suddenly, you begin to feel strange.\n") ;
    		tell_object(drinker,"You have been weakened!.\n") ;
            st = drinker->query_base_stats("strength");
            in = drinker->query_base_stats("intelligence");
           wi = drinker->query_base_stats("wisdom");
            de = drinker->query_base_stats("dexterity");
             co = drinker->query_base_stats("constitution");
            ch = drinker->query_base_stats("charisma");
	    	drinker->add_stat_bonus("strength",-(st/2));
	    	drinker->add_stat_bonus("intelligence",-(in/2));
	    	drinker->add_stat_bonus("wisdom",-(wi/2));
	    	drinker->add_stat_bonus("dexterity",-(de/2));
	    	drinker->add_stat_bonus("constitution",-(co/2));
	    	drinker->add_stat_bonus("charisma",-(ch/2));
                    set ("effect_time",60);
		resist = 0;    
	} else {
                set ("effect_time",1);
		tell_object(drinker,"You resisted the potion!\n") ;
		resist = 1;
   	}
    return 1 ;
}

int do_wear_off() {
    if(!resist){
    	tell_object(drinker,"Suddenly, you begin to feel better.\n") ;
           drinker->add_stat_bonus("strength",(st/2));
           drinker->add_stat_bonus("intelligence",(in/2));
         drinker->add_stat_bonus("wisdom",(wi/2));
           drinker->add_stat_bonus("dexterity",(de/2));
           drinker->add_stat_bonus("constitution",(co/2));
           drinker->add_stat_bonus("charisma",(ch/2));
    } 
    return 1 ;
}

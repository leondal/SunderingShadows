//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
//added weight & value *Styx* 12/05
#include <std.h>
#define SAVE_D "/daemon/saving_d.c"

inherit POTION;

int st,in,wi,de,co,ch;
int resist;

void create() {
    ::create() ;
    add_id("potion of weakness");
    add_id("dull red potion");
    add_id("dull red");
    set_obvious_short("%^RED%^A vial containing a dull red "+
       "potion%^RESET%^");
    set_short("%^RED%^Potion of Weakness%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^RESET%^%^RED%^dull red potion %^CYAN%^"+
       "that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to weaken someone.");
    set_property("lore difficulty",12);
    set ("color", "dull red") ;
    set_weight(1);
    set_value(20);
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

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#define SAVE_D "/daemon/saving_d.c"

inherit POTION;

void create() {
    ::create() ;
    add_id("potion of paralyzation");
    add_id("purple potion");
    add_id("purple");
    set_obvious_short("%^MAGENTA%^A vial containing a purple "+
       "potion%^RESET%^");
    set_short("%^MAGENTA%^Potion of Paralyzation%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^RESET%^%^MAGENTA%^purple potion "+
       "%^CYAN%^that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to paralyze someone.");
    set_property("lore difficulty",12);
    set ("color", "purple") ;
    set ("effect_time", 0) ;
    set_value(30);
    set_weight(1);
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

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

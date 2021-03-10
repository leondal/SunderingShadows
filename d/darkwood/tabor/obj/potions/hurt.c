//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#define SAVE_D "/daemon/saving_d.c"
inherit POTION;

void create() {
    ::create() ;
   add_id("cyan potion");
   add_id("hurt");
    add_id("cyan");
    set_obvious_short("%^RESET%^%^CYAN%^A vial containing a "+
       "cyan potion%^RESET%^");
    set_short("%^CYAN%^Potion of Harm%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^BOLD%^cyan potion %^RESET%^%^CYAN%^"+
       "that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to harm someone.");
    set_property("lore difficulty",12);
    set ("color", "cyan") ;
    set ("effect_time", 0) ;
   set_value(400);
    set_weight(1);
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

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

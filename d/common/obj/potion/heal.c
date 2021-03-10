//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
inherit POTION;

void create() {
    ::create();
    add_id("potion of cure light wounds");
    add_id("white potion");
    add_id("white");
    set_obvious_short("A vial containing a white potion") ;
    set_short("%^BOLD%^Potion of Cure Light Wounds%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^RESET%^white potion %^CYAN%^"+
       "that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to cure some wounds.");
    set_property("lore difficulty",12);
    set ("color", "white") ;
    set ("effect_time", 0) ;
    set_value(50);
    set_weight(1);
}

int do_effect() {
  int healing;
    if(drinker->query_hp() < drinker->query_max_hp()){
    	healing = random(4) + random(4) + 2;
    	tell_object(drinker,"Suddenly, you begin to feel better.\n") ;
    	tell_object(drinker,"You have gained back "+healing+" hit points.\n") ;
    	drinker->add_hp(healing);
    } else {
    	tell_object(drinker,"You feel no different than before.\n") ;
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

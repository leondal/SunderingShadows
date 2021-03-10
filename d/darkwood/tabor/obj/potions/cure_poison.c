//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
inherit POTION;

void create() {
    ::create() ;
    set_name("cure_poison");
    add_id("cure poison");
    add_id("cure poison potion");
   add_id("dull white potion");
   add_id("cure poison");
    set_obvious_short("A vial containing a dull white potion") ;
    set_short("Antidote");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^RESET%^dull white potion %^CYAN%^"+
       "that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to cure poison.");
    set_property("lore difficulty",12);
    set ("color", "dull white") ;
    set ("effect_time", 0) ;
   set_value(600);
    set_weight(1);
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

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>

inherit POTION;

void create() {
    ::create() ;
    add_id("potion of cure blindness");
    add_id("bright cyan potion");
    add_id("cyan");
    add_id("bright cyan");
    set_obvious_short("A vial containing a %^BOLD%^%^CYAN%^bright "+
       "cyan potion%^RESET%^") ;
    set_short("%^BOLD%^%^CYAN%^Potion of Cure "+
       "Blindness%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^BOLD%^%^CYAN%^bright cyan potion "+
       "%^RESET%^%^CYAN%^that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to cure blindness.");
    set_property("lore difficulty",12);
    set ("color", "bright cyan") ;
   set_value(500);
    set_weight(1);
}

int do_effect() {
  object spellob;
   spellob=new("/cmds/spells/r/_remove_blindness");
   spellob->set_silent_casting(1);
   spellob->set_cast_string("");
   spellob->use_spell(drinker,drinker,(random(3)+random(3)+5),100,"cleric");
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

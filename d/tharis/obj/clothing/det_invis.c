//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>

inherit POTION;

void create() {
    ::create() ;
    add_id("green potion");
    add_id("bright green potion");
    add_id("green");
    add_id("bright green");
    set_obvious_short("A vial containing a %^BOLD%^%^GREEN%^bright "+
       "green potion%^RESET%^") ;
    set_short("%^BOLD%^%^GREEN%^Potion of Detect "+
       "Invisibility%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^BOLD%^%^GREEN%^bright green potion "+
       "%^RESET%^%^CYAN%^that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to detect invisibility.");
    set_property("lore difficulty",12);
    set ("color", "bright green") ;
}

int do_effect() {
  object spellob;
   spellob=new("/cmds/spells/d/_detect_invisibility");
//neither of below is working to suppress the casting message but should?
   spellob->set_silent_casting(1);
   spellob->set_cast_string("");
   spellob->use_spell(drinker,drinker,(random(8)+random(5)+8),100,"mage");
   spellob->potion_dest_effect((random(10)+5) * 60);
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

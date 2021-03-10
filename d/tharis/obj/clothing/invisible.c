//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>

inherit POTION;

void create() {
    ::create() ;
    set_obvious_short("%^BOLD%^%^BLUE%^A vial containing a "+
       "blue potion%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^Potion of Invisibility%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This smooth %^BOLD%^crystal vial "+
       "%^RESET%^%^CYAN%^is rather small and tear-drop shaped.  "+
       "It is completely %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^, "+
       "allowing you to see a %^BOLD%^%^BLUE%^blue potion %^RESET%^"+
       "%^CYAN%^that swirls inside.") ;
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to make someone "+
       "invisible.");
    set_property("lore difficulty",12);
    set ("color", "blue") ;
}

int do_effect() {
  object spellob;
    	set ("effect_time", (random(4) * 60)) ;
//	drinker->set_invis();
   spellob=new("/cmds/spells/i/_invisibility");
   spellob->use_spell(drinker,drinker->query_name(),(random(5)+random(5)+12),100,"mage");
   spellob->potion_dest_effect((random(4)+2) * 60);
    	return 1 ;
}

int do_wear_off() {
//	drinker->set_invis();
    return 1 ;
}

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

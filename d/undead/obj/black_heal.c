//updated with lore by Circe 5/24/04
#include <std.h>
#include "../undead.h"

inherit POTION;

void create() 
{
    ::create() ;
    set_obvious_short("%^BOLD%^%^BLACK%^A vial containing a vile "
       "black potion%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Potion of Minotaur Health%^RESET%^");
    set_long("%^RED%^The black potion froths in its glass vial.\n");
    set_weight(5);
    set("color","black");
    set("effect_time", 50) ;
    set_lore("This strange potion is said to be distilled from the "
       "blood of a minotaur.  Granted with amazing natural healing, "
       "minotaurs are known for their health and vigor.  Strange, "
       "though, that you would find a potion like this, as "
       "minotaurs are known to be extremely rare.");
    set_property("lore difficulty",12);
}

int do_effect() 
{
    if(!objectp(drinker)) { return 1; }
    tell_object(drinker,"%^GREEN%^You choke down the vile black potion.");
    if(drinker->query_hp() > drinker->query_max_hp())
    {
        tell_object(drinker,"You feel no different than before.");
    }
    else
    {
    tell_object(drinker,"Suddenly, you begin to feel better.\n") ;
    drinker->set_hp(drinker->query_hp() + 100); 
    }
    return 1 ;
}

int do_wear_off() { return 1; }

int isMagic()
{
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

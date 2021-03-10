#include <std.h>
#include "../tecqumin.h"
#define SAVE_D "/daemon/saving_d.c"

inherit POTION;

void create() {
    ::create() ;
    add_id("draught of flowers");
    add_id("pink potion");
    add_id("purple");
    set_obvious_short("%^BOLD%^%^MAGENTA%^A vial containing a pink "+
       "potion");
    set_short("%^BOLD%^%^MAGENTA%^Dr%^BOLD%^%^CYAN%^a"
      +"%^BOLD%^%^MAGENTA%^ught %^YELLOW%^of%^BOLD%^%^MAGENTA%^"
      +" Flow%^BOLD%^%^CYAN%^e%^BOLD%^%^MAGENTA%^rs");
    set_long("This smooth crystal vial "+
       "is rather small and tear-drop shaped.  "+
       "It is completely clear, "+
       "allowing you to see a%^BOLD%^%^MAGENTA%^ pink potion "+
       "%^RESET%^that swirls inside.") ;
    set_lore("The %^BOLD%^%^MAGENTA%^Dr%^BOLD%^%^CYAN%^a"
      +"%^BOLD%^%^MAGENTA%^ught %^YELLOW%^of%^BOLD%^%^MAGENTA%^"
      +" Flow%^BOLD%^%^CYAN%^e%^BOLD%^%^MAGENTA%^rs %^RESET%^ is a" 
      +" legendary creation of the priesthood of the%^CYAN%^"
      +" Tecqumin%^RESET%^. They used it to induce a state of"
      +" blissful acquiescence in those who were to be sacrificed to"
      +" the Gods. Once imbibed, it will cause the drinker to become"
      +" compliant with any command they hear. Every command the"
      +" drinker hears will extend the effect.\n"
      +"OOC: To give a command, say what you want the drinker to do,"
      +" prefacing it with the drinker's name followed by a comma."
      +" For example, if you say 'Simnel, wield sword', Simnel will"
      +" enter <wield sword> as a command. In between responding to"
      +" commands, the drinker will be paralyzed until the draught"
      +" wears off.");
    set_property("lore difficulty",25);
    set ("color", "pink") ;
    set ("effect_time", 0) ;
    set_value(3000);
    set_weight(1);
}

int do_effect() {
    object followmob;
    int length;
        if(!SAVE_D->saving_throw(TP,"paralyzation_poison_death")){
                length = 500 * (1+ random(3));
                tell_object(drinker,"Suddenly, you begin to feel"
                  +" strange. Good, but strange.\n") ;
                tell_object(drinker,"A feeling of euphoria drifts"
                 +" over you. You don't feel like moving, or"
                 +" doing anything\n") ;
                drinker->set_paralyzed(length,"You feel dreamy,"
                  +" listless and unmotivated");
                drinker->set_property("compliant", 1);
        } else
                tell_object(drinker,"You resisted the potion!"
                  +" Nothing to stop you pretending it worked,"
                  +" though, if you know what it does.\n") ;
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

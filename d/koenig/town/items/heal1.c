#include <std.h>
inherit POTION;

void create() {
    ::create() ;
   set_name("healing potion plus");
   set_obvious_short("%^BOLD%^%^WHITE%^A %^BOLD%^%^RED%^p%^RESET%^%^ORANGE%^ri%^BOLD%^s%^GREEN%^m%^BLUE%^a%^MAGENTA%^t%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^c %^MAGENTA%^p%^BLUE%^o%^GREEN%^t%^ORANGE%^i%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^n%^RESET%^");
   set_short("%^BOLD%^%^RED%^Strong%^RESET%^%^ORANGE%^ healing potion%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A %^BOLD%^%^RED%^p%^RESET%^%^ORANGE%^ri%^BOLD%^s%^GREEN%^m%^BLUE%^a%^MAGENTA%^t%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^c %^MAGENTA%^p%^BLUE%^o%^GREEN%^t%^ORANGE%^i%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^ swirls inside the glass vial.%^RESET%^");
   set_lore("You seem to recall this particular potion having strong healing properties.");
   set ("color", "glowing rainbow");
    set ("effect_time", 0);
   set_value(50);
  set_weight(2);  // added by Styx 6/21/03, thanks to a bug report telling us
}

int do_effect() {
  int healing;
    if(drinker->query_hp() < drinker->query_max_hp()){
        healing = random(10) + random(10) + random(10) + 5;
        tell_object(drinker,"Suddenly, you begin to feel better.\n") ;
        tell_object(drinker,"You have gained back "+healing+" hit points.\n") ;
        drinker->add_hp(healing);
    } else {
        tell_object(drinker,"You feel no different then before.\n") ;
    }
    return 1 ;
}

int do_wear_off() {
    return 1 ;
}

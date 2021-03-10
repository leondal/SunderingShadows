#include <std.h>
inherit POTION;

void create() {
    ::create() ;
    set_short("A vial containing a dull green potion");
    set_long("The dull green potion swirls in the crystal vial.\n");
    set ("color", "green");
    set ("effect_time", 0) ;
}

int do_effect() {
  int speed;
    tell_object(drinker,"%^GREEN%^Your inards feel as if they are about to explode!%^RESET%^\n");
    tell_object(drinker,"%^GREEN%^%^BOLD%^Suddenly the pain receds and you feel hastened in your attacks%^RESET%^\n");
    call_out("attack",1);
    call_out("attack",25);
    return 1;
}

int do_wear_off() {
    return 1 ;
}

int attack(){
   drinker->execute_attack();
   return 1;
}

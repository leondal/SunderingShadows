#include "../brew.h"
inherit BREWPOTION;

void create() {
    ::create();
    set_property("instant potion",1);
}

int potion_effect(object drinker,int mystrength,string str) {
    ::potion_effect(drinker,mystrength,str);
    if(drinker->query_blind()) {
      drinker->set_blind(0);
      drinker->set_temporary_blinded(0);
      tell_object(drinker,"%^CYAN%^The fog clears from your eyes and the world reappears before you in stark detail.%^RESET%^");
    }
    else tell_object(drinker,"%^GREEN%^The potion seems to have no effect.%^RESET%^");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    int howblind;
    ::potion_backfire(drinker,mystrength,str);
    tell_object(drinker,"%^GREEN%^Your eyes only seem to grow cloudier.%^RESET%^");
    howblind = (int)drinker->query_temporary_blinded();
    howblind = howblind + roll_dice(1,2);
    drinker->set_temporary_blinded(howblind);
    return 1;
}
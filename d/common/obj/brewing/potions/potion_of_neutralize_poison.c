#include <daemons.h>
#include "../brew.h"
inherit BREWPOTION;

void create() {
    ::create();
    set_property("instant potion",1);
}

int potion_effect(object drinker,int mystrength,string str) 
{
    int temp;
    string *tmp;
    ::potion_effect(drinker,mystrength,str);
    temp = POISON_D->is_poisoned(drinker);
    if(temp > 0) 
    {
        tmp = POISON_D->clear_poisons_by_dc(drinker,mystrength);
        if(!tmp) 
        { 
            tell_object(drinker,"%^GREEN%^The potion seems to have no effect.%^RESET%^");
            return 1;
        }
        tell_object(drinker,"%^CYAN%^The insidious poison surging through your veins fades and is gone.%^RESET%^");
        return 1;
    }
    tell_object(drinker,"%^GREEN%^The potion seems to have no effect.%^RESET%^");
    return 1 ;
}

int potion_backfire(object drinker,int mystrength,string str) {
    ::potion_backfire(drinker,mystrength,str);
    tell_object(drinker,"%^GREEN%^The potion seems to have no effect.%^RESET%^");
    return 1;
}
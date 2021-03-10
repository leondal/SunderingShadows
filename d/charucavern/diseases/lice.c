#include <std.h>
#include <daemons.h>

inherit "/d/charucavern/diseases/disease_inherit";

void create()
{
    ::create();
    add_disease_effect((["damage" : roll_dice(2,10)]), -1);
    add_disease_effect((["exhaustion" : roll_dice(1,10)]), 1);
//    add_disease_effect((["paralyze" : roll_dice(1,10)]), -1);
    set_disease_name("lice");
    set_incubation_period(0);
    set_base_incubation_period(0);
    set_dc(55);
    //the stage the disease starts at  
    //in effects -1 is added every time the disease does anything
    //other stages are once - so exhaustion could only possibly happen once
    set_base_disease_stage(-1);
    set_disease_stage(-1);
    set_effect_rate(150);
    set_infection_rate(100);
    set_disease_length(-1);
    set_bypass_immunity(1);
    set_disease_string("$TSUB%^BOLD%^%^BLACK%^ scratches frequently.%^RESET%^");
    set_personal_disease_string("%^BOLD%^%^GREEN%^You scratch frequently.%^RESET%^");
}

void beneign_disease_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(WhoInfected)) return;
    switch(random(2))
    {
        case 0:
            tell_object(WhoInfected, "%^BOLD%^%^RED%^You scratch your head rapidly as the lice bite at you!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^RED%^ scratches "+WhoInfected->QP+" head "+
            "rapidly!%^RESET%^", WhoInfected);
            break;
        case 1:
            tell_object(WhoInfected, "%^BOLD%^%^BLACK%^You scratch and slap at your head, as the lice eat at your scalp!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^BLACK%^ scratches and slaps "+
            "at "+WhoInfected->QP+" head and you can see lice fall off!%^RESET%^", WhoInfected);
            break;
    }
}

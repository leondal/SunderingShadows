#include <std.h>
#include <daemons.h>

inherit "/d/charucavern/diseases/disease_inherit";

void create()
{
    ::create();
    add_disease_effect((["damage" : roll_dice(2,10)]), -1);
    add_disease_effect((["exhaustion" : roll_dice(1,10)]), 1);
    set_disease_name("The deep flu");
    set_incubation_period(10800);
    set_base_incubation_period(10800);
    set_dc(18);
    //the stage the disease starts at  
    //in effects -1 is added every time the disease does anything
    //other stages are once - so exhaustion could only possibly happen once
    set_base_disease_stage(0);
    set_disease_stage(0);
    set_effect_rate(900);
    set_disease_string("$TSUB%^BOLD%^%^GREEN%^ coughs sporadically.%^RESET%^");
    set_personal_disease_string("%^BOLD%^%^GREEN%^You cough sporadically.%^RESET%^");
}

void beneign_disease_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(WhoInfected)) return;
    switch(random(3))
    {
        case 0:
            tell_object(WhoInfected, "%^BOLD%^%^GREEN%^You cough loudly and hack up some phlegm!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^GREEN%^ coughs loudly and hacks "+
            "up some phlegm!%^RESET%^", WhoInfected);
            break;
        case 1:
            tell_object(WhoInfected, "%^BOLD%^%^RED%^You cough suddenly and spit up a glob of bright red blood!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^RED%^ suddenly coughs and spits up a "+
            "glob of bright red blood!%^RESET%^", WhoInfected);
            break;
        case 2:
            tell_object(WhoInfected, "%^BOLD%^%^BLACK%^You cough and cough, struggling to breath!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^BLACK%^ coughs and coughs, "+
            "struggling to breath!%^RESET%^", WhoInfected);
            break;
    }
}
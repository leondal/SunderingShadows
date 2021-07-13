#include <std.h>
#include <daemons.h>

inherit FEAT;

int SURGE,count,bonus;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Archpsion");
    feat_name("power surge");
    feat_prereq("Archpsion L1");
    feat_syntax("power_surge");
    feat_desc("Power surge allows the archpsion to turn his mental energy into increased strength with his powers. When an archpsion activates power surge, she will enter a state of intense concentration. When under attack, occasionally the concentration will empower her spells. These strengthened spells are difficult to maintain, however, and will only last for a short duration before the archpsion must recover his mental energies. Once the power is activated, it does not need to be activated again until death or something similar.");
    set_required_for(({"perfect manifesting","kinetic conversion"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archpsion") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_power_surge(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


void execute_feat()
{
    if(FEATS_D->is_active(caster,"power surge"))
    {
        tell_object(caster,"Power surge is already active.");
        dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster,"%^RESET%^%^BOLD%^%^CYAN%^You turn your minds eye inwards, focusing on your mental strength and preparing to unleash it outwards.%^RESET%^");
    caster->set_property("active_feats",({TO}));
    return;
}


void execute_attack()
{
    if(!objectp(caster) || !objectp(environment(caster)))
    {
        dest_effect();
        return;
    }
    place = environment(caster);

    if(SURGE) { count++; }
    if(!SURGE) { count = 0; }

    if(sizeof(caster->query_attackers()))
    {
        if(!SURGE)
        {
            if(!random(4)) // might need to adjust the frequency here, will have to observe it
            {
                SURGE = 1;
                bonus = clevel / 10;
                tell_object(caster,"%^RESET%^%^BOLD%^%^MAGENTA%^You unleash the force in your mind, strengthening your powers!%^RESET%^");
                caster->set_property("empowered",bonus);
            }
        }
    }

    if(SURGE && !sizeof(caster->query_attackers()))
    {
        SURGE = 0;
        tell_object(caster,"%^RESET%^%^BOLD%^%^CYAN%^You release the mental focus required to maintain the surge, preparing for the next.");
        caster->set_property("empowered",-1 * bonus);
    }

    if(SURGE && (count > bonus) )
    {
        SURGE = 0;
        count = 0;
        tell_object(caster,"%^RESET%^%^BOLD%^%^RED%^You can no longer maintain the power surge.  You prepare your mind for the next one.");
        caster->set_property("empowered",-1*bonus);
    }

    if(objectp(place)) { place->addObjectToCombatCycle(TO,1); }
    else { dest_effect(); }
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        if(SURGE)
        {
            tell_object(caster,"%^RESET%^%^BOLD%^%^CYAN%^You relax as you release the mental focus required to produce a surge.");
            caster->set_property("empowered",-1 * bonus);
        }
        caster->remove_property_value("active_feats",({TO}));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

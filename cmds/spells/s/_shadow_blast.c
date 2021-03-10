#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shadow blast");
    set_spell_level(([ "mage" : 6,]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS shadow blast");
    set_damage_desc("half cold, half electricity");
    set_description("This spell sends a waves of dark bolts snatched from the plane of shadow. A quick opponent might dodge bolts, but will still be damaged by the cold. This spell will aim at every living present.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("reflex");
}

string query_cast_string()
{
    return "%^MAGENTA%^"+caster->QCN+" spells an incantation in eerie voice.";
}

void spell_effect(int prof)
{
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^MAGENTA%^"+caster->QCN+" raises hand and releases bolts of darkness!%^RESET%^");
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^The bolts disperse, hitting nobody.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        admg=sdamage;
        tell_object(attackers[i],"%^BLUE%^You are hit with bolts of darkness!%^RESET%^");
        tell_object(caster,"%^BOLD%^" + attackers[i]->QCN + " is hit with bolts of darkness!%^RESET%^");
        if(!do_save(attackers[i]))
        {
            damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"electricity");
        }
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"cold");
    }
    spell_successful();
    dest_effect();
}

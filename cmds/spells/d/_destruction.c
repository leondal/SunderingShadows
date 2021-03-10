#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("destruction");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("necromancy");
    set_mystery("reaper");
    set_domains("repose");
    set_syntax("cast CLASS destruction on TARGET");
    set_damage_desc("divine");
    set_description("This spell instantly delivers untyped damage to the target. If the target's health points fall below zero it instantly dies. Successful save halves the damage.");
    set_verbal_comp();
    set_save("fort");
    set_somatic_comp();
    set_target_required(1);
}

spell_effect()
{
    int dam = sdamage;
    spell_successful();
    if(do_save(target,0))
        dam/=2;
    if (interactive(caster))
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^You simply unmake some of "+target->QCN+"!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" unmakes some of "+target->QCN+" with "+caster->QP+" spell!", ({caster}) );
    }
    damage_targ(target, target->return_target_limb(), sdamage,"divine");
    if(target->query_hp()<0)
        target->die();
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

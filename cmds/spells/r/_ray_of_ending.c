#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create() {
    ::create();
    set_spell_name("ray of ending");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS ray of ending on TARGET");
    set_damage_desc("untyped");
    set_description("This devastating spell causes a ray of dark brown mist to lance towards any target in range. The caster must succeed at a touch attack to strike the target with a ray of ending. Any creature struck by a ray of ending must make a saving throw or be erased from existence. When this spell suceeds it always kills the target.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof)
{
    int roll;
    ::spell_effect();

    if (!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
    spell_kill(target,caster);
    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);

    spell_kill(target,caster);
    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(target, "%^BOLD%^%^BLACK%^You are narrowly missed by a black mist emanating from "+caster->QCN+".\n");
        tell_room(place, "%^BOLD%^%^BLACK%^"+target->QCN+" is narrowly missed by a black mist emanating from "+caster->QCN+".\n",({ caster, target}));
        tell_object(caster, "%^BOLD%^%^BLACK%^Your ray of ending missed "+target->QCN+".\n");

        TO->remove();
    } else {
        spell_successful();
        tell_object(target, "%^BOLD%^%^BLACK%^You are hit by a black ray emanating from "+caster->QCN+".\n");
        tell_object(target, "%^BOLD%^%^BLACK%^You suddenly feel your very body is being unmade.\n");
        tell_room(place, "%^BOLD%^%^BLACK%^"+target->QCN+" is hit by a ray emanating from "+caster->QCN+".\n", ({ caster, target}));
        tell_object(caster, "%^BOLD%^%^BLACK%^Your ray of ending hits "+target->QCN+"!\n");

        // WOK, clasing rocks and this one share disadvantage value.
        if (combat_death_save(target, 0)) {
            tell_object(target,"%^BOLD%^%^BLACK%^You sigh with relief as you endure the unmaking.");
            damage_targ(target, target->return_target_limb(), sdamage, "untyped");
        } else {
            tell_object(target,"%^BOLD%^%^BLACK%^You are no more.");
            tell_room(place, "%^BOLD%^%^BLACK%^" + target->QCN + " turns into a black smoke.", target);
            damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "untyped");
            target->die();
        }
    }
    return 1;
}

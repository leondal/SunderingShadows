#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create() {
    ::create();
    set_spell_name("ray of exhaustion");
    set_spell_level(([ "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS ray of exhaustion on TARGET");
    set_damage_desc("exhaustion for clevel/6+1 rounds");
    set_description("A black ray springs from your hand. You must succeed on a ranged touch attack to strike a target. The subject becomes exhausted, but on a successful roll they only become fatigued. If they are already fatigued, they become exhausted.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof)
{
    int roll;
    ::spell_effect();

    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return;
    }
    spell_kill(target,caster);
    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);

    spell_kill(target,caster);
    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(target, "%^BOLD%^%^BLACK%^You are narrowly missed by a black ray emanating from "+caster->QCN+".\n");
        tell_room(place, "%^BOLD%^%^BLACK%^"+target->QCN+" is narrowly missed by a black ray emanating from "+caster->QCN+".\n",({ caster, target}));
        tell_object(caster, "%^BOLD%^%^BLACK%^Your ray of exhaustion missed "+target->QCN+".\n");

        TO->remove();
    } else {
        spell_successful();
        tell_object(target, "%^BOLD%^%^BLACK%^You are hit by a black ray emanating from "+caster->QCN+".\n");
        tell_object(target, "%^BOLD%^%^BLACK%^You suddenly feel very tired.\n");
        tell_room(place, "%^BOLD%^%^BLACK%^"+target->QCN+" is hit by a ray emanating from "+caster->QCN+".\n", ({ caster, target}));
        tell_object(caster, "%^BOLD%^%^BLACK%^Your ray of exhaustion hits "+target->QCN+"!\n");

        if(target->query_property("effect_fatigued")||
           do_save(target,0))
        {
            "/std/effect/status/fatigued"->apply_effect(target,clevel/6+1);
        }
        else
            "/std/effect/status/exhausted"->apply_effect(target,clevel/6+1);

        spell_kill(target,caster);
    }
    return 1;
}

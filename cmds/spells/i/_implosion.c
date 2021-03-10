#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("implosion");
    set_spell_level(([ "cleric" : 9, "psion" : 9 ]));
    set_spell_sphere("invocation_evocation");
    set_discipline("shaper");
    set_syntax("cast CLASS implosion on TARGET");
    set_damage_desc("untyped");
    set_description("With this spell caster attempts to crush opponent.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " wavers while chanting.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You extend your hand and will to crush " + target->QCN + "!");
        tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " extends hand and wills to crush " + target->QCN + " with " + caster->QP + " spell!", ({ caster }));
    }
    damage_targ(target, target->return_target_limb(), sdamage, "untyped");
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

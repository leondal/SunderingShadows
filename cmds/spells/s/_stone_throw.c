// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("stone throw");
    set_spell_level(([ "oracle" : 1, "mage" : 1, "druid" : 1 ]));
    set_mystery("stone");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS stone throw on TARGET");
    set_damage_desc("bludgeoning");
    set_description("You create a small stone and forcefully project it on target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}
string query_cast_string()
{
    return "%^ORANGE%^" + caster->QCN + " chants sonorously, dust forms in front of them into a small stone.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster, "%^ORANGE%^You project the stone into direction of " + target->QCN + "!");
        tell_room(place, "%^ORANGE%^" + caster->QCN + " forcefully projects the stone at " + target->QCN + "!", ({ caster }));
    }
    damage_targ(target, target->return_target_limb(), sdamage, "bludgeoning");
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

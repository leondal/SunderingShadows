#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("serac");
    set_spell_level(([ "mage" : 2]));
    set_spell_sphere("invocation_evocation");
    set_domains("cold");
    set_syntax("cast CLASS serac on TARGET");
    set_damage_desc("half cold half bludgeoning");
    set_description("With this spell the caster summons a platform of ice and popells it towards the enemy with force.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect()
{
    int dam = sdamage;
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^A platform of ice appears by your side and propels towards " + target->QCN + " with force.%^RESET%^");
        tell_object(target, "%^BOLD%^%^CYAN%^A platform of ice appears by " + caster->QCN + "'s side and propels towards you with force.%^RESET%^");
        tell_object(target, "%^BOLD%^%^CYAN%^A platform of ice appears by " + caster->QCN + "'s side and propels towards " + target->QCN + " with force.%^RESET%^", ({ caster, target }));
    }
    damage_targ(target, target->return_target_limb(), sdamage / 2, "cold");
    damage_targ(target, target->return_target_limb(), sdamage / 2, "bludgeoning");
    dest_effect();
}

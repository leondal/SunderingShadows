#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("greater ruin");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_domains("destruction");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS greater ruin on TARGET");
    set_damage_desc("untyped");
    set_description("With this spell mage attempts to disrupt the very creation of her target to transform them into nothing.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" crushes a lodestone while chanting.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You simply unmake some of "+target->QCN+"!");
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" unmakes some of "+target->QCN+" with "+caster->QP+" spell!", ({caster}) );
    }
    damage_targ(target, target->return_target_limb(), sdamage,"untyped");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

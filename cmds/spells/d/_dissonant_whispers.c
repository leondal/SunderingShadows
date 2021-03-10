#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("dissonant whispers");
    set_spell_level(([ "bard" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS dissonant whispers on TARGET");
    set_description("Your opponent hears whispers that damages their psyche.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" whispers a cong.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if (interactive(caster)) {
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" whispers a song towards "+target->QCN+".", ({target}) );
        tell_object(target,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s whispers are just maddening, mean and hurtful!"+target->QCN+".", ({caster}) );        
    }
    damage_targ(target, target->return_target_limb(), sdamage,"mental");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


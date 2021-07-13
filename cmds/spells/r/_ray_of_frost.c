// Mind Thrust
// ~Circe~ 7/19/05
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("ray of frost");
    set_spell_level(([ "cantrip" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS ray of frost on TARGET");
    set_description("With this spell you direct a freezing ray at your target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^CYAN%^"+caster->QCN+"'s hand cover in a layer of frost%^RESET%^";
}

spell_effect(int prof) {

    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^You open your hands and direct a ray of frost at "+target->QCN+"!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" opens "+caster->QP+" hands and directs a ray of frost at "+target->QCN+"!", ({caster}) );
    }
    tell_object(target,"%^BOLD%^%^CYAN%^You feel very cold!");
    damage_targ(target, target->return_target_limb(), sdamage,"cold");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


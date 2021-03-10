#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("acid splash");
    set_spell_level(([ "mage" : 1, "inquisitor" : 1, "magus" : 1]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid splash on TARGET");
    set_description("This spell opens a tiny portal into the paraelemental plane of ooze above your target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "acid"}) );
}

spell_effect(int prof) {

    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You open a portal above "+target->QCN+" and some acid splashes through it!");
        tell_room(place,"%^BOLD%^%^GREEN%^A portal opens above "+target->QCN+" and some acid pours through it!", ({caster}) );
    }
    damage_targ(target, target->return_target_limb(), sdamage,"acid");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

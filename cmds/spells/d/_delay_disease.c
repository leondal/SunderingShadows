#include <std.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("delay disease");
    set_spell_level(([ "cleric":2, "druid":2, "paladin":2, "ranger":2, "inquisitor":2]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS delay disease on TARGET");
    set_description("On a sucessful power check will revert all deseases target experiences a stage back.");

    set_verbal_comp();
    set_somatic_comp();

    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^"+caster->QCN+" starts to vibrate and speaks a long incantation!";
}

void spell_effect()
{
    object * diseases;

    tell_room(place, "%^BOLD%^%^WHITE%^A brilliant white aura briefly envelopes " + target->QCN + "!");

    spell_successful();

    diseases = filter_array(all_inventory(target), (:$1->is_disease():));

    if (sizeof(diseases)) {
        diseases->reverse_stage(clevel * 9 / 8);
        tell_object(caster,"%^BOLD%^%^WHITE%^You attempt to cure symptoms of the disease.");
    } else {
        tell_object(caster,"%^BOLD%^%^WHITE%^You sense no changes in " + target->QCN + ".");
    }
    return;
}

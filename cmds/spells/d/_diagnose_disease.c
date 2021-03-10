#include <std.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("diagnose disease");
    set_spell_level(([ "cleric":1, "druid":1, "paladin":1, "ranger":1]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS diagnose disease on TARGET");
    set_description("You determine whether a creature carries any sort of disease or infestation, or any exceptional or supernatural effects causing the sickened or nauseated effects. If there is disease present, you know what disease it is and its effects.");

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
        tell_object(caster,"%^BOLD%^%^WHITE%^You sense next diseases: " + implode(diseases->query_name(), ", "));
    } else {
        tell_object(caster,"%^BOLD%^%^WHITE%^You sense no diseases affecting " + target->QCN + ".");
    }

    return;
}

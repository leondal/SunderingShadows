#include <spell.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("sylvan vigor");
    set_spell_level(([ "druid" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sylvan vigor");
    set_description("This spell bestows a small blessing upon the caster, increasing her health.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^RESET%^%^GREEN%^"+caster->QCN+" holds forth a sprig of mistletoe and whispers an incantation.";
}

int preSpell()
{
    if(caster->query_property("spell_bonus_hp"))
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^The vigor of nature strengthens you!%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+"'s skin takes on a glow of health!%^RESET%^",caster);
    bonus = clevel+10;

    caster->add_max_hp_bonus(bonus);
    caster->set_property("spell_bonus_hp",1);
    caster->set_property("spelled",({TO}));
    addSpellToCaster();
    spell_successful();
}

void dest_effect() {
    if(objectp(caster))
    {
        caster->add_max_hp_bonus(-bonus);
        caster->remove_property("spell_bonus_hp");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

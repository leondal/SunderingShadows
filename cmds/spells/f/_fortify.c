//added a property to prevent stacking ~Circe~ 12/16/19
//updated to add psions and psywarrior to streamline spells - replaces biofeedback ~Circe~ 10/26/19
//Reskinned into the fortify spell for psions (spell sphere is important).
#include <priest.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("fortify");
    set_spell_level(([ "psywarrior" : 1, "psion" : 1 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS fortify");
    set_bonus_type(({ "resistance" }));
    set_damage_desc("+1 to all saving throws");
    set_description("By this spell, the psionic manifester grants them additional protection from harm. They gain +1 to all saving throws.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + caster->QCN + " concentrates deeply.%^RESET%^";
}

int preSpell()
{
    set_target(caster);
    
    if(has_bonus_type()) {
        return 0;
    }
    
    return 1;
}

spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    
    if (interactive(caster)) {
        tell_object(caster, "%^GREEN%^As the last note fades, you feel a light prickling of protection across your skin.");
        tell_room(place, "%^GREEN%^The last note fades as " + caster->QCN + " glances around.", caster);
    }
    
    bonus = 1;

    caster->add_saving_bonus("all", bonus);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster) && caster->query_property("morale-boost"))
    {
        tell_object(caster,"%^CYAN%^An increase of morale you felt washes away as your resistance fades.");
        caster->add_saving_bonus("all", -bonus);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

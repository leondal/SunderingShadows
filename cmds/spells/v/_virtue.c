#include <spell.h>
inherit SPELL;

int newhp;

void create() {
    ::create();
    set_spell_name("virtue");
    set_spell_level(([ "paladin" : 1,"inquisitor":1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS virtue");
    set_damage_desc("clevel + 10 max hp bonus");
    set_description("This spell bestows a small blessing upon the caster, increasing their resilience.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" lowers "+caster->QP+" head and speaks a prayer.";
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

void spell_effect(int prof)
{
    object Vob;
    int bonus, diff;
    if (!objectp(caster) || !objectp(environment(caster)))
    {
        TO->remove();
        return;
    }
    if(objectp(Vob = caster->query_property("VigorOb"))) Vob->dest_effect();
    tell_object(caster,"%^BOLD%^%^BLUE%^The truth and valor of your cause fills you!");
    tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+"'s skin takes on a glow of health!",caster);


    newhp = clevel + 10;

    caster->add_max_hp_bonus(newhp);
    caster->set_property("spell_bonus_hp",1);
    caster->set_property("spelled",({TO}));
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    if(objectp(caster))
	{
            tell_object(caster, "%^BOLD%^%^BLUE%^The truth and valor of your cause fades away!%^RESET%^");
            tell_room(environment(caster), "%^BOLD%^%^BLUE%^The healthy glow of "+caster->QCN+
            "%^BOLD%^%^BLUE%^'s skin fades away!%^RESET%^", caster);
            caster->add_max_hp_bonus(-newhp);
            caster->remove_property("spell_bonus_hp");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}

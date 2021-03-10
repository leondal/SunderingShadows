#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("deadeyes lore");
    set_spell_level(([ "bard" : 1, "cleric" : 1, "druid" : 1, "inquisitor" : 1, "ranger" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS deadeyes lore");
    set_damage_desc("half of clevel survival skill");
    set_description("While subject to this spell, you take upon yourself the mantle of the hunter, channeling the insights of the spirits of the wild.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;
    if(target->query_property("deadyes_lore"))
    {
        tell_object(caster,"The target is already under a similar influence.");
        return 0;
    }
    return 1;
}

spell_effect()
{
    target = caster;

    spell_successful();

    tell_room(place,"%^GREEN%^"+caster->QCN+" touches own eyes, chanting in low undertones.%^RESET%^");

    bonus=clevel/2+1;
    target->add_skill_bonus("survival",bonus);
    target->set_property("spelled", ({TO}) );
    target->set_property("deadeyes_lore",1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 3;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("survival",-bonus);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^CYAN%^Your insights of the hunter retreat.%^RESET%^");
        target->remove_property("deadeyes_lore");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

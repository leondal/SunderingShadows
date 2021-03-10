#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("impenetrable veil");
    set_spell_level(([ "mage" : 6, "bard" : 6 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS impenetrable veil on TARGET");
    set_damage_desc("half of clevel to stealth checks on sneaking");
    set_description("You raise a shadowy veil around your target, making it harder to detect them.");
    set_arg_needed();
	set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;
    if(target->query_property("chameleoned"))
    {
        tell_object(caster,"The target is already under the influence of similar effect");
    }
    return 1;
}

spell_effect()
{
    if(!target)
        target = caster;

    if(!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    spell_successful();

    tell_room(place,"%^MAGENTA%^"+caster->QCN+" with a swift chant raises a wall of shadows around "+target->QCN+".%^RESET%^");

    bonus=clevel/2+1;
    target->set_property("spelled", ({TO}) );
    target->set_property("chameleoned",clevel/2);
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^MAGENTA%^The veil granted fades.%^RESET%^");
        target->remove_property("chameleoned");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

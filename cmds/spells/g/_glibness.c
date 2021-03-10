#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("glibness");
    set_spell_level(([ "bard" : 3, ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS glibness [on TARGET]");
    set_damage_desc("half of clevel influence skill");
    set_description("You temporarily increase your influence.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
    set_silent_casting(1);
}

int preSpell()
{
    if (!target) {
        target = caster;
    }
    if (target->query_property("glibness_spell")) {
        tell_object(caster, "The target is already under a similar influence.");
        return 0;
    }
    return 1;
}

spell_effect()
{
    spell_successful();
    tell_object(target, "%^MAGENTA%^You feel insight into the desires of others fill your mind.%^RESET%^");
    tell_room(place, "%^MAGENTA%^" + caster->QCN + " touches " + caster->QP + " temples, chanting in low undertones.%^RESET%^");

    bonus = clevel / 2 + 1;
    target->add_skill_bonus("influence", bonus);
    target->set_property("spelled", ({ TO }));
    target->set_property("glibness_spell", 1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(target)) {
        target->add_skill_bonus("influence", -bonus);
        target->remove_property_value("spelled", ({ TO }));
        tell_object(target, "%^MAGENTA%^Your insights into the desires of others fade.%^RESET%^");
        target->remove_property("glibness_spell");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

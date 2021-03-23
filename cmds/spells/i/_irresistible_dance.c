// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int bonus;

int is_curse()
{
    return 1;
}

void create()
{
    ::create();
    set_spell_name("irresistible dance");
    set_spell_level(([ "bard" : 6, "mage" : 8, "oracle" : 8, "cleric" : 8 ]));
    set_mystery("whimsy");
    set_domains("chaos");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS irresistible dance on TARGET");
    set_damage_desc("-clevel/8 to reflex save and AC");
    set_description("The subject feels an undeniable urge to dance and begins doing so, complete with foot shuffling and tapping. The spell effect makes it hard for the subject to do anything other than caper and prance in place.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

int preSpell()
{
    if (!caster->ok_to_kill(target)) {
        tell_object(caster, "You can't curse that!");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^BLUE%^A dark aura threads its way around " + caster->QCN + "'s fingers as " +
        caster->QS + " intones a spell.%^RESET%^";
}

void spell_effect(int prof)
{
    int duration;
    if (!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
    if (target->query_property("irresistible_dance")) {
        tell_object(caster, "%^ORANGE%^Your spell slips away from " + target->QCN + ", as they are already dancing!%^RESET%^");
        TO->remove();
        return;
    }
    if (target->query_property("magic resistance")) {
        if (target->query_property("magic resistance") < random(99) + 1) {
            tell_object(caster, "%^ORANGE%^You feel your spell take a grasp on " + target->QCN + " but then disperse as its power is rendered useless!\n");
            tell_object(target, "%^ORANGE%^You feel a spell attempt to dance your mind, but the grip slips and you the thought to dance passes.\n");
            spell_kill(target, caster);
            dest_effect();
            return;
        }
    }
    if (do_save(target, -2)) {
        tell_object(caster, "%^ORANGE%^You feel your spell take a grasp on " + target->QCN + " but then disperse as its power is rendered useless!\n");
        tell_object(target, "%^ORANGE%^You feel a spell attempt to dance your mind, but the grip slips and you the thought to dance passes.\n");
        spell_kill(target, caster);
        dest_effect();
        return;
    }
    bonus = clevel / 8;
    bonus = bonus < 1?1:bonus;
    bonus = bonus > 8?8:bonus;
    tell_object(target, "%^ORANGE%^You begin dancing, which significantly distracts you from moving as desired!%^RESET%^");
    tell_room(place, "%^ORANGE%^" + target->QCN + " begins uncontrollably dancing!%^RESET%^", target);
    target->add_ac_bonus(-bonus);
    target->add_saving_bonus("reflex", -bonus);
    target->set_property("irresistible_dance", 1);
    target->set_property("spelled", ({ TO }));
    addSpellToCaster();
    call_out("dancing_echo", ROUND_LENGTH * 2);
    duration = (ROUND_LENGTH)*clevel;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect", spell_duration);
    spell_successful();
}

void dancing_echo()
{
    if (!objectp(target)) {
        dest_effect();
        return;
    }
    tell_room(environment(target), "%^ORANGE%^" + target->QCN + " performs a silly dance!%^RESET%^", target);
    tell_object(target, "%^ORANGE%^You perform a silly dance!");
    call_out("dancing_echo", ROUND_LENGTH * roll_dice(1, 4));
}

void dest_effect()
{
    remove_call_out("dancing_echo");
    if (objectp(target)) {
        tell_object(target, "%^ORANGE%^Finally! You no longer feel compelled to dance.%^RESET%^");
        tell_room(environment(target), "%^ORANGE%^" + target->QCN + "'s silly dancing comes to an end.%^RESET%^", target);
        target->add_ac_bonus(bonus);
        target->add_saving_bonus("reflex", bonus);
        target->remove_property("irresistible_dance");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

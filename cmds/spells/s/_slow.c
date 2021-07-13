#include <std.h>
#include <magic.h>

inherit SPELL;

int power;

void create() {
    ::create();
    set_spell_name("slow");
    set_spell_level(([ "bard": 3, "mage": 3, "magus" : 3, "cleric" : 3 ]));
    set_spell_sphere("alteration");
    set_domains("law");
    set_damage_desc("clevel/20 + 1 to attack rolls, ac, and reflex damage, staggered for clevel / 25 + 1 rounds");
    set_syntax("cast CLASS slow on TARGET");
    set_description("An affected creature moves and attacks at a drastically slowed rate. Its number of attacks becomes reduced, and it becomes staggered and slow to move.");
    set_save("will");

    set_verbal_comp();
    set_somatic_comp();

    set_target_required(1);
}

int preSpell()
{
    if(target->query_property("slowed"))
    {
        tell_object(caster,"Your target is already slowed.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    return "%^BOLD%^%^ORANGE%^The sound turns dull as "+caster->QCN+" makes passes.%^RESET%^";
}

spell_effect()
{
    int round_duration;

    power = clevel / 20 + 1;

    if (do_save(target, -2)) {
        tell_object(caster,"%^ORANGE%^%^BOLD%^" + target->QCN + " shakes off your words of slow.");
        tell_object(target,"%^ORANGE%^%^BOLD%^You overcome the words of slow " + caster->QCN + " tried to induce on you.");
        TO->remove();
        return;
    }

    tell_object(target,"%^ORANGE%^As " + caster->QCN + "completes the chant your motions become slowed.");
    tell_object(caster,"%^ORANGE%^As you complete the chant " +target->QCN+"'s motions become slowed.");
    tell_room(place, "%^ORANGE%^As " + caster->QCN + "completes the chant " + target->QCN + "'s motions become slowed.", ({caster, target}));

    round_duration = clevel / 25 + 1;

    "/std/effect/status/staggered"->apply_effect(target, round_duration, caster);

    target->add_saving_bonus("reflex", -power);
    target->add_ac_bonus(-power);
    target->add_attack_bonus(-power);

    target->set_property("slowed", 1);

    spell_kill(target, caster);

    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();

}

dest_effect()
{
    if (objectp(target)) {
        tell_object(target,"%^ORANGE%^%^BOLD%^Your motions are no longer slowed by the spell.");
        target->remove_property("slowed");
        target->add_saving_bonus("reflex", power);
        target->add_ac_bonus(power);
        target->add_attack_bonus(power);
    }

    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

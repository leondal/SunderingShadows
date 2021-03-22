#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create()
{
    ::create();
    set_spell_name("orb of the void");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS orb of the void");
    set_damage_desc("mass negative levels on living");
    set_description("This spells represents necromancer's ability to channel negative energies and behaves the same as enervation, but hits multiple targets.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" spreads arms around them, chanting in deep, dark tone.";
}

void spell_effect()
{
    object * attackers;
    int power, round_duration;

    tell_object(caster,"%^BOLD%^%^BLUE%^You connect your hands, clapping loudly, as waves of fell powers spread with the sound.");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " connects " + caster->QP + " hands with a loud clap, sickening waves of power spread with the sound.", caster);

    attackers = target_selector();
    attackers = filter_array(attackers, (:!$1->is_undead():));

    if (!sizeof(attackers)) {
        tell_object(caster,"%^BOLD%^Your spell fails to infect anyone.");
    }

    foreach(target in attackers) {
        power = roll_dice(1, 4);
        round_duration = roll_dice(1, 20);
        "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
        spell_kill(target, caster);
    }

    spell_successful();
    return;

}

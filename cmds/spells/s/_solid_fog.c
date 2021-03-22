#include <std.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("solid fog");
    set_spell_level(([ "mage" : 4, "magus" : 4, "cleric" : 4 ]));
    set_domains("water");
    set_spell_sphere("conjuration_summoning");
    set_damage_desc("mass staggering for 1d6 rounds");
    set_description("This spells functions a lot like fog cloud, but instead of obscuring sight it conjures a fog so hard to move in everyone in the agrea becomes staggered.");

    set_verbal_comp();
    set_somatic_comp();

    splash_spell(3);
}

string query_cast_string()
{
    return "%^ORANGE%^As "+caster->QCN+" spells the incantation, the air becomes heavy.";
}

void spell_effect()
{
    object * attackers;
    int round_duration;

    tell_object(caster,"%^ORANGE%^You complete the chant, making the air around your enemies nearly solid...");
    tell_room(place, "%^ORANGE%^" + caster->QCN + " completes the chant, making the air nearly solid..", caster);

    attackers = target_selector();
    attackers = filter_array(attackers, (:!$1->is_undead():));

    if (!sizeof(attackers)) {
        tell_object(caster,"Your spell fails to affect anyone.");
    }

    round_duration = roll_dice(1, 6);

    foreach(target in attackers) {
        "/std/effect/status/staggered"->apply_effect(target, round_duration);
        spell_kill(target, caster);
    }

    spell_successful();
    return;

}

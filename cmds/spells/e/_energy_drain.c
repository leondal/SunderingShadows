#include <std.h>
#include <magic.h>

inherit SPELL;

int power;

void create() {
    ::create();
    set_spell_name("energy drain");
    set_spell_level(([ "mage" : 9, "cleric":9]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS energy drain on TARGET");
    set_damage_desc("1d4 negative levels to living for 3d20 rounds, clevel * 3 / 2 additional hp to undead");
    set_description("This spell functions exactly like enervation, but the duration is on a higher die.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof)
{
    int round_duration;
    int power;
    int i;

    power = roll_dice(1, 4);
    round_duration = roll_dice(3, 20);

    tell_object(caster,"%^BOLD%^%^BLACK%^A black ray of energy hits " + target->QCN + "%^RESET%^");
    tell_object(target,"%^BOLD%^BLACK%^A black ray, emanating from " + caster->QCN + "'s finger, hits you.");
    tell_room(place, "%^BOLD%^%^BLACK%^A black ray, emanating from " + caster->QCN + "'s finger hits " + target->QCN + ".", ({target, caster}));

    if (target->is_undead()) {
        target->add_max_hp_bonus(clevel * 3 / 2);
        tell_object(target,"%^BOLD%^As the ray hits you, you feel empowered.");
    } else {
        "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
        spell_kill(target, caster);
    }


}

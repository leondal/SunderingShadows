#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create() {
    ::create();
    set_spell_name("harvest of tyrannos");
    set_spell_level(([ "innate" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS harvest of tyrannos on TARGET");
    set_damage_desc("fire");
    set_description("Your gaze fills with black flame of Tyrannos, burning your victim's soul and blood in an instant of its death.");
    set_save("will");
    set_blood_magic(1);
    set_target_required(1);
    set_peace_needed(1);
}

int preSpell() {
    if (!RACE_D->is_valid_blooddrain_target(target, caster)) {
        tell_object(caster,"This is not a fresh victim.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    ::spell_effect();

    spell_kill(target,caster);

    spell_successful();

    tell_object(target, "%^BOLD%^%^BLACK%^"+caster->QCN+" gazes upon you, the gaze burns your soul from within with fire.\n");
    tell_object(target, "%^BOLD%^%^BLACK%^You feel your very soul being unmade.\n");
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " gazes upon " + target->QCN + " with eyes full of fire.\n", ({ caster, target}));

    if (combat_death_save(target, -8) || target->query_resistance_percent("fire") > 100) {
        tell_object(target,"%^BOLD%^%^BLACK%^You sigh with relief as your soul survives.");
        tell_object(caster,"%^BOLD%^%^RED%^Your gaze barely scorches the victim.");
        damage_targ(target, target->return_target_limb(), sdamage, "fire");
    } else {
        tell_object(target,"%^BOLD%^%^BLACK%^You are no more.");
        tell_room(place, "%^BOLD%^%^BLACK%^" + target->QCN + " turns into an ash.", target);
        tell_object(caster,"%^BOLD%^%^RED%^You feel your hunger for blood somewhat replenished.");
        caster->add_bloodlust(10000);
        damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "fire");
        target->die();
    }

    return 1;
}

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("clashing rocks");
    set_spell_level(([ "mage" : 9, "druid":9,]));
    set_mystery("stone");
    set_domains("magic");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS clashing rocks on TARGET");
    set_damage_desc("bludgeoning");
    set_description("You create colossal-sized rocks and propel them forcefully at your enemy. You have a chance to miss your opponent entirely, and if they sidestep in time they'll survive the attack.");
    set_save("reflex");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^ORANGE%^" + caster->QCN + " closes " + caster->QP + " eyes and tosses a few rocks upon the ground!";
}

void spell_effect(int prof)
{
    int roll;
    ::spell_effect();

    if (!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
    spell_kill(target, caster);
    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);

    spell_kill(target, caster);
    tell_object(caster, "%^BOLD%^As rocks grow large and float in the air, you propel them forcefully at " + target->QCN);
    tell_room(place, "%^BOLD%^As rocks grow large and float in the air, " + caster->QCN + " propels them forcefully at " + target->QCN, caster);

    if (!roll || roll == -1 && !caster->query_property("spectral_hand")) {
        tell_object(target, "%^ORANGE%^You barely make an escape from rocks clashing at you!.");
        tell_room(place, "%^ORANGE%^" + target->QCN + " barely makes an ascape from rocks clashing at them!", ({ caster, target }));
        tell_object(caster, "%^ORANGE%^Propelled rocks missed  " + target->QCN + "!");

        TO->remove();
    } else {
        spell_successful();
        tell_object(target, "%^ORANGE%^%^BOLD%^You are hit by the giant rocks!\n");
        tell_room(place, "%^ORANGE%^%^BOLD%^" + target->QCN + " is hit by the giant rocks!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^BLACK%^Your ray of ending hits " + target->QCN + "!\n");

        // Ray of ending, WOK and this one should share disadvantage value
        if (combat_death_save(target, 0)) {
            tell_object(target, "%^BOLD%^%^BLACK%^You barely make an escape from being crushed to dust!");
            damage_targ(target, target->return_target_limb(), sdamage, "bludgeoning");
        } else {
            tell_object(target, "%^BOLD%^%^BLACK%^You are crushed by the rocks, and die.");
            tell_room(place, "%^BOLD%^%^BLACK%^" + target->QCN + " dies being crushed by the rocks.", target);
            damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "bludgeoning");
            target->die();
        }
    }
    return 1;
}

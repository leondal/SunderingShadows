#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create()
{
    ::create();
    set_spell_name("frigid touch");
    set_spell_level(([ "mage" : 2, "druid" : 2, "magus" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS frigid touch on TARGET");
    set_damage_desc("cold, staggered");
    set_description("This spell causes your hand to glow with a pale blue radiance... Then you touch mean people with it and they become cold. Nasty business.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^CYAN%^" + caster->QCN + " utters cold words.";
}

spell_effect(int prof)
{
    string mycolor, myhue, myhue2, myfeeling;
    int bonus, roll;

    if (!objectp(caster) || !objectp(target)) {
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();

    bonus = 0;

    if (!present(target, environment(caster))) {
        tell_object(caster, "%^BOLD%^Your target is not in this area.\n");
        target = 0;
        dest_effect();
        return;
    }

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if (!roll || roll == -1 && !caster->query_property("spectral_hand")) {
        tell_object(caster, "" + mycolor + "You try and touch " + target->QCN + "'s " + target_limb + " with a " + myhue + " hand, but miss!");
        tell_object(target, "" + mycolor + caster->QCN + "'s " + myhue + " hand gropes for your " + target_limb + " unsuccessfully.");
        tell_room(place, "" + mycolor + caster->QCN + " reaches out for " + target->QCN + "'s " + target_limb + " with a " + myhue + " hand and misses!", ({ caster, target }));
        target = 0;
        dest_effect();
        return;
    }

    if (!"/daemon/combat_d.c"->extra_hit_calcs(caster, target)) {
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster, "%^BOLD%^%^CYAN%^You reach out and touch " + target->QCN + "'s " + target_limb + " with your hand.");
    tell_object(target, "%^BOLD%^%^CYAN%^" + caster->QCN + " touches your " + target_limb + ".\n%^WHITE%^A feeling of cold runs through you...");
    tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + " reaches out and touches " + target->QCN + "'s " + target_limb + "...", ({ caster, target }));
    spell_successful();

    damage_targ(target, target->return_target_limb(), sdamage, "cold");
    target->set_tripped(roll_dice(1, 6), "%^BOLD%^%^CYAN%^You are staggered by the cold!%^RESET%^");
    target->use_stamina(sdamage / 6);

    dest_effect();
}

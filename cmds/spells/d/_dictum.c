#include <std.h>
#include <spell.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("dictum");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 6, ]));
    set_spell_sphere("invocation_evocation");
    set_mystery("godclaw");
    set_domains("law");
    set_syntax("cast CLASS dictum on TARGET");
    set_description("You proclaim a word of power, and stagger, paralyze or kill your target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^You can feel an orderly presence building inside.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " chants in an orderly fashion.", caster);
    return "display";
}

void spell_effect()
{
    int ldiff;

    ldiff = (clevel - target->query_level());

    caster->force_me("yell %^WHITE%^%^BOLD%^DIE!");

    if (!do_save(target, 4)) {
        tell_room(place, "%^BOLD%^" + target->QCN + " is blasted to the groud with the power of the voice.", target);
        tell_object(target, "%^BOLD%^%^You are blasted to the ground with the power of the voice.");
        target->set_tripped(roll_dice(1, 4), "%^BOLD%^You are trying to regain your footing.");
    }

    if (ldiff > 4) {
        int duration;
        tell_room(place, "%^BOLD%^" + target->QCN + " stops for a moment with a thoughtful expression.", target);
        tell_object(target, "%^BOLD%^%^You are stunned by the command.");
        duration = roll_dice(2, 4);
        if (do_save(target, 4)) {
            duration = 8 * roll_dice(1, 4);
        }
        target->set_paralyzed(duration, "You are stunned by the command you just heard.");
    }

    if (ldiff > 9) {
        if (!combat_death_save(target, 6)) {
            tell_room(place, "%^BOLD%^Upon hearing the words, " + target->QCN + " simply dies!", target);
            tell_object(target, "%^BOLD%^YOU OBEY AND DIE.");
            damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "mental");
        }
    }

    dest_effect();
    return;
}

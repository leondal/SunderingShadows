#include <spell.h>
#include <magic.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("grease");
    set_spell_level(([ "mage" : 1, "bard" : 1, "magus" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_damage_desc("tripped for 1d4 rounds");
    set_description("A grease spell covers a solid surface with a layer of slippery grease. Any creature in the area when the spell is cast must make a successful Reflex save or fall.");

    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    return "%^GREEN%^" + caster->QCN + " steps away from " + target->QCN + " and starts a low chant.";
}

spell_effect(int prof)
{
    int save, neededroll, power;
    string strength;
    tell_object(caster, "%^GREEN%^You jab your finger at " + target->QCN + " and strands of sticky grease shoot out towards " + target->QO + "!");
    tell_object(target, "%^GREEN%^" + caster->QCN + " jabs " + caster->QP + " finger at you, shooting out jet of sticky grease!");
    tell_room(place, "%^GREEN%^" + caster->QCN + " jabs " + caster->QP + " finger at " + target->QCN + ", shooting out jet of sticky grease!", ({ caster, target }));
    if (do_save(target, -2)) {
        tell_object(caster, "%^BOLD%^%^GREEN%^" + target->QCN + " manages to dodge your jet of grease!");
        tell_object(target, "%^BOLD%^%^GREEN%^You manage to dodge the grease!");
        tell_room(environment(caster), "%^BOLD%^%^GREEN%^" + target->QCN + " manages to dodge the grease!", ({ caster, target }));
        dest_effect();
        return;
    } else {
        spell_successful();
        tell_room(place, "%^GREEN%^" + target->QCN + " slips on the grease and falls down!", ({ caster, target }));
        target->set_tripped(roll_dice(1, 4));
    }
}

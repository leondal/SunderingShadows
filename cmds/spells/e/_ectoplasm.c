/*
  ectoplasm.c

  Reskinned rewrite of web with psionic theme.

  -- Tlaloc -- 3.20.20
*/

#include <spell.h>
#include <magic.h>

inherit SPELL;

void dest_effect();

create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("ectoplasm");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("metacreativity");
    set_discipline("shaper");
    set_syntax("cast CLASS ectoplasm on TARGET");
    set_damage_desc("tripped for 1d8 rounds");
    set_description("Summons strands of ectoplasm from the Astral Plane to wrap themselves around the target and trip them.");
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    return caster->QCN+" steps away from "+target->QCN+" and begins meditating.";
}

spell_effect(int prof)
{
    int save;

    string my_name, your_name;

    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();

    tell_object(caster, "%^CYAN%^" + sprintf("You summon strands of astral ectoplasm that shoot out towards %s!", your_name) + "%^RESET%^");
    tell_object(target, "%^CYAN%^" + sprintf("%s summons strands of astral ectoplasm that shoot out towards you!", my_name) + "%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s summons strands of astral ectoplasm that shoot out towards %s!", my_name, your_name) + "%^RESET%^", ({ caster, target }));

    if ( do_save(target,-2))
    {
        tell_object(caster,""+target->QCN+" manages to dodge your ectoplasm!");
        tell_object(target,"You manage to dodge the ectoplasm!");
        tell_room(environment(caster),""+target->QCN+" manages to dodge the ectoplasm!",({caster, target}) );
        dest_effect();
        return;
    }
    else
    {
        spell_successful();
        tell_object(caster, "%^CYAN%^" + sprintf("Your strands of ectoplasm wrap around %s, trapping %s in place!",your_name,target->query_objective()) + "%^RESET%^");
        tell_object(target, "%^CYAN%^" + sprintf("%s's strands of ectoplasm wrap around you, trapping you in place!", my_name) + "%^RESET%^");
        tell_room(place, sprintf("%s's strands of ectoplasm wrap around %s, trapping %s in place!", my_name, your_name, target->query_objective()), ({ caster, target }));
        target->set_tripped(roll_dice(1,8));
    }
}

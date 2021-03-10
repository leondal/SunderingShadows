/*
  _psychic_crush.c
  
  Similar to dictum. Causes status effects or kills.
  
  -- Tlaloc -- 4.7.20
*/

#include <std.h>
#include <spell.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("psychic crush");
    set_spell_level(([ "psion" : 5 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS psychic crush on TARGET");
    set_description("Your psychic will abruptly and brutally crushes the mental essence of the target. This power will stagger, paralyze or kill the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}


void spell_effect()
{
    int ldiff;

    ldiff=(clevel-target->query_level());
    
    tell_object(caster, "%^BOLD%^CYAN%^You focus your psychic energies on crushing "+target->QCN+"'s mind!");
    tell_object(target, "%^BOLD%^You suddenly feel a vicious attack upon your psyche!");

    if(!do_save(target,4))
    {
        tell_room(place,"%^BOLD%^"+target->QCN+" is knocked down by the mental assault!",target);
        tell_object(target,"%^BOLD%^You are assaulted by a brutal mental assault, knocking you off your feet!");
        target->set_tripped(roll_dice(1,4),"You are trying to regain your footing.");
    }

    if(ldiff>4)
    {
        int duration;
        tell_room(place,"%^BOLD%^"+target->QCN+" is paralyzed by the mental assault!",target);
        tell_object(target,"%^BOLD%^You feel your body freeze as the mental assault thrashes your mind!");
        duration = roll_dice(2,4);
        if(!do_save(target,4))
            duration = 8*roll_dice(1,4);
        target->set_paralyzed(duration,"%^BOLD%^You are paralyzed by the mental assault!");
    }

    if(ldiff>9)
    {
        if(!(do_save(target,4)||
             target->query_property("no death")))
        {
            tell_room(place,sprintf("The psychic assault crushes %s's mind completely and %s drops dead!",target->QCN,target->query_subjective()));
            tell_object(target,"You die as your mind is crushed!");
            damage_targ(target,target->return_target_limb(),target->query_max_hp()*2,"mental");
        }
    }

    dest_effect();
    return;
}

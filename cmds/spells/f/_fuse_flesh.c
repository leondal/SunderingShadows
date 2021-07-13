/*
  _fuse_flesh.c
  
  Higher level blindness spell.
  
  -- Tlaloc -- 3.31.20
*/

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("fuse flesh");
    set_spell_level(([ "psion" : 6, ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS fuse flesh on TARGET");
    set_description("You cause the target's flesh to ripple, grow together into a seamless whole. The subject's eyelids are directly affected, causing immediate blindness if they do not make a fortitude save..");
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^CYAN" + sprintf("%s concentrates on %s psionic powers.", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{

    if(target->query_blind() || target->query_temporary_blinded())
    {
        tell_object(caster,"The sight is already gone from "+target->QCN+"'seyes!");
        tell_room(place,""+caster->QCN+"'s psionic power softly snuffs out.",caster);
        TO->remove();
        return;
    }
    if(do_save(target))
    {
        tell_object(target,"Your vision becomes momentarily hazy, but you manage to re-focus.");
        tell_room(place,""+target->QCN+" hesitates, but then shakes off the psychic assault.",target);
        TO->remove();
        return;
    }
    tell_object(target,"%^CYAN%^Your vision is compromised as your eyelids fuse shut!");
    tell_room(place,"^&CYAN%^"+target->QCN+"'s eyelids fuse, rendering them blind!",target);
    target->set_temporary_blinded(roll_dice(2,6));
    spell_successful();
    dest_effect();
}

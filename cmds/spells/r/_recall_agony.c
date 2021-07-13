/*
  _recall_agony.c
  
  Single target mental blast spell.
  
  -- Tlaloc -- 3.30.20
*/

#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("recall agony");
    set_spell_level(([ "psion" : 2 ]));
    set_damage_desc("mental");
    set_spell_sphere("clairsentience");
    set_save("will");
    set_syntax("cast CLASS recall agony on TARGET");
    set_description("The fabric of time parts to your will, revealing wounds your foe has received in the past (or has yet to receive). That foe takes damage as the past (or future) impinges briefly on the present.");
    set_target_required(1);
    mental_spell();
}

void spell_effect(int prof)
{
    int num, numdarts, damage, mylevel;
    string hardness;
    mylevel = clevel;

    spell_successful();
    if (interactive(caster))
    {
        tell_object(caster,"You part the fabric of time itself, bringing past and future to the present!");
        tell_object(target,"%^CYAN%^"+caster->QCN+" parts the fabric of time itself!");
        tell_room(place,"%^CYAN%^"+caster->QCN+" parts the fabric of time, focusing on "+target->QCN+" intently!", ({caster, target}) );
    }
    damage = sdamage;
    
    if(!caster || !target)
        return;
    
    tell_object(caster, sprintf("%s screams in pain as %s feels pain, both past and future!", target->QCN, target->QP));
    tell_object(target, "%^YELLOW%^You scream in pain as you feel your future and past pain all at once!%^RESET%^");
    tell_room(place, sprintf("%s screams in pain as %s feels pain, both past and future!", target->QCN, target->QP));

    damage_targ(target, target->return_target_limb(), damage,"mental");
    this_object()->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}

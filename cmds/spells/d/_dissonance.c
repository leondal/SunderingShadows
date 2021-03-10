/*
  _dissonance.c
  
  Seer ability that damages and sickens.
  
  -- Tlaloc -- 4.10.20
*/

#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("dissonance");
    set_spell_level( ([ "psion" : 1 ]) );
    set_discipline("seer");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS dissonance on TARGET");
    set_damage_desc("Mental Damage and Sickened");
    set_description("Your mere thought grants your foe an imperfect, unfocused glimpse of the many possible futures in store. Unaccustomed to and unable to process the information, the subject becomes sickened for 2d4 rounds");
    set_target_required(1);
    set_arg_needed();
}

string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    tell_object(caster, "%^CYAN%^BOLD%^You show your opponent glimpses of many possible futures, assaulting their mind!");
    tell_object(target, "%^CYAN%^BOLD%^" + caster->QCN + " assaults your mind, showing you many possible futures!");
    say( sprintf("%s assaults %s's mind!", caster->QCN, target->QCN), target, caster);
    
    spell_successful();
    
    "/std/effect/status/sickened"->apply_effect(target,roll_dice(2,4));
    damage_targ(target,target->return_target_limb(),sdamage,"mental");
    
    dest_effect();
}

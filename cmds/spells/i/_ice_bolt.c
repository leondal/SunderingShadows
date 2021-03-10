/*
  _ice_bolt.c
  
  Innate spell for Clerics with the Cold Domain.
  Ranged attack for hit.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("ice bolt");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("cold");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate ice bolt on TARGET");
    set_damage_desc("Cold damage to target on successful ranged touch attack");
    set_description("Clerics with the cold domain learn, by the grace of their deity, how to attack their opponents with bolts of ice. This spell uses a ranged touch attack to do cold damage. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    set_immunities( ({ "cold" }) );
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while pointing with "+caster->QP+" finger.%^RESET%^";
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 0;
    }
    
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Ice Bolt!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
       
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1 && !caster->query_property("spectral_hand"))
    {
        tell_object(caster, "You fire an ice bolt at " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^A bolt of glistening ice shoots out of your finger and squarely strikes " + target->QCN + " with a spray of frost!%^RESET%^");
    tell_room(place, "%^CYAN%^BOLD%^" + caster->QCN + " shoots a bolt of glistening ice out of " + caster->QP + " finger, striking " + target->QCN + " with a spray of frost.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "cold");
    spell_kill(target, caster);
}
    
    


/*
  _moonfire.c
  
  Innate spell for Clerics with the Moon Domain.
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
    
    set_spell_name("moonfire");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("moon");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate moonfire on TARGET");
    set_damage_desc("Divine damage to target on successful ranged touch attack");
    set_description("Clerics with the moon domain learn, by the grace of their deity, how to attack their opponents with the light of the moon. This spell uses a ranged touch attack to do divine damage. This spell requires one Divine Grace point to use. This spell does 25% more damage against were-creatures.");
    set_target_required(1);
    set_immunities( ({ "divine" }) );
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
        tell_object(caster, "You don't have the Divine Grace to cast Moonfire!");
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
        tell_object(caster, "You fire a fire bolt at " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^WHITE%^BOLD%^A bolt of pure moonlight shoots out of your finger and squarely strikes " + target->QCN + " with a splash of pale radiance!%^RESET%^");
    tell_room(place, "%^WHITE%^BOLD%^" + caster->QCN + " shoots a bolt of pure moonlight out of " + caster->QP + " finger, striking " + target->QCN + " with a splash of pale radiance.%^RESET%^", ({ caster })); 
    
    //Does 25% more damage against were creatures
    if(target->is_were())
        sdamage = (sdamage * 125) / 100;
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "divine");
    spell_kill(target, caster);
}
    
    


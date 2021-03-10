/*
  _acid_dart.c
  
  Innate spell for Clerics with the Earth Domain.
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
    
    set_spell_name("acid dart");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("earth");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast innate acid dart on TARGET");
    set_damage_desc("Acid damage to target on successful ranged touch attack");
    set_description("Clerics with the earth domain learn, by the grace of their deity, how to attack their opponents with a dart of acid. This spell uses a ranged touch attack to do acid damage. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    set_immunities( ({ "acid" }) );
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
        tell_object(caster, "You don't have the Divine Grace to cast Acid Dart!");
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
        tell_object(caster, "You fire a dart of acid at " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^GREEN%^BOLD%^A dart of acid shoots out of your finger and squarely strikes " + target->QCN + " with a spray of droplets!%^RESET%^");
    tell_room(place, "%^GREEN%^BOLD%^" + caster->QCN + " shoots a dart of acid out of " + caster->QP + " finger, striking " + target->QCN + " with a spray of droplets.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "acid");
    spell_kill(target, caster);
}
    
    


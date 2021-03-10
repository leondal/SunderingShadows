/*
  _touch_of_madness.c
  
  Innate spell for Clerics with the Madness Domain.
  Touch attack for hit.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("touch of madness");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("madness");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast innate touch of madness on TARGET");
    set_damage_desc("Confusion on failed save with touch attack, mental damage on successful save");
    set_description("Clerics with the madness domain learn, by the grace of their deity, how to cause madness with a mere touch. This spell uses a touch attack to cause confusion on a failed will save. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    set_save("will");
    set_immunities( ({ "mental" }) );
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
        tell_object(caster, "You don't have the Divine Grace to cast Touch of Madness!");
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
        tell_object(caster, "You try to grasp " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^MAGENTA%^BOLD%^A swirl of magical energy forms on your hand, and you grasp " + target->QCN + " with the grip of madnessRESET%^");
    tell_room(place, "%^RED%^BOLD%^" + caster->QCN + " extends " + caster->QP + " hand, grasping " + target->QCN + " a swirl of madness.%^RESET%^", ({ caster })); 
    
    if(!do_save(target, clevel))
        "/std/effect/status/confused"->apply_effect(target,clevel/5+1,caster);
    else
        target->cause_typed_damage(target, target->return_target_limb(), sdamage, "mental");
    
    spell_kill(target, caster);
}
    
    


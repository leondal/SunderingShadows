/*
  _dazing_touch.c
  
  Innate spell for Clerics with the Charm Domain.
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
    
    set_spell_name("dazing touch");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("charm");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast innate dazing touch on TARGET");
    set_damage_desc("1/2 Untyped Damage and daze for one round");
    set_description("Clerics with the charm domain learn, by the grace of their deity, how to paralyze their opponents with a mere touch. This spell uses a touch attack to do untyped damage and paralyze on a failed will save. This spell requires one Divine Grace point to use.");
    set_save("will");
    set_target_required(1);
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
        tell_object(caster, "You don't have the Divine Grace to cast Dazing Touch!");
        return;
    }
}

void spell_effect(int prof)
{
    int roll;
       
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1 && !caster->query_property("spectral_hand"))
    {
        tell_object(caster, "You reach your hand out to " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^WHITE%^BOLD%^You reach out and grasp " + target->QCN + " with a glowing hand!%^RESET%^");
    tell_room(place, "%^WHITE%^BOLD%^" + caster->QCN + " reaches out with " + caster->QP + " hand, grasping " + target->QCN + " with a flash of magical energy.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage / 2, "untyped");

    if(do_save(target) || target->query_property("no paralyze"))
    {
        tell_object(caster, "%^YELLOW%^You fail to paralyze your opponent.%^RESET%^");
        tell_object(target, "%^YELLOW%^You resist the paralysis!%^RESET%^");
    }
    else
    {
        target->set_paralyzed(3, "%^WHITE%^BOLD%^You are dazed and can't seem to move!%^RESET%^");
        tell_object(caster, "%^YELLOW%^Your opponent seems to freeze, dazed by your touch!%^RESET%^");
        tell_object(target, "%^YELLOW%^You are dazed by the touch!%^RESET%^");
    }
    
    spell_kill(target, caster);
}
    
    


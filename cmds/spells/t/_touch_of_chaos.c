/*
  _touch_of_chaos.c
  
  Innate spell for Clerics with the Chaos Domain.
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
    
    set_spell_name("touch of chaos");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("chaos");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast innate touch of chaos on TARGET");
    set_damage_desc("Disadvantage on attack rolls for three rounds");
    set_description("Clerics with the chaos domain learn, by the grace of their deity, how to disrupt their opponent's attacks with a mere touch. This spell uses a touch attack to cause an opponent to roll twice on an attack roll, taking the lowest result. This spell requires one Divine Grace point to use.");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while reaching with "+caster->QP+" hand.%^RESET%^";
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
        tell_object(caster, "You don't have the Divine Grace to cast Touch of Chaos!");
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
        tell_object(caster, "You reach your hand out to grasp " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^ORANGE%^You reach out and grasp " + target->QCN + " with a glowing hand, cursing them with chaos!%^RESET%^");
    tell_room(place, "%^ORANGE%^" + caster->QCN + " reaches out with " + caster->QP + " hand, grasping " + target->QCN + " with a swirl of chaotic energy!%^RESET%^", ({ caster })); 
    
    target->set_property("touch of chaos", 1);
    
    spell_kill(target, caster);
    
    call_out("dest_effect", 3);
}

dest_effect()
{
    target && tell_object(target, "You feel the curse of chaos fade from you.");
    caster && tell_object(caster, "Your touch of chaos fades from your opponent.");
    target && target->remove_property("touch of chaos");
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
    
    


/*
  _touch_of_law.c
  
  Innate spell for Clerics with the Law Domain.
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
    
    set_spell_name("touch of law");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("law");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast innate touch of law on TARGET");
    set_damage_desc("All d20 rolls for attacks and saving throws become 11 for 3 rounds");
    set_description("Clerics with the law domain learn, by the grace of their deity, how to impose the balance of law with a mere touch. This spell causes all natural d20 rolls for attacks and saving throws to result in an 11 for the duration. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while reaching with "+caster->QP+" hand.%^RESET%^";
}

int preSpell()
{
    
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Touch of Law!");
        return 0;
    }
    
    return 1;
}

void spell_effect(int prof)
{
    int roll;
       
    spell_successful();
    
    if(!objectp(target) || place != environment(target))
        return;
    
    if(member_array(target, caster->query_attackers()) >= 0)
    {
        roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
        if(roll < 1 && !caster->query_property("spectral_hand"))
        {
            tell_object(caster, "You try to grasp " + target->QCN + " but miss!");
            return;
        }
    }
    
    tell_object(caster, "%^ORANGE%^You reach out and grasp " + target->QCN + " with a glowing hand, imbuing them with the balance of law!%^RESET%^");
    tell_room(place, "%^ORANGE%^" + caster->QCN + " reaches out with " + caster->QP + " hand, grasping " + target->QCN + " with a swirl of balancing energy!%^RESET%^", ({ caster })); 
    
    target->set_property("touch of law", 1);
    
    spell_kill(target, caster);
    
    call_out("dest_effect", 3);
}

dest_effect()
{
    target && tell_object(target, "You feel the touch of law fade from you.");
    target && target->remove_property("touch of law");
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
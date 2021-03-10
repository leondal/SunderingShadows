/*
  _bleeding_touch.c
  
  Innate spell for Clerics with the Udeath Domain.
   attack for hit.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int num;

void create()
{
    ::create();
    
    set_spell_name("bleeding touch");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("undeath");
    set_spell_sphere("necromancy");
    set_syntax("cast innate bleeding touch on TARGET");
    set_damage_desc("Negative energy damage to target on successful touch attack plus bleed");
    set_description("Clerics with the undeath domain learn, by the grace of their deity, how to cause ceaseless bleeding with their touch. This spell uses a touch attack to do negative energy damage to the target with additional negative energy every round. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    evil_spell(1);
    set_immunities( ({ "negative energy" }) );
}

string query_cast_string()
{
    return "%^BLACK%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while reaching out with "+caster->QP+" hand.%^RESET%^";
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
        tell_object(caster, "You don't have the Divine Grace to cast Fire Bolt!");
        return 0;
    }
    
    return 1;
}

void spell_effect(int prof)
{
    int roll;
    
    ::spell_effect();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1 && !caster->query_property("spectral_hand"))
    {
        tell_object(caster, "You try to reach out and touch " + target->QCN + " but miss!");
        return;
    }
    
    spell_successful();
    
    tell_object(caster, "%^BLACK%^BOLD%^Your hand becomes enveloped in darkness as you grab " + target->QCN + " with your wounding grasp!%^RESET%^");
    tell_room(place, "%^BLACK%^BOLD%^" + caster->QCN + " reaches out with " + caster->QP + " hand, striking " + target->QCN + " with a wounding grasp!%^RESET%^", ({ caster })); 
    if(!target->is_undead())
        tell_object(target, "%^RED%^BOLD%^You begin to bleed profusely as negative energy works its way into the wound!%^RESET%^");
    target->cause_typed_damage(target, target->return_target_limb(), sdamage / 2, "negative energy");
    spell_kill(target, caster);
    
    num = clevel / 8 + 1;
    
    call_out("touch_bleed", ROUND_LENGTH - 1);
}

void touch_bleed()
{
    int dam;
    object room;
    
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    
    if(target->is_undead())
    {
        dest_effect();
        return;
    }
    
    dam = sdamage / 5;
    room = environment(target);
    
    tell_object(target, "%^RED%^BOLD%^You continue to bleed profusely from the wound!%^RESET%^");
    tell_room(room, "%^RED%^BOLD%^" + target->QCN + " continues to bleed profusely from the wound!%^RESET%^");
    
    target->cause_typed_damage(target, target->return_target_limb(), dam, "negative energy");
    
    if(num-- <= 0)
    {
        dest_effect();
        return;
    }
    
    call_out("touch_bleed", ROUND_LENGTH - 1);
}

void dest_effect()
{
    if(find_call_out("touch_bleed") >= 0)
        remove_call_out("touch_bleed");
    
    ::dest_effect();
    
    if(objectp(this_object()))
        this_object()->remove();
}
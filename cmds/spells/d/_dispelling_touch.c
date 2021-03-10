/*
  _dispelling_touch.c
  
  Innate spell for Clerics with the Magic Domain.
  Touch attack for hit.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int checkDispel(object ob);

void create()
{
    ::create();
    
    set_spell_name("dispelling touch");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("magic");
    set_spell_sphere("abjuration");
    set_syntax("cast innate dispelling touch on TARGET");
    set_damage_desc("1/2 Untyped Damage plus attempt to dispel one spell on a successful touch attack");
    set_description("Clerics with the magic domain learn, by the grace of their deity, how to dispel magic from their opponents with a mere touch. This spell uses a ranged touch attack to perform a dispel attempt. This spell requires one Divine Grace point to use.");
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
        tell_object(caster, "You don't have the Divine Grace to cast Dispelling Touch!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
    object *spells;
       
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1 && !caster->query_property("spectral_hand"))
    {
        tell_object(caster, "You attempt to grasp reach out and touch " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^Your hand begins to glow as you grab " + target->QCN + " with a flash of arcane energy!%^RESET%^");
    tell_room(place, "%^CYAN%^BOLD%^" + caster->QCN + " extends " + caster->QP + " glowing hand, grasping " + target->QCN + " with arcane energy.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage / 2, "untyped");
    spell_kill(target, caster);

    spells = target->query_property("spelled");
    
    if(!sizeof(spells))
    {
        tell_object(caster, "There was nothing to dispel.");
        return;
    }
    
    shuffle(spells);
    
    if(!checkDispel(spells[0]))
    {
        tell_object(caster, "You fail to dispel anything.");
        return;
    }
    
    tell_object(caster, "%^BOLD%^CYAN%^You feel magic crumble beneath your grasp.%^RESET%^");
    
    target->remove_property_value("spelled", ({ spells[0] }));
    spells[0]->dest_effect();  
}

int checkDispel(object ob)
{
    return "/std/magic/dispel"->checkDispel(ob, clevel, caster);
}
    
    


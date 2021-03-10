/*
  _blinding_flash.c
  
  Innate spell for Clerics with the Sun Domain.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("blinding flash");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("sun");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate blinding flash");
    set_damage_desc("Blindness on attackers on failed fortitude save");
    set_description("Clerics with the sun domain learn, by the grace of their deity, how to cause a flash of light to blind their enemies. Enemies who are at or below the cleric's level make a fortitude save or suffer blindness for 1d4 rounds. This spell requires one Divine Grace point to use.");
    set_save("fort");
    splash_spell(2);
    set_immunities( ({  }) );
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while pointing with "+caster->QP+" finger.%^RESET%^";
}

int preSpell()
{
    if(!sizeof(caster->query_attackers()))
    {
        tell_object(caster, "You're not under attack.");
        dest_effect();
        return 0;
    }
    
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Blinding Flash!");
        return 0;
    }
    
    return 1;
}

void spell_effect(int prof)
{
    int roll;
    object *attackers;
       
    spell_successful();
    
    attackers = caster->target_selector();
    
    tell_object(caster, "%^BOLD%^You snap your finger, and a bright flash illuminates the area around you!%^RESET%^");
    tell_room(place, "%^BOLD%^" + caster->QCN + " snaps " + caster->QP + " finger, illuminating the area with a bright flash!%^RESET%^", ({ caster }));
    
    foreach(object ob in attackers)
    {
        if(clevel < ob->query_level())
            continue;
        
        if(do_save(ob, 0))
            continue;
        
        tell_room(place, "%^BOLD%^" + ob->QCN + " is blinded by the flash!%^RESET%^", ({ ob }));
        tell_object(ob, "%^BOLD%^You are blinded by the flash!%^RESET%^");
        ob->set_temporary_blinded(roll_dice(1, 4));
    }
}
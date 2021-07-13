/*
  _adapt_body.c
  
  Psion gains +10 to all elemental resistances
  
  -- Tlaloc -- 4.3.20
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void effect(int direction)
{
    if(direction > 0)
    {
        caster->set_property("castspellresist",1);
        caster->set_property("poison immunity", 1);
    }
    else
    {
        caster->remove_property("castspellresist");
        caster->remove_property("poison immunity");
    }
    
    caster->set_resistance("fire", 10 * direction);
    caster->set_resistance("acid", 10 * direction);
    caster->set_resistance("electricity", 10 * direction);
    caster->set_resistance("cold", 10 * direction);
    caster->set_resistance("sonic", 10 * direction);

    return;
}

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("adapt body");
    set_spell_level( ([ "psion" : 5, "psywarrior" : 5 ]) );
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS adapt body");
    set_damage_desc("+10 to fire, cold, electricity, acid, and sonic resistance.");
    set_description("With this power, the psion uses psychometabolism and adjusts their body to better survive in harsh environments. This power increases all elemental resistances.");
    set_helpful_spell(1);
}

int preSpell()
{
   if(caster->query_property("castspellresist") || caster->query_property("fiery body"))
   {
      tell_object(caster,"You already have protection of this nature!");
      return 0;
   }
   
   return 1;
}


string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    string myname, yourname;
    int mylevel;
    
    myname = caster->QCN;
  
    tell_object(caster, "%^CYAN%^BOLD%^You focus internally with your psychic power, adjusting your body to better survive.");
    tell_room(place, "%^BOLD%^CYAN%^" + sprintf("%s focuses on adapting %s body!", myname, caster->query_possessive()), ({ caster }));

    effect(1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    tell_object(caster, "%^MAGENTA%^BOLD%^The shadows subsuming your body seem to dissapate.");
    effect(-1);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}

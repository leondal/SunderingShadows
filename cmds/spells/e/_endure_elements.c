/*
  _endure_elementa.c
  
  Gains +10 Fire and Cold resistance
  
  -- Tlaloc -- 7.11.20
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
    }
    else
    {
        caster->remove_property("castspellresist");
    }
    
    caster->set_resistance("fire", 10 * direction);
    caster->set_resistance("cold", 10 * direction);

    return;
}

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("endure elements");
    set_spell_level( ([ "ranger" : 1, "druid" : 1, "cleric" : 1, "paladin" : 1, "mage" : 1, "oracle" : 1, ]) );
    set_mystery( ({ "waves", "winter" }) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS endure elements");
    set_damage_desc("+10 to fire and cold resistance.");
    set_description("With this spell, the caster gains enhanced protection from extreme heat and cold.");
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
    return "%^GREEN%^" + sprintf("%s concentrates on %s protective powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    string myname, yourname;
    int mylevel;
    
    myname = caster->QCN;
  
    tell_object(caster, "%^GREEN%^You place a hand upon yourself, enhancing your body with enhanced protection against heat and cold.");
    tell_room(place, "%^GREEN%^" + sprintf("%s focuses on enhancing %s body with enhanced protection!", myname, caster->query_possessive()), ({ caster }));

    effect(1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    tell_object(caster, "%^GREEN%^Your protection from the elements seems to dissapate.");
    effect(-1);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}

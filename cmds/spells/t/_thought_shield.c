/*
  _thought_shield.c
  
  Grants 13 resistance to mental damage.
  Taken from PF SRD.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void effect(int direction)
{
    /*
    if(direction > 0)
        //caster->set_property("castspellresistance", 1);
    else
        //caster->remove_property("castspellresistance");
    */
    caster->set_resistance("mental", 13 * direction);
}

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("thought shield");
    set_spell_level( ([ "psion" : 2, "psywarrior" : 2 ]) );
    set_spell_sphere("telepathy");
    set_bonus_type("circumstance");
    set_syntax("cast CLASS thought shield");
    set_damage_desc("+13 to mental resistance");
    set_description("The caster fortifies her mind from hostile intrusions, gaining 13 resistance to mental damage.");
    set_helpful_spell(1);
}

int preSpell()
{
    /*
   if(caster->query_property("castspellresist") || caster->query_property("fiery body"))
   {
      tell_object(caster,"You already have protection of this nature!");
      return 0;
   }
   */
   
   return 1;
}

string query_cast_string()
{
    return "%^CYAN%^" + sprintf("%s concentrates on %s protective powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    string myname, yourname;
    int mylevel;
    
    myname = caster->QCN;
  
    tell_object(caster, "%^CYAN%^You place a hand upon yourself, enhancing your mind with protection from mental attacks.");
    tell_room(place, "%^CYAN%^" + sprintf("%s focuses on enhancing %s mind with protection against mental attacks!", myname, caster->query_possessive()), ({ caster }));

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
    
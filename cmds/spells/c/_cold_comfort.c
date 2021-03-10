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
    
    caster->set_resistance("fire", 20 * direction);
    caster->set_resistance("cold", 20 * direction);

    return;
}

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("cold comfort");
    set_spell_level( ([ "warlock" : 1 ]) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS cold comfort");
    set_damage_desc("+20 to fire and cold resistance.");
    set_description("With this invocation, the warlock gains enhanced protection from extreme heat and cold.");
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
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
    return "%^BLACK%^BOLD%^" + sprintf("%s calls upon %s ancient and forbidden knowledge", caster->QCN, caster->query_possessive());
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
    tell_object(caster, "%^CYAN%^Your protection from the elements seems to dissapate.");
    effect(-1);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}

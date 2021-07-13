/*
  _detect_intruders.c
  
  Basically a reskinned commune with nature.
  
  -- Tlaloc -- 03.30.20
*/

#include <std.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("detect intruders");
    set_spell_level(([ "psion" : 2, "psywarrior" : 2 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS detect intruders");
    set_description("With this ability, the psion can detect nearby psychic energy, allowing them to pinpoint living entities in the vicinity");
    set_helpful_spell(1);
}

string query_cast_string()
{
     tell_object(caster,"%^CYAN%^You place a hand on your forehead and concentrate deeply, attempting to sense nearby intruders.%^RESET%^");
     tell_room(place, sprintf("%s places a hand on %s forehead and concentrates deeply.",caster->QCN, caster->QP), ({ caster }));
    return "display";
}

void spell_effect(int prof)
{
    string myloc, *exploded, mydir;
    object *peo, *targets;
    int i, j;

    if(!objectp(place))
    {
      dest_effect();
      return;
    }

    myloc = base_name(place);
    exploded = explode(myloc,"/");
    if(!sizeof(exploded))
    {
      dest_effect();
      return;
    }
    exploded -= ({ exploded[(sizeof(exploded))-1] });
    if(!sizeof(exploded))
    {
      dest_effect();
      return;
    }
    mydir = "/"+implode(exploded,"/")+"/";

    spell_successful();

    if(place->is_temple() || place->is_dock())
    {
      tell_object(caster,"Something unsettling seems to dull your senses here.");
      dest_effect();
      return;
    }
    
    peo = ({});
    peo += users();
    if(member_array(caster,peo) != -1) peo -= ({ caster });
    
    if(!sizeof(peo))
    {
      tell_object(caster,"You can sense no intruders nearby!");
      dest_effect();
      return;
    }
    
    targets = ({});
    for(i=0;i<sizeof(peo);i++)
    {
      if(!objectp(peo[i])) continue;
      if(!objectp(environment(peo[i]))) continue;
      if(peo[i]->query_true_invis()) continue;
      if(strsrch(base_name(environment(peo[i])),mydir) != -1) targets += ({ peo[i] });
    }
    targets = filter_array(targets,"is_non_immortal",FILTERS_D);
    
    if(!sizeof(targets))
    {
      tell_object(caster,"You can sense no intruders nearby!");
      dest_effect();
      return;
    }
    tell_object(caster,"You can sense the presence of interlopers nearby...\n");
    
    for(i=0;i<sizeof(targets);i++)
    {
      tell_object(caster,""+targets[i]->getWholeDescriptivePhrase()+" is near " +(environment(targets[i]))->query_short()+".\n");
    }
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

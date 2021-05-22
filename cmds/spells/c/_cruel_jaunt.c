#include <std.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();

    set_author("yves");
    set_spell_name("cruel jaunt");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 6, "mage" : 6, "magus" : 6, "paladin" : 4 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS cruel jaunt");
    set_description("You can sense the stench of cowards suffering from a fear effect that are within the same area as you and then teleport directly to a chosen coward.");
    set_helpful_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    evil_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^RED%^You place a finger to your temple and concentrate deeply, attempting to sense the stench of fear nearby.%^RESET%^");
    tell_room(place, "%^RED%^"+caster->QCN+" places a finger to "+caster->QP+" temple and concentrates deeply.%^RESET%^", ({ caster }));
    return "display";
}

void spell_effect(int prof)
{
    string myloc, *exploded, mydir;
    object *targets, *peo, jaunter;
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
      tell_object(caster,"You sense no stench of fear nearby!");
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
    targets = filter_array(targets, (:$1->is_feared():));

    if(!sizeof(targets))
    {
      tell_object(caster,"You sense no stench of fear nearby!");
      dest_effect();
      return;
    }
    tell_object(caster,"%^RED%^You sense the stench of fear nearby...%^RESET%^\n");

    for(i=0;i<sizeof(targets);i++)
    {
      tell_object(caster,i+": "+targets[i]->getWholeDescriptivePhrase()+" is cowering near " +(environment(targets[i]))->query_short()+".\n");
    }
    tell_object(caster,"%^RED%^Which coward would you like to pursue?%^RESET%^");
    jaunter = new("/d/magic/obj/jaunter.c");
    jaunter->move(caster);
    jaunter->set_targs(targets);
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

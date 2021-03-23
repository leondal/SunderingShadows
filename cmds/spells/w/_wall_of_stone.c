// Web

#include <spell.h>
#include <magic.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("wall of stone");
    set_spell_level(([ "mage" : 5, "monk" : 9, "oracle" : 6, "magus" : 5, "druid" : 5, "cleric" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_domains( ({ "earth" }) );
    set_mystery("stone");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS wall of stone on <exit>");
    set_description("This command will cause a wall of rubble to appear on an exit, preventing travel in that direction "
        "until all of the rubble has been cleared away.  The more powerful the caster, the larger the rubble "
        "wall that must be removed.");
    set_spell_sphere("conjuration_summoning");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
    set_components(([
      "mage" : ([ "granite dust":1, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^YELLOW%^"+caster->QCN+" suddenly yells in rage and stomps "+caster->QP+" foot hard on the ground!";
}

int preSpell()
{
    if(place->query_property("wall of stone"))
    {
        tell_object(caster,"%^BOLD%^There is already a wall of stone here, you can't create another!");
        return 0;
    }
    if(!arg || (member_array(arg,(string*)place->query_exits()) == -1))
    {
        tell_object(caster,"%^BOLD%^You need to specify an exit from this room.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    tell_object(caster,"%^ORANGE%^You can feel the earth begin to tremble as it heeds your command!");
    tell_room(place,"%^ORANGE%^The earth begins to tremble as it heeds "+caster->QCN+"'s command!",caster);

    spell_successful();
    call_out("block_exit",4,arg);
}


void block_exit(string exit)
{
    tell_room(place,"%^BOLD%^A small mountain of stone rushes up from the ground, blocking the "+arg+"!");
    place->collapse_exit(arg,(clevel+5)*20);
    place->set_property("wall of stone",1);
}

void dest_effect()
{
    if(objectp(place)) { place->remove_property("wall of stone"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

    return;
}

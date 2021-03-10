#include <std.h>
#include <magic.h>
inherit "/cmds/spells/a/_angelic_aspect";

string ashort;

void effect(int direction)
{
    if(direction>0)
    {
        caster->set_property("flying",1);
        caster->set_property("angelic_aspect",1);
    }
    else
    {
        caster->set_property("flying", -1);
        caster->remove_property("angelic_aspect");
    }

    caster->set_property("endurance",(clevel/10)*direction);
    caster->set_resistance("cold",5*direction);
    caster->set_resistance("acid",5*direction);
    return;
}

void create()
{
    ::create();
    set_spell_name("lesser angelic aspect");
    set_spell_level(([ "cleric": 2, "paladin": 2, "mage": 2, "magus" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS lesser angelic aspect");
    set_damage_desc("levitating, 5 DR to Acid and Cold");
    set_description("You take on an aspect of an angelic being, including some of its physical characteristics. This spell won't last outside of combat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

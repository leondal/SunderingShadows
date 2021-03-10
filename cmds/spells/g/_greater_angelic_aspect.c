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

    caster->add_ac_bonus(4*direction);
    caster->set_property("endurance",(clevel/10)*direction);
    caster->set_resistance("cold",50*direction);
    caster->set_resistance("acid",50*direction);
    caster->set_resistance("fire",10*direction);
    caster->set_resistance("electricity",10*direction);
    caster->set_property("no death",direction);
    return;
}

void create(){
    ::create();
    set_spell_name("greater angelic aspect");
    set_spell_level(([ "cleric": 8, "paladin": 4, "mage": 8, ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS greater angelic aspect");
    set_damage_desc("levitating, AC4, 50 DR to Acid and Cold, 10 DR to Fire, Electricity, deathward");
    set_description("You take on an aspect of an angelic being, including some of its physical characteristics. This spell won't last outside of combat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

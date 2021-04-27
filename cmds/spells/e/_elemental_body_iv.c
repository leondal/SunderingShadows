#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit "/cmds/spells/e/_elemental_body_i";

void effect(int direction)
{
    /*
    if(direction>0)
        caster->set_property("augmentation");
    else
        caster->remove_property("augmentation");
    */

    switch(query_element())
    {
        case "air":
            caster->add_stat_bonus("strength",4*direction);
            caster->add_stat_bonus("dexterity",6*direction);
            caster->add_ac_bonus(4*direction);
            break;
        case "fire":
            caster->add_stat_bonus("constitution",4*direction);
            caster->add_stat_bonus("dexterity",6*direction);
            caster->add_ac_bonus(4*direction);
            break;
        case "earth":
            caster->add_stat_bonus("strength",8*direction);
            caster->add_stat_bonus("dexterity",-2*direction);
            caster->add_stat_bonus("constitution",4*direction);
            caster->add_ac_bonus(6*direction);
            break;
        case "water":
            caster->add_stat_bonus("strength",4*direction);
            caster->add_stat_bonus("constitution",8*direction);
            caster->add_stat_bonus("dexterity",-2*direction);
            caster->add_ac_bonus(6*direction);
            break;
    }
    return;
}
void create()
{
    ::create();
    set_spell_name("elemental body iv");
    set_spell_level(([ "mage" : 7,"oracle": 7, "innate" : 7 ]));
    set_mystery("elemental");
    set_description("When you cast this spell, you infuse yourself with the power of the element. Infusions give the next effects as follows:

  fire:  +6 dexterity,    +4 constitution, +4 armor class
  air:   +6 dexterity,    +4 strength,     +4 armor class
  earth: +8 strength,     +4 constitution, -2 dexterity,   +6 armor class
  water: +8 constitution, +4 strength,     -2 dexterity,   +6 armor class

Stone Lords may only gain the augmentation of earth.

Clerics of elemental domain can change into a specific domain form only.");
    set_syntax("cast CLASS "+query_spell_name()+" on fire|air|earth|water");
}

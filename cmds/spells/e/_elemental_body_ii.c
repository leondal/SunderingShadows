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
            caster->add_stat_bonus("dexterity",4*direction);
            caster->add_ac_bonus(3*direction);
            break;
        case "fire":
            caster->add_stat_bonus("dexterity",4*direction);
            caster->add_ac_bonus(3*direction);
            break;
        case "earth":
            caster->add_stat_bonus("strength",4*direction);
            caster->add_ac_bonus(5*direction);
            break;
        case "water":
            caster->add_stat_bonus("constitution",4*direction);
            caster->add_ac_bonus(5*direction);
            break;
    }
    return;
}
void create()
{
    ::create();
    set_spell_name("elemental body ii");
    set_spell_level(([ "mage" : 5, "oracle" : 5 ]));
    set_mystery("elemental");
    set_description("When you cast this spell, you infuse yourself with the power of the element. Infusions give the next effects as follows:

  fire:  +4 dexterity,     +3 armor class
  air:   +4 dexterity,     +3 armor class
  earth: +4 strength,      +5 armor class
  water: +4 constitution,  +5 armor class");
    set_syntax("cast CLASS "+query_spell_name()+" on fire|air|earth|water");
}

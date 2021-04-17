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
            caster->add_stat_bonus("strength",2*direction);
            caster->add_stat_bonus("dexterity",4*direction);
            caster->add_ac_bonus(4*direction);
            break;
        case "fire":
            caster->add_stat_bonus("constitution",2*direction);
            caster->add_stat_bonus("dexterity",4*direction);
            caster->add_ac_bonus(4*direction);
            break;
        case "earth":
            caster->add_stat_bonus("strength",6*direction);
            caster->add_stat_bonus("dexterity",-2*direction);
            caster->add_stat_bonus("constitution",2*direction);
            caster->add_ac_bonus(6*direction);
            break;
        case "water":
            caster->add_stat_bonus("strength",2*direction);
            caster->add_stat_bonus("constitution",6*direction);
            caster->add_stat_bonus("dexterity",-2*direction);
            caster->add_ac_bonus(6*direction);
            break;
    }
    return;
}
void create()
{
    ::create();
    set_spell_name("elemental body iii");
    set_spell_level(([ "mage" : 6, "oracle" : 6 ]));
    set_mystery("elemental");
    set_description("When you cast this spell, you infuse yourself with the power of the element. Infusions give the next effects as follows:

  fire:  +4 dexterity,    +2 constitution, +4 armor class
  air:   +4 dexterity,    +2 strength,     +4 armor class
  earth: +6 strength,     +2 constitution, -2 dexterity,   +6 armor class
  water: +6 constitution, +2 strength,     -2 dexterity,   +6 armor class");
    set_syntax("cast CLASS "+query_spell_name()+" on fire|air|earth|water");
}

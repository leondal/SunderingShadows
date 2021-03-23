#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit "/cmds/spells/d/_dispel_magic";

void create() {
    ::create();
    set_spell_name("greater dispel magic");
    set_spell_level(([ "mage" : 7, "bard" : 5, "cleric" : 6, "druid" : 6, "inquisitor":6, "magus" : 6 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS greater dispel magic [on TARGET]");
    set_description("Greater Dispel Magic is a significantly more powerful version of the 3rd level spell, Dispel Magic. When cast it will attempt to destroy any spell enchantments, magical summonings, and anything conjured.  The chances of each dispelling depends on both the dispeller's casting level and the power level of the spellcaster that created whatever is being dispelled, whether it be an enchantment, summoning, or conjuration.");
    set_arg_needed();
}

int dispel_power()
{
    return clevel / 6 + 1;
}

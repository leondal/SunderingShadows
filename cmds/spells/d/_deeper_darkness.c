// darkness
#include <spell.h>
#include <magic.h>
#include <std.h>

inherit "/cmds/spells/d/_darkness";

void create() {
    ::create();
    set_spell_name("deeper darkness");
    set_spell_level(([ "mage" : 3, "assassin": 3, "inquisitor" : 3, "cleric" : 3, "oracle" : 3 ]));
    set_mystery(({"darkness","shadow"}));
    set_domains(({ "darkness" }));
    set_syntax("cast CLASS deeper darkness");
    set_description("This will create a globe of darkness, which will overcome normal light sources. This globe is more powerful than with the darkness spell. You may only possess one globe of darkness at a time.");
    set_verbal_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
}

int set_darkness_power()
{
    return 3;
}

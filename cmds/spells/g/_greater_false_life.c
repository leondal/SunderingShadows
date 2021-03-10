#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit "/cmds/spells/f/_false_life";

int bonus;

void create() {
    ::create();
    set_spell_name("greater false life");
    set_spell_level(([ "mage" : 4, "magus" : 4 ]));
    set_damage_desc("clevel*2 hitpoints bonus");
    set_syntax("cast CLASS greater false life [on TARGET]");
}

int query_fl_power()
{
    return 2;
}

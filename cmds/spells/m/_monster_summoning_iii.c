#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_i.c";

create() {
    ::create();
    set_spell_name("monster summoning iii");
    set_spell_level(([ "mage" : 3, "bard" : 3, "cleric":3,"paladin":3 ]));
    set_syntax("cast CLASS monster summoning iii");
}

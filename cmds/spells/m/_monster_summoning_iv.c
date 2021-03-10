#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_i.c";

create() {
    ::create();
    set_spell_name("monster summoning iv");
    set_spell_level(([ "mage" : 4, "bard" : 4 , "cleric" : 4, "paladin" : 4]));
    set_syntax("cast CLASS monster summoning iv");
}

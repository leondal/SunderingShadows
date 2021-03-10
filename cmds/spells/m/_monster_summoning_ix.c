#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_i.c";

create() {
    ::create();
    set_spell_name("monster summoning ix");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_syntax("cast CLASS monster summoning ix");
}

#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/m/_monster_summoning_i.c";

create() {
    ::create();
    set_spell_name("monster summoning vii");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_syntax("cast CLASS monster summoning vii");
}

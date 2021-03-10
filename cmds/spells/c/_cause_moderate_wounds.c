#include <std.h>

inherit "/cmds/spells/h/_harm";

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("cause moderate wounds");
    set_spell_level(([ "cleric" : 2,"paladin":2, "inquisitor" : 2 ]));
    set_affixed_spell_level(2);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause moderate wounds on TARGET");
    set_description("When cast, this prayer will draw some energy from the target, inflicting him with a wound.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

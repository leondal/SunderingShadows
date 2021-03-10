#include <std.h>

inherit "/cmds/spells/h/_harm";

void create() {
    ::create();
    set_author("pator");
    set_spell_name("cause light wounds");
    set_spell_level(([ "cleric" : 1,"paladin":1, "inquisitor" : 1 ]));
    set_affixed_spell_level(1);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause light wounds on TARGET");
    set_description("When cast it makes a nice little wound on the target monster. It is almost as powerful in inflicting "
"wounds as the cure light wounds is in healing wounds.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

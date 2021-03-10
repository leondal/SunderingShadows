#include <std.h>

inherit "/cmds/spells/h/_harm";

void create() {
    ::create();
    set_spell_name("cause serious wounds");
    set_spell_level(([ "cleric" : 3, "paladin" : 3,"inquisitor":3 ]));
    set_affixed_spell_level(3);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause serious wounds on TARGET");
    set_description("When cast it makes a serious wound on the target monster. It is almost as powerful in inflicting "
                    "wounds as the cure serious wounds is in healing them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

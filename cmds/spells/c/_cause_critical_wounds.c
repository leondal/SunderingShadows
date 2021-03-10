#include <std.h>

inherit "/cmds/spells/h/_harm";

void create() {
    ::create();
    set_author("pator");
    set_spell_name("cause critical wounds");
    set_spell_level(([ "cleric" : 4, "paladin" : 4,"inquisitor":4 ]));
    set_affixed_spell_level(4);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS cause critical wounds on TARGET");
    set_description("This spell siphons off life energy from the target. The effect of this spell is aimed at one limb of "
"the opponents body. During battle, this spell is very powerful and requires no special skills or abilities.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_immunities( ({ "spell_immunity"}) );
}

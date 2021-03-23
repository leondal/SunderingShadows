#include <std.h>

inherit "/cmds/spells/h/_heal";

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("cure moderate wounds");
    set_spell_level(([ "cleric" : 2, "bard" : 2, "ranger" : 3, "druid" : 3, "paladin" : 3, "inquisitor" : 2 ]));
    set_affixed_spell_level(2);
    set_domains(({}));
    set_mystery(({}));
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure moderate wounds on TARGET");
    set_description("Praying to their diety for a small miracle, the priest can attempt to heal a bit of damage to the "
"target.  As the caster's strength grows, she will find her prayer will heal more.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
	set_helpful_spell(1);
}

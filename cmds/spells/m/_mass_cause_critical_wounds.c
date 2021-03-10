#include <priest.h>
inherit "/cmds/spells/m/_mass_harm";

void create() {
    ::create();
    set_spell_name("mass cause critical wounds");
    set_spell_level(([ "cleric" : 8,"inquisitor":5 ]));
    set_affixed_spell_level(5);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS mass cause critical wounds [on TARGET]");
    set_description("This is a stronger version of the priest spell, cause critical wounds.  When cast on a target, it "
"will do damage to them if they are living, and it will heal them if they are undead.  If no target is given, it will hit "
"all of the caster's current attackers.");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
}

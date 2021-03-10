#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("binding blast");
    set_spell_level(([ "warlock" : 4 ]));
    set_syntax("<blasttype binding>");
    set_description("An eldritch blast with this essence applied will ensnare the target/s "
"with magical energy, temporarily stunning them.\nSee also: <help blasttype>.");
    set_save("will");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("utterdark blast");
    set_spell_level(([ "warlock" : 4 ]));
    set_syntax("<blasttype utterdark>");
    set_description("An eldritch blast with this essence applied will be empowered for "
"greater damage to its target/s.\nSee also: <help blasttype>.");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}

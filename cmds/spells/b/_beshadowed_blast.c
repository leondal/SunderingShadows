#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("beshadowed blast");
    set_spell_level(([ "warlock" : 3 ]));
    set_syntax("<blasttype beshadowed>");
    set_description("An eldritch blast with this essence applied will cloud the target/s' "
"vision, temporarily blinding them.\nSee also: <help blasttype>.");
    set_save("fort");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
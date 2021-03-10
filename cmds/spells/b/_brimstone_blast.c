#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("brimstone blast");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("<blasttype brimstone>");
    set_description("An eldritch blast with this essence applied will cause the target/s to "
"catch fire, burning for further damage over several rounds. Subsequent eldritch blasts will "
"not stack this effect, but will refresh its duration. This essence will also change the "
"base type of the blast to fire.\nSee also: <help blasttype>.");
    set_save("reflex");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
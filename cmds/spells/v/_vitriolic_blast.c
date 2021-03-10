#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("vitriolic blast");
    set_spell_level(([ "warlock" : 3 ]));
    set_syntax("<blasttype vitriolic>");
    set_description("An eldritch blast with this essence applied will bypass all magic resistance "
"and AC of the target, unerringly finding its mark. It will cause acidic residue to burn the "
"target/s for further damage over several rounds. Subsequent eldritch blasts will not stack this "
"effect, but will refresh its duration. This essence will also change the base type of the blast "
"to acid.\nSee also: <help blasttype>.");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
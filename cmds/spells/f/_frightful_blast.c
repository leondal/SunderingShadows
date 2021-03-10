#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("frightful blast");
    set_spell_level(([ "warlock" : 1 ]));
    set_syntax("<blasttype frightful>");
    set_description("An eldritch blast with this essence applied will cause the target/s to "
"become shaken for 1min. This will inflict a penalty to their attack rolls, saving throws, and "
"skill checks. Subsequent eldritch blasts will not stack this effect, but will refresh its "
"duration.\nSee also: <help blasttype>.");
    set_save("will");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("glacial blast");
    set_spell_level(([ "warlock" : 1 ]));
    set_syntax("<blasttype glacial>");
    set_description("An eldritch blast with this essence applied will cause the target/s to "
"become chilled for 10min, which will inflict a penalty to their dexterity. Subsequent eldritch "
"blasts will not stack this effect, but will refresh its duration. This essence will also change "
"the base type of the blast to cold.\nSee also: <help blasttype>.");
    set_save("fort");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
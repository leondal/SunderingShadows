#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("lifedrinker blast");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("<blasttype lifedrinker>");
    set_description("An eldritch blast with this essence applied will leech part of the damage "
"done to heal the warlock. Multiple-target blast shapes will still leech the same amount of "
"vampiric healing as a single-targetted blast. This essence will also change the base type of "
"the blast to negative energy.\nSee also: <help blasttype>.");
}

int preSpell() {
    tell_object(caster,"You can't cast this as an invocation! See <help blasttype> for syntax.");
    return 0;
}
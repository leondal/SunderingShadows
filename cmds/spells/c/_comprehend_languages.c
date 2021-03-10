#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit "/cmds/spells/t/_tongues";

#include <langs.h>

int theProf;

create() {
    ::create();
    set_spell_name("comprehend languages");
    set_spell_level(([ "classless" : 3 ]));
    set_spell_sphere("divination");
    set_spell_domain("knowledge");
    set_syntax("cast CLASS comprehend languages on TARGET");
    set_description("This blessing allows the priest to call on the vast knowledge of their god.  The blessing comes in "
"the form of a greater understanding of languages.");
    set_verbal_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

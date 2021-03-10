//

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("feather fall");
	set_spell_level(1);
	set_spell_type("wizard");
	set_spell_sphere("alteration");
}

spell_effect() {
	::spell_effect();
}

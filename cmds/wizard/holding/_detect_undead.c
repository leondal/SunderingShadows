//

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("detect undead");
	set_spell_level(1);
	set_spell_type("wizard");
	set_spell_sphere("necromancy");
	set_components(([
   "gloworm" : 1,
	]));
}

spell_effect() {
	::spell_effect();
}

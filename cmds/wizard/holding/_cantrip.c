// Sample Spell for Spell System II
// Thorn -- 950518

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("cantrip");
	set_spell_level(2);
	set_spell_type("wizard");
	set_spell_sphere("invocation_evocation");
	set_components( ([
	"stardust" : 2,
	"terror" : 1,
	]) );
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You have just cast a cantrip.  Bubbles fly all over the place!");
	tell_room(environment(CASTER), "You see big bubbles emerge from out of nowhere!", CASTER);
	CASTER->set_casting(0);
}

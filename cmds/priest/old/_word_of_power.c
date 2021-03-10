#include <std.h>
#include <spell.h>

inherit SPELL;
create() {
	::create();
	set_spell_name("word_of_power");
	set_spell_level(6);
	set_spell_type("priest");
	set_spell_sphere("summoning");
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You reach your hands out and wave them in strange motions.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" reaches out and waves his arms in strange motions.", CASTER);
	if(CASTER->query_internal_encumbrance() > CASTER->query_level() * 25){
		tell_object(CASTER,"Nothing happens");
		return;
	}
	tell_object(CASTER, "You are magically transported somewhere.");
	CASTER->move_player("/d/shadow/room/city/church");
	CASTER->set_casting(0);
}

int help(string str){
write(
@HELP
Level  : 6th Level
Sphere : Summoning
Syntax : <cast word of power>

Word of power will teleport you back to the church in Shadow.

HELP
);
return 1;
}

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("cure_serious_wounds");
	set_spell_level(4);
	set_spell_type("priest");
	set_spell_sphere("healing");
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You reach out and touch "+TARGET->query_name()+" and you heal "+TARGET->query_objective()+" a little.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" reaches out to "+TARGET->query_cap_name()+" and heals "+TARGET->query_objective()+" a little bit.", CASTER);
	TARGET->add_hp(random(8)+random(8)+3);
	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
Level  : 1st Level
Sphere : Healing
Syntax : <cast cure serious wounds on [char]>

Cure serious wounds will heal someone a larger amount then
cure light wounds.

HELP
);
}


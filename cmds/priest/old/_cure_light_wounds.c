#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("cure_light_wounds");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("healing");
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You reach out and touch "+TARGET->query_name()+" and you heal "+TARGET->query_objective()+" a little.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" reaches out to "+TARGET->query_cap_name()+" and heals "+TARGET->query_objective()+" a little bit.", CASTER);
	TARGET->add_hp(random(8)+2);
	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
Level  : 1
Sphere : Elemental
Syntax : <cast cure light wounds on [char]>

Cure light wounds will heal someone a small amount.

HELP
);
return 1;
}

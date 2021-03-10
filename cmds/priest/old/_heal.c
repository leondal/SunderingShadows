#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("heal");
	set_spell_level(6);
	set_spell_type("priest");
	set_spell_sphere("healing");
	set_target_required(1);
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You reach out and touch "+TARGET->query_name()+" and you heal "+TARGET->query_objective()+", completely.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" reaches out to "+TARGET->query_cap_name()+" and heals "+TARGET->query_objective()+" a little bit.", CASTER);
	TARGET->add_hp(-(TARGET->query_hp() - TARGET->query_max_hp()));
	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
Level  : 6th Level
Sphere : Healing
Syntax : <cast heal on [char]>

Cast Heal will heal someone completely, wounds and desease.

HELP
);
}


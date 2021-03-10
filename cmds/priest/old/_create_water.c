#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("create_water");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("elemental");
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You create a puddle of clean water.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" makes a  pool of water.", CASTER);
	CASTER->set_casting(0);
	new("/cmds/priest/obj/water")->move(environment(TP));
}
int help(string str){
write(
@HELP
Level  : 1st level      
Sphere : Elemental
Syntax : <cast create water>

This spell creates a pool of drinkable water.
You can drink from the pool, to quench your thirst.
HELP
);
}

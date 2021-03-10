#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("create_food");
	set_spell_level(3);
	set_spell_type("priest");
	set_spell_sphere("creation");
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You create a pile of edible food.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" makes a  pool of water.", CASTER);
	CASTER->set_casting(0);
	new("/cmds/priest/obj/food")->move(environment(TP));
}
int help(string str){
write(
@HELP
Level  : 3rd level      
Sphere : Creation
Syntax : <cast create food>

This spell creates a pile of edible food.
You can eat some if you wish. The higher
level the caster, the more food is created.

HELP
);
}

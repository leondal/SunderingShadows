#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("detect_poison");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("divination");
	set_non_living_ok(1);
}

spell_effect() {
    int poison;
	::spell_effect();
	if(living(TARGET))
	    poison = 0;
	else poison = (int)TARGET->query_poisoning();
	if(poison)
	   tell_object(CASTER, "You detect poison on "+TARGET->query_cap_name()+".");
	else
	   tell_object(CASTER, "You detect no poison on "+TARGET->query_cap_name()+".");

	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
Level  : 1st level
Sphere : Divination
Syntax : <cast detect poison on [object || char]>

Will detect if object or char is poisonous in nature.

HELP
);
}


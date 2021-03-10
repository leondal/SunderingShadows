#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("detect_magic");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("divination");
	set_non_living_ok(1);
}

spell_effect() {
    int magic;
	::spell_effect();
	if(living(TARGET))
	    if((TARGET->query_class() == "fighter") ||
		(TARGET->query_class() == "thief"))
			magic = 0;
	    else magic = 1;
	else magic = (int)TARGET->query_property("enchantment");
	if(magic)
	   tell_object(CASTER, "You detect magic in "+TARGET->query_cap_name()+".");
	else
	   tell_object(CASTER, "You detect no magic in "+TARGET->query_cap_name()+".");

	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
Level  : 1st level
Sphere : Divination
Syntax : <cast detect magic on [object || char]>

Will detect if object or char is evil in nature.
Will not detect alignment. Merely whether or not 
it is evil.

HELP
);
}


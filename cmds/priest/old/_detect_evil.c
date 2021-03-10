#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("detect_evil");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("all");
}

spell_effect() {
    int align;
	::spell_effect();
	if(TARGET->query_property("enchantment"))
	   tell_object(CASTER, "You detect magic in "+TARGET->query_cap_name()+".");
	else
	   tell_object(CASTER, "You detect no magic in "+TARGET->query_cap_name()+".");

	CASTER->set_casting(0);
}
int help(string str){
write(
@HELP
LEvel  : 1st Level
Sphere : All
Syntax : <cast detect evil on [char || obj]>

Detect evil will detect the presence of evil in players or objects.
HELP
);
}


#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("remove_paralysis");
	set_spell_level(3);
	set_spell_type("priest");
	set_spell_sphere("protection");
	set_target_required(1);
}

spell_effect() {
    int duration,level;
	::spell_effect();
	level = CASTER->query_level();
	tell_object(CASTER, "You cast remove paralysis on "+TARGET->query_cap_name());
	tell_room(environment(CASTER), CASTER->query_cap_name()+" casts a spell on "+TARGET->query_cap_name()+".", CASTER);
	if(!TARGET->query_paralyzed()) 
		return;
	TARGET->set_paralyzed(0);
}
int help(string str){
write(
@HELP
Level  : 3rd level
Sphere : Protection
Syntax : <cast remove paralysis on [target]>

This spell will remove any paralysis from it's
target. Negates hold spells, and paralysis spells.

HELP
);
}


#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("neutralize_poison");
	set_spell_level(4);
	set_spell_type("priest");
	set_spell_sphere("healing");
	set_target_required(1);
}

spell_effect() {
    int duration,level;
	::spell_effect();
	level = CASTER->query_level();
	tell_object(CASTER, "You cast neutralize poison on "+TARGET->query_cap_name());
	tell_room(environment(CASTER), CASTER->query_cap_name()+" casts a spell on "+TARGET->query_cap_name()+".", CASTER);
	TARGET->add_poisoning(-TARGET->query_poisoning());

}
int help(string str){
write(
@HELP
Level  : 3rd level
Sphere : Protection
Syntax : <cast neutralize poison on [target]>

This spell will neutralize any poison from it's
target. 

HELP
);
}


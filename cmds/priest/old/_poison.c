#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("poison");
	set_spell_level(4);
	set_spell_type("priest");
	set_spell_sphere("healing");
	set_target_required(1);
//	set_non_living_ok(1);
}

spell_effect() {
    int duration,level;
	::spell_effect();
	level = CASTER->query_level();
	tell_object(CASTER, "You cast poison on "+TARGET->query_cap_name());
	tell_room(environment(CASTER), CASTER->query_cap_name()+" casts a spell on "+TARGET->query_cap_name()+".", CASTER);
	if(TARGET->is_weapon())
		TARGET->add_poisoning(10);
	if("/daemon/saving_d"->get_saving_throw(TARGET,"spells"))
		TARGET->add_poisoning(1000);
}
int help(string str){
write(
@HELP
Level  : 4th level
Sphere : Healing
Syntax : <cast neutralize poison on [OB | living]>

This spell will poison the target. If the target is 
a weapon, it will make it a poison weapon. If the target 
is living, it will poison them badly. 

HELP
);
}


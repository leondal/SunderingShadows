#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("hold_person");
	set_spell_level(2);
	set_spell_type("priest");
	set_spell_sphere("charm");
	set_target_required(1);
}

spell_effect() {
    int duration,level;
	::spell_effect();
	level = CASTER->query_level();
	if(level > 20) level = 20;
	duration = level * 20;
	tell_object(CASTER, "You cast hold person on "+TARGET->query_cap_name());
	tell_room(environment(CASTER), CASTER->query_cap_name()+" casts a spell on "+TARGET->query_cap_name()+".", CASTER);
	if((TARGET->query_body_type() != "human") && 
	   (TARGET->query_body_type() != 0)) 
		return;
	if("/daemon/saving_d"->get_saving_throw(TARGET,"spells"))
		TARGET->set_paralyzed(duration,"You are magically held still. You can't move a muscle in your body.");
}
int help(string str){
write(
@HELP
Level  : 2nd level
Sphere : Charm
Syntax : <cast hold person on [target]>

This will magically hold any humanoid creature.
It will hold for longer, as your levels increase.
They will be able to hear, but not look or fight.

HELP
);
}


#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("raise_dead");
	set_spell_level(5);
	set_spell_type("priest");
	set_spell_sphere("necromanic");
	set_target_required(1);
}

spell_effect() {
	::spell_effect();
	tell_object(CASTER, "You cast raise dead on "+TARGET->query_cap_name());
	tell_room(environment(CASTER), CASTER->query_cap_name()+" casts a spell on "+TARGET->query_cap_name()+".", CASTER);
    if(!TARGET->query_ghost()) {
      return;
    }
    TARGET->revive();
    TARGET->set_hp(1);
    TARGET->set_heart_beat(1);
    TARGET->set_heal_rate(2);
}

int help(string str){
write(
@HELP
Level  : 5th level
Sphere : Necromanic
Syntax : <cast raise dead on [target]>

This spell will revive a dead player.

HELP
);
}


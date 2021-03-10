// Blindness

#include <std.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object caster, target;

create() {
	::create();
	set_spell_name("blindness");
	set_spell_level(2);
	set_spell_type("wizard");
	set_spell_sphere("illusion_phantasm");
	set_verbal_comp();
	set_target_required(1);
}

spell_effect() {
	::spell_effect();
	caster=CASTER;
	target=TARGET;
	if(TO->do_saving_throw(target)) {
		tell_object(caster, "Your spell fails.");
		return;
	}
	tell_object(target, "%^BOLD%^%^BLACK%^Your world suddenly "+
	    "goes all gray!!");
	target->add_sight_bonus(-10000);
	target->set_attack_bonus(-4);
	call_out("dest_effect", 26*ROUND_LENGTH);
}

void dest_effect() {
	if(!target) return;
	tell_object(target, "You squint your eyes as light once "+
	    "again reaches your eyes.");
	target->add_sight_bonus(10000);
	target->set_attack_bonus(4);
}
	

help() {
	write(
@HELP
Blindness (Illusion/Phantasm)
-----------------------------
Usage: cast blindness on <target>
	
	The "blind" spell causes the target to lose all sight for the 
duration of the spell, seeing only gray.  Because of this, the target
won't be able to attack or defend as well as he/she could with sight.

HELP
	);
}

// Shocking Grasp

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>


inherit SPELL;

object grasp;

create() {
	::create();
	set_spell_name("shocking grasp");
	set_spell_level(1);
	set_spell_type("wizard");
	set_spell_sphere("alteration");
    set_verbal_comp();
    set_somatic_comp();
}

spell_effect() {
	object caster;
	::spell_effect();
	caster = CASTER;
	target = TARGET;
	grasp=new(SPELL_OBJ_DIR+"s_grasp");
	grasp->move(caster);
	caster->command("wield graspx");
}

void dest_effect() {
	object caster;
	
	caster = CASTER;
	if(!grasp) return;
	grasp->dispel();
	TO->remove();
}

help() {
	write(
@HELP
Shocking Grasp (Level 1)
--------------------------
Usage: cast shocking grasp
Once cast: shock <target>
           dismiss shocking grasp

Range: Touch
Components: V, S
Duration: Until discharged or dismissed
Casting time: 1
Area of effect: Creature touched
Saving Throw: None

	This spell creates a strong electrical charge in the body of the
caster that is discharged for 1d8 pts of damage by a successful melee
grasp by the caster.

HELP
	);
}

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("magical_vestment");
	set_spell_level(3);
	set_spell_type("priest");
	set_spell_sphere("protection");
}

spell_effect() {
    int armorclass,new_ac,level,duration;
	::spell_effect();
	level = TP->query_level();
	if(level > 20) level = 20;
	level -= 6;
	new_ac = 5 - (level/3);
	duration = (4 + level) * 10;
	armorclass = CASTER->query_ac();
	tell_object(CASTER, "You cast a magical vestment on yourself");
	CASTER->set_ac(new_ac);
	call_out("wear_off",duration,armorclass);
	CASTER->set_casting(1);
	
}
void wear_off(int old_ac){
	CASTER->set_ac(old_ac);
	write("You feel the magical vestment wear off.");
}
int help(string str){
write(
@HELP
Level  : 3rd level
Sphere : Protection
Syntax : <cast magical vestment>

Will create a magical armor around the caster,
which will increase in ac and duration as the 
caster gains levels. It can only be cast upon 
ones self.

HELP
);
}


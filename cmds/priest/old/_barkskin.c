#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("barkskin");
	set_spell_level(2);
	set_spell_type("priest");
	set_spell_sphere("plant");
}

spell_effect() {
    int armorclass,new_ac,level,duration;
	::spell_effect();
	level = TP->query_level();
	if(level > 20) level = 20;
	new_ac = 6 - (level/4);
	duration = (4 + level) * 10;
	armorclass = TARGET->query_ac();
	tell_object(CASTER, "You cast a barkskin on "+TARGET->query_cap_name());
	TARGET->set_ac(new_ac);
	call_out("wear_off",duration,armorclass);
	CASTER->set_casting(1);
	
}
void wear_off(int old_ac){
	TARGET->set_ac(old_ac);
	write("You feel the barkskin wear off.");
}
int help(string str){
write(
@HELP
Level  : 2nd level
Sphere : Plant
Syntax : <cast barkskin on [char]>

Will create a magical armor around the caster,
which will increase in ac and duration as the 
caster gains levels. It can be cast upon anyone,
including ones self.

HELP
);
}


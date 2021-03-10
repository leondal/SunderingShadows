#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("shillelagh");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("plant");
}

spell_effect() {
    object ob,ob2;
    int level;
	::spell_effect();
	level = CASTER->query_level();
	if(level > 20) level = 20;
	if(!ob2 = present("staff",CASTER)){
	    tell_object(CASTER, "You don't have a staff!");
	    return;
	}
	ob = new("/cmds/priest/obj/shillelagh");
	ob->set_duration(40+(level * 10));
	ob->set_owner(CASTER);
	ob->set_object(file_name(ob2));
	ob->move((CASTER));
        CASTER->force_me("wield staff in right hand and left hand.");
	CASTER->set_casting(4);
	
}
int help(string str){
write(
@HELP
Level  : 1st level
Sphere : Plant
Syntax : <cast shillelagh>

Shillelagh will take the casters staff, and make
it into a magically enhanced staff. The enhancements
will only last a short time, then the staff will
revert back to it's old self. Only the caster
of the spell, can wield the staff. 

HELP
);
}

